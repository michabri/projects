#include "Controller.h"
#include <iostream>

//=======================================================================================
Controller::Controller(const int& num_of_players)
	: m_numOfPlayers(num_of_players), m_socket(nullptr)
{
	try {
		m_file_levels.open("level_list.txt", std::ios::in);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}
//=======================================================================================
Controller::Controller(Socket* socket, bool isHost)
	: m_numOfPlayers(2), m_usingSocket(true), m_socket(socket), m_isHost(isHost)
{
	m_board.usingSocket(isHost);
	try {
		m_file_levels.open("level_list.txt", std::ios::in);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
}
//=======================================================================================
void Controller::run(sf::RenderWindow& window) 
{
	setMusic(false);
	m_caption.setNumOfPlayers(m_numOfPlayers);
	setLevel();
	sf::Sprite bg_sprite = sf::Sprite(*Resources::instance().getBackground(background::BACKGROUND_FADE));
	sf::Event event;
	const sf::Time timerLimit = sf::seconds(0.1f);
	sf::Clock clock;
	float deltaTime = 0.0f;
	bool played_countdown = false;


	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		m_world->Step(m_timeStep, m_velocityIterations, m_positionIterations);
		
		if (!checkLivesPlayers())
		{
			m_caption.printMessege("You lost the game sucker", window, false);
			setMusic(true);
			return;
		}
		if (checkTimeOver(window))
		{
			setMusic(true);
			return;
		}
		window.clear(sf::Color::White);
		window.draw(bg_sprite);
		for(auto& player : m_players)
			player->draw(window);
		m_board.draw(window);
		m_caption.draw(window);
		window.display();

		if (!eventHandler(event, window))
		{
			setMusic(true);
			return;
		}
		movementManger(deltaTime);

		if (checkCollisions(window, event))
		{
			m_new_level = true;
			setLevel();
		}
		if (m_end_game)
		{
			m_caption.printMessege("Congratulation you passed the game", window, false);
			setMusic(true);
			return;
		}
	}
}
//=======================================================================================
bool Controller::eventHandler(sf::Event& event, sf::RenderWindow& window) 
{
	while (window.pollEvent(event)) 
	{
		if (event.type == sf::Event::Closed)
			window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			if (!pauseMenu(window))
				return false;
		
		if (event.type == sf::Event::KeyReleased)
			for (auto& player : m_players)
				player->SetStandingImage(0, 1.0f);
	
	}
	return true;
}
//=======================================================================================
bool Controller::checkLivesPlayers()
{
	for (int i = 0; i < m_players.size(); i++)
	{
		for (auto player = m_players.begin(); player < m_players.end(); player++)
		{
			if (m_caption.getLives((*player)->getId()) <= 0)
			{
				m_world->DestroyBody(&(*player)->getBody());
				m_players.erase(player);
				break;
			}
		}
	}
	if (m_players.size() > 0)
		return true;
	Resources::instance().playSound(sounds::GAME_OVER);
	return false;
}
//=======================================================================================
bool Controller::checkTimeOver(sf::RenderWindow& window)
{
	if (m_caption.getTime() <= 0) // means game over
	{
		if (!m_ball_hit)
		{
			for (auto& player : m_players)
				m_caption.updateLives(-1, player->getId());
		}
		else
		{
			Resources::instance().playSound(sounds::PLAYER_HIT_SOUND);
			m_ball_hit = false;
		}
		m_caption.printMessege("NOOB! , you lost :( shame on you", window, false);

		if (!checkLivesPlayers())
			return true;
		
		setLevel();
	}
	return false;
}
//=======================================================================================
bool Controller::checkCollisions(sf::RenderWindow& window, sf::Event event)
{
	if (m_board.checkAllBallsCleared())
	{
		m_caption.printMessege("YAY! , you won :) KOL HA KAVOD!", window, false);
		return true;
	}

	m_board.updateObjects(m_world.get());
	m_board.checkAllBallsToTheRightAndDownGone(m_world.get());
	
	if (m_board.checkSplit(m_cl, m_world.get(), m_onlineData))
		for (auto& player : m_players)
			player->ballHit();

	int value;
	int index_player;
	if (m_board.checkHitGift(m_cl, m_world.get(), value, index_player))
	{
		switch (value)
		{
		case gift::NORMAL_WEAPON:
		case gift::HOOK_WEAPON:
		case gift::LASER_WEAPON:
			for (auto& player : m_players)
				if (player->getId() == index_player)
					player->setCurrWeapon(value);
			break;
		case gift::SHIELD_GIFT:
			for (auto& player : m_players)
				if (player->getId() == index_player)
					player->setShield();
			break;
		case gift::GREEN_CLOCK: m_caption.updateTime(10, false); break;
		case gift::RED_CLOCK: m_caption.updateTime(-10, false); break;
		case gift::LIFE: 
			for (auto& player : m_players)
				if (player->getId() == index_player)
					m_caption.updateLives(1, index_player);
			break;
		}
	}

	if (m_cl.isBallHitPlayer(index_player))
	{
		for (auto& player : m_players)
			if (player->getId() == index_player)
				m_caption.updateLives(-1, index_player);

		
		m_ball_hit = true;
		m_caption.resetTime();
	}

	for (auto& player : m_players)
		player->handlePowers(m_cl);

	return false;
}
//=======================================================================================
void Controller::movementManger(float deltaTime)
{
	if (!m_usingSocket)
	{
		for (auto& player : m_players)
			player->move(m_cl, getInput(player->getId()), deltaTime);
	}
	else
	{
		if (m_players.size() > 1)
		{
			m_players[!m_isHost]->move(m_cl, getInput(m_players[!m_isHost]->getId()), deltaTime);
			m_players[m_isHost]->move(m_cl, getOnlineInput(), deltaTime);
		}
		else if(m_players[0]->getId() == !m_isHost)
			m_players[0]->move(m_cl, getInput(m_players[0]->getId()), deltaTime);
		else
			m_players[0]->move(m_cl, getOnlineInput(), deltaTime);
	}
	
}
//=======================================================================================
std::pair<sf::Vector2f, bool> Controller::getInput(int playerId)
{
	std::pair<sf::Vector2f, bool> pair(directionInput(playerId), shootingInput(playerId));
	if (m_usingSocket)
	{
		m_onlineData.direction = pair.first;
		m_onlineData.shoot = pair.second;
		m_socket->send(m_onlineData);
	}
		
	return pair;
}
//=======================================================================================
bool Controller::shootingInput(int playerId)
{
	if (playerId == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			return true;
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			return true;
		}
	}
	return false;
}
//=======================================================================================
sf::Vector2f Controller::directionInput(int playerId)
{
	if (playerId == 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			return sf::Vector2f(1, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			return sf::Vector2f(-1, 0);
		else
			return sf::Vector2f(0, 0);
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			return sf::Vector2f(1, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			return sf::Vector2f(-1, 0);
		else
			return sf::Vector2f(0, 0);
	}
}

//=======================================================================================
bool Controller::pauseMenu(sf::RenderWindow& window)
{
	sf::Clock clock;
	clock.restart();

	while (window.isOpen())
	{
		Resources::instance().drawPauseScreen(window);
		window.display();
		if (auto event = sf::Event{}; window.waitEvent(event))
		{
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				m_caption.updateTime(clock.getElapsedTime().asSeconds(), false);
				m_board.restartTimers();
				return true;
			}

			switch (event.type)
			{

			case sf::Event::MouseButtonReleased:
				auto location = window.mapPixelToCoords(
					{ event.mouseButton.x, event.mouseButton.y });

				if (event.mouseButton.button == sf::Mouse::Button::Left)
				{
					auto buttonClicked = m_caption.handleClick(location);
					
					if (buttonClicked == pauseButtons::HOME)
					{
						return false;
					}

					else if (buttonClicked == pauseButtons::RESTART)
					{
						if(!m_usingSocket)
							setLevel();

						return true;
					}
					else if (buttonClicked == pauseButtons::MUSIC)
					{
						Resources::instance().setMusic(music_song::BACKGROUND_SONG, false);
					}
				}
			}
		}
	}
	m_caption.updateTime(clock.getElapsedTime().asSeconds(), false);
	return true;
}
//=======================================================================================
void Controller::setLevel()
{
	m_players.clear();
	m_board.clearBoard();
	
	m_world = std::make_unique<b2World>(m_garvity);
	m_world->SetContactListener(&m_cl);
	
	for (int i = 0; i < m_numOfPlayers; i++)
	{
		sf::Vector2f loc;
		switch (i)
		{
		case 0: loc = sf::Vector2f(1400, WINDOW_HEIGHT - 1.2 * STATIC_OBJECT_SIZE_PIXEL); break;
		case 1: loc = sf::Vector2f(1100, WINDOW_HEIGHT - 1.2 * STATIC_OBJECT_SIZE_PIXEL); break;
		}
		if (m_caption.isAlive(i))
			m_players.push_back(std::make_unique<Player>(Player(loc, m_world.get(), i)));
	}
	if (m_new_level)
	{
		try 
		{
			if (getline(m_file_levels, m_curr_level))
				m_board.setBoard(m_curr_level, m_world.get());
			else
			{
				m_end_game = true;
				return;
			}
		}
		catch (const std::exception& e) 
		{
			std::cerr << e.what() << "\n";
		}
		m_new_level = false;
		m_caption.updateLevel();
	}
	else
	{
		m_board.setBoard(m_curr_level, m_world.get());
	}
	switch (m_caption.getLevel())
	{
	case 1: m_caption.updateTime(90, true); break;
	case 2: m_caption.updateTime(90, true); break;
	case 3: m_caption.updateTime(90, true); break;
	}
	m_cl.restartFlags();
}
//=======================================================================================
std::pair<sf::Vector2f, bool> Controller::getOnlineInput()
{
	m_socket->receive(m_onlineData);
	std::pair<sf::Vector2f, bool> pair(m_onlineData.direction, m_onlineData.shoot);
	return pair;
}
//=======================================================================================
void Controller::setMusic(const bool& returtn_menu)
{
	Resources::instance().setMusic(music_song::MENU_SONG, returtn_menu);
	Resources::instance().setMusic(music_song::BACKGROUND_SONG, returtn_menu);
}
#include "Caption.h"

//=======================================================================================
Caption::Caption() 
	: m_level(0), m_stageTime(0)
{
	setText(m_stageTimeText, 2);
	setText(m_levelText, 3);
}
//=======================================================================================
void Caption::setText(sf::Text& text, int i)
{
	text.setFont(*Resources::instance().getFont());
	text.setCharacterSize(40);
	int loc;
	switch (i)
	{
	case 0: loc = 50; break;
	case 1: loc = 1175; break;
	case 2: loc = 600; break;
	case 3: loc = 900; break;
	}
	text.setPosition(loc, WINDOW_HEIGHT - STATIC_OBJECT_SIZE_PIXEL/1.5f);
	text.setColor(sf::Color::Green);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(3);
}
//=======================================================================================
Caption::~Caption() 
{}
//=======================================================================================
void Caption::updateTime(float time, const bool& new_level)
{
	if (new_level)
		m_stageTime = time;
	else
		m_stageTime += time;
	m_stageTime -= m_Timer.getElapsedTime().asSeconds();

	m_stageTimeText.setString("Time left: " + std::to_string((int)m_stageTime));

	m_Timer.restart();
}

//=======================================================================================
void Caption::updateLevel()
{
	m_level++;
	m_levelText.setString("Level:" + std::to_string(m_level));
	m_Timer.restart();

}
//=======================================================================================
int Caption::getLevel() const
{
	return m_level;
}

//=======================================================================================
float Caption::getTime() const
{
	return m_stageTime;
}
//=======================================================================================
void Caption::resetTime()
{
	m_stageTime = 0;
}
//=======================================================================================
void Caption::draw(sf::RenderWindow& window)
{
	updateTime(0, false);
	window.draw(m_levelText);
	window.draw(m_stageTimeText);
	for(int i = 0; i < m_lives_rect.size(); i++)
		for (int j = 0; j < m_lives_rect[i].size(); j++)
			window.draw(m_lives_rect[i][j]);
	for (int i = 0; i < m_liveText.size(); i++)
		window.draw(m_liveText[i]);
		
}

//=======================================================================================
void Caption::printMessege(const sf::String text, sf::RenderWindow& window, const bool& time_based)
{
	//set the message settings
	auto message = sf::Text(text, *Resources::instance().getFont());
	message.Bold;
	message.setOutlineColor(sf::Color(12, 36, 97, 255));
	message.setOutlineThickness(3);
	message.setCharacterSize(70);
	message.setColor(sf::Color(29, 209, 161, 255));
	message.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2.5));
	message.setOrigin(sf::Vector2f(message.getGlobalBounds().width / 2, message.getGlobalBounds().height / 2));

	auto message_press_space = sf::Text("Press Enter to continue", *Resources::instance().getFont());
	message_press_space.Bold;
	message_press_space.setOutlineColor(sf::Color(12, 36, 97, 255));
	message_press_space.setOutlineThickness(3);
	message_press_space.setCharacterSize(70);
	message_press_space.setColor(sf::Color(29, 209, 161, 255));
	message_press_space.setPosition(sf::Vector2f(1000, 600));
	message_press_space.setOrigin(sf::Vector2f(message.getGlobalBounds().width / 2, message.getGlobalBounds().height / 2));

	// print the background
	sf::Sprite bg;
	window.draw(message);
	window.draw(message_press_space);
	window.display();
	auto event = sf::Event{};

	if (!time_based)
	{
		while (window.waitEvent(event)) // wait until Space is pressed
		{
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Enter)
				|| (event.type == sf::Event::Closed))
			{
				return;
			}
		}
	}
	else
	{
		sf::Clock wait;
		wait.restart();
		while (wait.getElapsedTime().asSeconds() != 1.f);
		return;
	}
}
//=======================================================================================
void Caption::updateLives(const int& lives, const int& player)
{
	if (m_lives[player] + lives < m_lives_rect[player].size())
	{
		m_lives[player] += lives;
		if (m_lives[player] <= 0)
			m_alive[player] = false;
	
		if (lives > 0)
			m_lives_rect[player][m_lives[player] - 1].setTexture(Resources::instance().getTexture(gameObjects::LIFE_GO), true);
		else if (lives < 0)
			m_lives_rect[player][m_lives[player]].setTexture(Resources::instance().getTexture(gameObjects::X_LIFE_GO), true);
	}
}
//=======================================================================================
int Caption::handleClick(const sf::Vector2f location)
{
	if (clicked(HOME, location)) return HOME;
	else if (clicked(MUSIC, location)) return MUSIC;
	else if (clicked(RESTART, location)) return RESTART;

	return -1; // return any number so if no button is clicked - nothing happens
}

//=======================================================================================
// return if the button is clicked
bool Caption::clicked(int index, const sf::Vector2f location)
{
	if (Resources::instance().getPauseButtons(index)->getGlobalBounds().contains(location))
		return true;

	return false;
}
//=======================================================================================
void Caption::setNumOfPlayers(const int& num_of_players)
{
	m_lives.resize(num_of_players);
	m_lives_rect.resize(num_of_players);
	m_liveText.resize(num_of_players);
	m_alive.resize(num_of_players);
	

	for (int i = 0; i < num_of_players; i++)
		m_lives[i] = 3;
	for (int i = 0; i < num_of_players; i++)
	{
		m_lives_rect[i].resize(8);
		setLivesRect(i);
	}
	for (int i = 0; i < num_of_players; i++)
		m_alive[i] = true;
	for (int i = 0; i < num_of_players; i++)
	{
		setText(m_liveText[i], i);
		switch (i)
		{
		case 0: m_liveText[i].setString("Batman"); break;
		case 1: m_liveText[i].setString("Robin"); break;
		}
	}
	
}
//=======================================================================================
int Caption::getLives(const int& id) const
{
	return m_lives[id];
}
//=======================================================================================
bool Caption::isAlive(const int& id) const
{
	return m_alive[id];
}
//=======================================================================================
void Caption::setLivesRect(const int& index)
{
	int start_lives = 3;
	for (int i = 0; i < m_lives_rect[index].size(); i++)
	{
		m_lives_rect[index][i].setSize(sf::Vector2f(30.f, 30.f));
		m_lives_rect[index][i].setOutlineThickness(3);
		m_lives_rect[index][i].setOutlineColor(sf::Color(sf::Color::Black));
		m_lives_rect[index][i].setPosition(sf::Vector2f(200 + 33*i + 1100*index, WINDOW_HEIGHT - STATIC_OBJECT_SIZE_PIXEL / 2.f));
		if (start_lives > 0)
		{
			m_lives_rect[index][i].setTexture(Resources::instance().getTexture(gameObjects::LIFE_GO));
			start_lives--;
		}
		else
			m_lives_rect[index][i].setTexture(Resources::instance().getTexture(gameObjects::X_LIFE_GO));
	}
}
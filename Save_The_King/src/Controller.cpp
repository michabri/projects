#include "Controller.h"

//-------------------------------------------------------------------------
Controller::Controller(sf::RenderWindow& window)
:m_window(&window), m_curr_character(0), m_new_level(true), m_end_game(false), m_is_playing(true)
{
    m_file_levels.open("level_list.txt", std::ios::in);
    setPauseMessage();
}
//-------------------------------------------------------------------------
void Controller::run()
{    
    setLevel();

    sf::Clock clock;  
    sf::Time delta_time, delta_time_gnomes;
    const sf::Time elapsed_time = sf::seconds(0.1f);
    sf::Sprite background = Singleton::instance().getMenuSprite(CONTROLLER_PIC);;
    bool is_time_over = false;

    while (m_window->isOpen()) 
    { 
        sf::Event event;
        while(m_window->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                m_window->close();
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
            {
                if (!m_is_playing)
                {
                    m_is_playing = true;
                    return;
                }
                m_is_playing = false;
                m_pause_message.setString("press space to resume the game!\npress escape to return to menu");
            }
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space) && !m_is_playing)
            {
                if(m_end_game)
                    m_window->close();

                if (m_new_level)
                    setLevel();
                
                if (is_time_over)
                {
                    setLevel();
                    is_time_over = false;
                }

                if(!m_is_playing && !m_end_game)
                    m_is_playing = true;
            }
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::P))
                nextCharacter();
            
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up) ||
                (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down) || 
                (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right) || 
                (event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
                    m_characters[m_curr_character]->setDirection(event.key.code);
         }

        if (m_info_line.getTime() <= 0)
        {
            m_pause_message.setString("The time is over! :(\npress space to restart the level");
            m_is_playing = false;
            m_new_level = false;
            is_time_over = true;
        }

        if (m_is_playing)
        {
            if (clock.getElapsedTime() >= elapsed_time)
                clock.restart();

            if (event.type == sf::Event::KeyPressed)
                manageCollision(delta_time, clock);

            for (int i = 0; i < m_characters.size() - CHARACTERS; i++)
            {
                int temp = m_curr_character;
                m_curr_character = i + CHARACTERS;
                manageCollision(delta_time_gnomes, m_clock_gnomes[i]);
                m_curr_character = temp;
            }
            setRectPlayer();
            m_window->clear();
            m_window->draw(background);
            m_board.draw(*m_window);
            m_info_line.draw(*m_window);
            m_window->draw(m_rect_player);
            m_window->display();
        }
        else
        {
            m_window->clear();
            m_window->draw(background);
            m_window->draw(m_pause_message);
            m_window->display();
            m_info_line.restartTime();
            clock.restart();
            for (int i = 0; i < m_characters.size() - CHARACTERS && m_clock_gnomes.size() > 0; i++)
                m_clock_gnomes[i].restart();
        }
    }
}
//-------------------------------------------------------------------------
void Controller::nextCharacter()
{
    Singleton::instance().playSound(SWITCH_SOUND);
    do {
        m_curr_character = ++m_curr_character % m_characters.size();
    } while (typeid(*m_characters[m_curr_character]) == typeid(Gnome));
}
//-------------------------------------------------------------------------
void Controller::manageCollision(sf::Time& delta_time, sf::Clock& clock)
{
    sf::Vector2f last_location = m_characters[m_curr_character]->getLocation();
    delta_time = clock.restart();
    m_characters[m_curr_character]->move(delta_time);

    collisionWithBoundaries(last_location); 
    collisionWithCharacters(last_location);
    collisionWithStasticObjects(last_location);
}
//-------------------------------------------------------------------------
void Controller::eraseStaticObject(StaticObject& static_object)
{
    for (auto static_ptr = m_static_objects.begin(); static_ptr != m_static_objects.end(); static_ptr++)
    {
        if ((*static_ptr)->getLocation() == static_object.getLocation())
        { 
            m_static_objects.erase(static_ptr);
            break;
        }
    }
}
//-------------------------------------------------------------------------
void Controller::eraseGnomes()
{
    std::vector<std::unique_ptr<MovingObject>> vec_tmp;
    for (auto moving_ptr = m_characters.begin(); moving_ptr != m_characters.end(); moving_ptr++)
    {
        if (typeid(**moving_ptr) != typeid(Gnome))
            vec_tmp.push_back(std::move(*moving_ptr));
    }
    
    m_characters.clear();
    m_clock_gnomes.clear();

    for (auto moving_ptr = vec_tmp.begin(); moving_ptr != vec_tmp.end(); moving_ptr++)
        m_characters.push_back(std::move(*moving_ptr));
}
//-------------------------------------------------------------------------
void Controller::collisionWithBoundaries(const sf::Vector2f& last_location)
{
    auto curr_global_bounds = m_characters[m_curr_character]->getGlobalBoundsSprite();
    if (curr_global_bounds.width + curr_global_bounds.left > WINDOW_WIDTH ||
        curr_global_bounds.left < 0 ||
        curr_global_bounds.height + curr_global_bounds.top > BOARD_HEIGHT ||
        curr_global_bounds.top < 0)
    {
        m_characters[m_curr_character]->setLocation(last_location);
        if (typeid(*m_characters[m_curr_character]) == typeid(Gnome))
            m_characters[m_curr_character]->setDirection(sf::Keyboard::Down);
        return ;
    }
    return ;
}
//-------------------------------------------------------------------------
void Controller::collisionWithCharacters(const sf::Vector2f& last_location)
{
    for (auto& character : m_characters)
    {
        if (m_characters[m_curr_character]->checkCollision(*character))
        {
            m_characters[m_curr_character]->setLocation(last_location);
            if (typeid(*m_characters[m_curr_character]) == typeid(Gnome))
                m_characters[m_curr_character]->setDirection(sf::Keyboard::Down);
            return ;
        }
    }
    return ;
}
//-------------------------------------------------------------------------
void Controller::collisionWithStasticObjects(const sf::Vector2f& last_location)
{
    for (auto& static_object : m_static_objects)
    {
        if (m_characters[m_curr_character]->checkCollision(*static_object))
        {
            m_characters[m_curr_character]->handleCollision(*static_object);
            switch (static_object->getCollision())
            {
            case Collisions::REGULAR_COLLISION:
                m_characters[m_curr_character]->setLocation(last_location);
                if (typeid(*m_characters[m_curr_character]) == typeid(Gnome))
                    m_characters[m_curr_character]->setDirection(sf::Keyboard::Down);
                else
                    Singleton::instance().playSound(WALL_SOUND);
                return ;
            case Collisions::WON:
                Singleton::instance().playSound(THRONE_SOUND);
                m_is_playing = false;
                m_pause_message.setString("You passed the level! :)\n next level press space");
                m_new_level = true;
                return ;

            case Collisions::OGRE:
                Singleton::instance().playSound(OGRE_SOUND);
                m_static_objects.push_back(std::make_unique<Key>(static_object->getLocation(), Singleton::instance().getObjectTexture(KEY)));
                m_board.resizeObject(*m_static_objects[m_static_objects.size()-1]);
                eraseStaticObject(*static_object);
                return ;

            case Collisions::KEY:
                Singleton::instance().playSound(KEY_SOUND);
                eraseStaticObject(*static_object);
                m_characters[m_curr_character]->setTexture(Singleton::instance().getObjectTexture(THIEF_KEY));
                m_board.resizeObject(*m_characters[m_curr_character]);
                if (m_characters[m_curr_character]->isRightPressed())
                    m_characters[m_curr_character]->rotateSprite(-1,1);
                return ;
            
            case Collisions::GATE:
                Singleton::instance().playSound(GATE_SOUND);
                eraseStaticObject(*static_object);
                m_characters[m_curr_character]->setTexture(Singleton::instance().getObjectTexture(THIEF));
                m_board.resizeObject(*m_characters[m_curr_character]);
                if (m_characters[m_curr_character]->isRightPressed())
                    m_characters[m_curr_character]->rotateSprite(-1, 1); 
                return ;
            
            case Collisions::FIRE:
                Singleton::instance().playSound(FIRE_SOUND);
                eraseStaticObject(*static_object);
                return;

            case Collisions::TELEPORT:
            {
                for (auto& character : m_characters)
                {
                    if (character->isOnTeleport())
                        return ;
                }
                Singleton::instance().playSound(TELEPORT_SOUND);
                m_characters[m_curr_character]->setLocation(m_board.findNextLocationTeleport(static_object->getLocation()));
                m_characters[m_curr_character]->setIsOnTeleport(true);
                return ;
            }
            case Collisions::GIFT1:
                Singleton::instance().playSound(GOOD_GIFT_SOUND);
                eraseStaticObject(*static_object);
                m_info_line.setTimeLeft(m_info_line.getTime() + ADD_TIME);
                return ;
            case Collisions::GIFT2:
                Singleton::instance().playSound(BAD_GIFT_SOUND);
                eraseStaticObject(*static_object);
                m_info_line.setTimeLeft(m_info_line.getTime() - ADD_TIME);
                return ;
            case Collisions::GIFT3:
                Singleton::instance().playSound(REMOVE_GNOME_SOUND);
                eraseStaticObject(*static_object);
                eraseGnomes();
                return ;
            }
        }
    }
    if (m_characters[m_curr_character]->isOnTeleport())
        m_characters[m_curr_character]->setIsOnTeleport(false);
    return ;
}
//-------------------------------------------------------------------------
void Controller::setLevel()
{
    m_curr_character = 0;
    m_characters.clear();
    m_static_objects.clear();
    m_clock_gnomes.clear();

    if (m_new_level)
    {
        if (getline(m_file_levels, m_curr_level))
            m_board.setBoard(m_curr_level, m_characters, m_static_objects);
        else
        {
            m_end_game = true;
            m_is_playing = false;
            m_pause_message.setString("You completed the game!\ncongratulations!\npress space to exit");
            return;
        }
        m_new_level = false;
        m_info_line.updateLevel();
    }
    else
    {
        m_board.setBoard(m_curr_level, m_characters, m_static_objects);
        m_info_line.restartTime();
    }
    switch (m_info_line.getLevel())
    {
    case 1: m_info_line.setTimeLeft(180); break;
    case 2: m_info_line.setTimeLeft(150); break;
    case 3: m_info_line.setTimeLeft(200); break;
    }
    Singleton::instance().playSound(START_SOUND);
    Singleton::instance().playMusic();
    for (int i = CHARACTERS; i < m_characters.size(); i++)
    {
        m_clock_gnomes.push_back(sf::Clock());
        m_characters[i]->setDirection(sf::Keyboard::Key::Left);
    }
}
//-------------------------------------------------------------------------
void Controller::setPauseMessage()
{
    m_pause_message.setFont(*Singleton::instance().getFont());
    m_pause_message.setCharacterSize(40);
    m_pause_message.setPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    m_pause_message.setFillColor(sf::Color::Black);
    m_pause_message.setString("press space to resume the game!");
    auto textRect = m_pause_message.getLocalBounds();
    m_pause_message.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
}
//-------------------------------------------------------------------------
void Controller::setRectPlayer()
{
    m_rect_player.setSize(sf::Vector2f(m_characters[m_curr_character]->getScaleSprite().x * OBJECT_SIZE_PIXEL, 
                                       m_characters[m_curr_character]->getScaleSprite().y * OBJECT_SIZE_PIXEL));
    m_rect_player.setOutlineColor(sf::Color::Black);
    m_rect_player.setOutlineThickness(3);
    m_rect_player.setFillColor(sf::Color::Transparent); 
    auto curr_global_bounds = m_characters[m_curr_character]->getGlobalBoundsSprite();
    if (m_characters[m_curr_character]->isRightPressed())
        m_rect_player.setPosition(sf::Vector2f(curr_global_bounds.width + curr_global_bounds.left, curr_global_bounds.top));
    else   
        m_rect_player.setPosition(sf::Vector2f(curr_global_bounds.left, curr_global_bounds.top));
}
//-------------------------------------------------------------------------
Controller::~Controller()
{
    m_file_levels.close();
}
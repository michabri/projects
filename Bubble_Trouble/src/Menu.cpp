#include "Menu.h"

Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Bubble Trouble")
{
    Resources::instance().setMusic(music_song::MENU_SONG, false);
    m_window.setFramerateLimit(240);
    m_gameOn = m_need_help = m_multiplayer = false;
    initButtons();

    //initiate help bar
    m_help_bar = sf::RectangleShape(sf::Vector2f(1280, 720));
    m_help_bar.setPosition(sf::Vector2f(200, 50));
    m_help_bar.setOutlineThickness(3);
    m_help_bar.setOutlineColor(sf::Color::Black);
    m_help_bar.setTexture(Resources::instance().getBackground(background::HELP));
    m_bg = sf::Sprite(*Resources::instance().getBackground(background::BACKGROUND));

    // set window icon 
    //auto icon = sf::Image{};
    //m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

//=======================================================================================
void Menu::run()
{
    //bool need_help = false;
    while (m_window.isOpen())
    {
        m_window.clear(sf::Color::White);
        m_window.draw(m_bg);
        draw();
        if (m_need_help)
            m_window.draw(m_help_bar);
        m_window.display();
        eventsHandler();
    }
}

//=======================================================================================
void Menu::eventsHandler()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        if ((event.type == sf::Event::Closed) ||
            ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
        {
            m_window.close();
        }

        switch (event.type)
        {
        case sf::Event::MouseMoved: 
        {
            auto loc = m_window.mapPixelToCoords(
                { event.mouseMove.x, event.mouseMove.y });
            handleHover(loc); 
            break;
        }

        case sf::Event::MouseButtonPressed:

            auto location = m_window.mapPixelToCoords(
                { event.mouseButton.x, event.mouseButton.y });
            
            switch (event.mouseButton.button)
            {
                case sf::Mouse::Button::Left:
                    if (!m_need_help)
                    {
                        handleButtons(location); //check if a button is pressed
                    }
                    else
                    {
                        m_need_help = false; // lower the help bar if the mouse clicked anywhere
                    }
                    break;
            }
            break;
        }
    }
}
//=======================================================================================
void Menu::draw()
{
    if (!m_gameOn)
    {
        for (int i = 0; i < m_buttons.size(); i++)
        {
            m_buttons[i].draw(m_window);
        }
    }
    else
    {
        if (!m_multiplayer)
        {
            for (int i = 0; i < m_gameModeButtons.size(); i++)
            {
                m_gameModeButtons[i].draw(m_window);
            }
        }
        else
        {
            for (int i = 0; i < m_multiplayerButtons.size(); i++)
            {
                m_multiplayerButtons[i].draw(m_window);
            }
        }

    }
}
//=======================================================================================
void Menu::handleButtons(const sf::Vector2f& location)
{
    if (!m_gameOn)
    {
        for (int i = 0; i < m_buttons.size(); i++)
        {
            if (m_buttons[i].handleClick(location))
            {
                switch (i)
                {
                case 0:
                    m_gameOn = true;
                    break;

                case 1:
                    m_need_help = true;
                    break;

                default:
                    m_window.close();
                    break;
                }
            }
        }
    }
    else
    {
        if (!m_multiplayer)
        {
            for (int i = 0; i < m_gameModeButtons.size(); i++)
            {
                if (m_gameModeButtons[i].handleClick(location))
                {
                    switch (i)
                    {
                    case 0:
                        Controller(1).run(m_window);
                        m_gameOn = false;
                        break;

                    case 1:
                        Controller(2).run(m_window);
                        m_gameOn = false;
                        break;

                    case 2:
                        m_multiplayer = true;
                        break;

                    default:
                        m_gameOn = false;
                        break;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < m_multiplayerButtons.size(); i++)
            {
                if (m_multiplayerButtons[i].handleClick(location))
                {
                    switch (i)
                    {
                    case 0: // host
                        m_socket.setMode(true);
                        hostWaitMenu();
                        m_socket.openHost();
                        Controller(&m_socket, true).run(m_window);
                        m_socket.disconnect();
                        m_gameOn = false;
                        break;

                    case 1: // client
                        m_socket.setMode(false);
                        m_socket.connect(getIp());
                        Controller(&m_socket, false).run(m_window);
                        m_socket.disconnect();
                        m_gameOn = false;
                        break;

                    default:
                        m_multiplayer = false;
                        break;
                    }
                }
            }
        }
    }
}

//=======================================================================================
void Menu::handleHover(const sf::Vector2f& location)
{
    m_buttons[m_lastHover].setColor(); // return to default color
    m_gameModeButtons[m_lastHoverGM].setColor();
    m_multiplayerButtons[m_lastHoverMulti].setColor();
    if (!m_gameOn)
    {
        for (int i = 0; i < m_buttons.size(); i++)
        {
            if (m_buttons[i].getGlobalBounds().contains(location))
            {
                // change the color if hovered over the button
                m_buttons[i].setColor(sf::Color(0, 137, 255));

                m_lastHover = i; // set current button as the last button hovered over
            }
        }
    }
    else
    {
        if (!m_multiplayer)
        {
            for (int i = 0; i < m_gameModeButtons.size(); i++)
            {
                if (m_gameModeButtons[i].getGlobalBounds().contains(location))
                {
                    // change the color if hovered over the button
                    m_gameModeButtons[i].setColor(sf::Color(0, 137, 255));

                    m_lastHoverGM = i;
                }
            }
        }
        else
        {
            for (int i = 0; i < m_multiplayerButtons.size(); i++)
            {
                if (m_multiplayerButtons[i].getGlobalBounds().contains(location))
                {
                    // change the color if hovered over the button
                    m_multiplayerButtons[i].setColor(sf::Color(0, 137, 255));

                    m_lastHoverMulti = i;
                }
            }
        }
    }
}

void Menu::initButtons()
{
    for (int i = 0; i < m_buttonsTexts.size(); i++)
    { 
        m_buttons.push_back(Button(sf::Vector2f(300, 80), m_buttonsTexts[i], sf::Vector2f(800, 330 + i * 150)));
    }
    for (int i = 0; i < m_gameModeTexts.size(); i++)
    {
        m_gameModeButtons.push_back(Button(sf::Vector2f(300, 80), m_gameModeTexts[i], sf::Vector2f(800, 230 + i * 150)));
    }
    for (int i = 0; i < m_multiplayerTexts.size(); i++)
    {
        m_multiplayerButtons.push_back(Button(sf::Vector2f(300, 80), m_multiplayerTexts[i], sf::Vector2f(800, 330 + i * 150)));
    }
}

std::string Menu::getIp()
{
    std::string input = "";
    initMultiplayerTexts();

    Button connect(sf::Vector2f(300, 80), "Connect", sf::Vector2f(550, 600));
    Button clear(sf::Vector2f(300, 80), "Clear", sf::Vector2f(900, 600));
    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(m_bg);
        m_window.draw(m_head);
        m_ipInput.setString(input);
        m_window.draw(m_ipInput);
        connect.draw(m_window);
        clear.draw(m_window);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                m_window.close();
            }
            switch (event.type)
            {
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Button::Left:
                    auto location = m_window.mapPixelToCoords(
                        { event.mouseButton.x, event.mouseButton.y });
                    if (connect.handleClick(location)) //check if a button is pressed
                        return input;

                    if (clear.handleClick(location))
                        input.clear();
                    break;
                }
                break;

            case sf::Event::TextEntered:
                input += char(event.text.unicode);
                break;
            }
        }
    }
    
    return input;
}

void Menu::initMultiplayerTexts()
{
    m_head.setFont(*Resources::instance().getFont());
    m_head.setString("Enter IP address to connect to:");
    m_head.setCharacterSize(40);
    m_head.setOutlineThickness(3);
    m_head.setPosition(WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 3.f);
    
    m_ipInput.setFont(*Resources::instance().getFont());
    m_ipInput.setCharacterSize(40);
    m_ipInput.setOutlineThickness(3);
    m_ipInput.setPosition(WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 2.f);
}

void Menu::hostWaitMenu()
{
    m_head.setFont(*Resources::instance().getFont());
    m_head.setString("Waiting for Connection, your Ip is:");
    m_head.setCharacterSize(40);
    m_head.setOutlineThickness(3);
    m_head.setPosition(WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 3.f);

    m_ipInput.setFont(*Resources::instance().getFont());
    m_ipInput.setCharacterSize(40);
    m_ipInput.setOutlineThickness(3);
    m_ipInput.setPosition(WINDOW_WIDTH / 4.f, WINDOW_HEIGHT / 2.f);
    m_ipInput.setString(m_socket.getLocalIp());

    m_window.clear();
    m_window.draw(m_bg);
    m_window.draw(m_head);
    m_window.draw(m_ipInput);
    m_window.display();

    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        if ((event.type == sf::Event::Closed) ||
            ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
        {
            m_window.close();
        }
    }
}
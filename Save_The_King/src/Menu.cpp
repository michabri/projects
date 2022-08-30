#include "Menu.h"

//---------------------------------------------------
Menu::Menu()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Save The King"), m_controller(m_window)
{
    for (int index = 0; index < NUM_OF_BUTTONS; index++)
        m_buttons[index] = Button(index);
}
//--------------------------------------------------------
void Menu::run()
{ 
    sf::Sprite background = Singleton::instance().getMenuSprite(MENU_BACKGROUND_PIC);
    sf::Sprite instructions = Singleton::instance().getMenuSprite(INSTRUCTION_PIC);
    instructions.setPosition(sf::Vector2f(300, 100));
    bool instructions_pressed = false;
    int last_button_over = 0;

    while (m_window.isOpen())
    {
        m_window.clear();
        m_window.draw(background);
        drawButtons();  
        if (instructions_pressed)
            m_window.draw(instructions);
        m_window.display();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Button::Left)
                {
                    instructions_pressed = false;
                    auto location = sf::Mouse::getPosition(m_window);
                    for (int i = 0; i < NUM_OF_BUTTONS; i++)
                    {
                        if (m_buttons[i].handleMouseOver((sf::Vector2f)location))
                            doButton(i, instructions_pressed);
                    }
                }
                break;
            
            case sf::Event::MouseMoved:
                auto location = sf::Mouse::getPosition(m_window); 
                m_buttons[last_button_over].setColor(sf::Color(204, 0, 0));
                for (int i = 0; i < NUM_OF_BUTTONS; i++)
                {
                    if (m_buttons[i].handleMouseOver((sf::Vector2f)location))
                    {
                        m_buttons[i].setColor(sf::Color(255, 0, 0));
                        last_button_over = i;
                    }
                }
                break;
            }
        }
    }
}
//--------------------------------------------------------
void Menu::drawButtons()
{
    for (int i = 0; i < NUM_OF_BUTTONS; i++)
        m_buttons[i].draw(m_window);
}
//--------------------------------------------------------
void Menu::doButton(const int index, bool &instruction_pressed)
{
    switch(index)
    {
    case START:
        m_controller.run();
        break;

    case INSTRUCTIONS:
        instruction_pressed = true;
        break;

    case EXIT:
        m_window.close();
        break;
    }
}

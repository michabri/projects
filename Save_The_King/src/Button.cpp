#include "Button.h"

//-------------------------------------------------------------------------
Button::Button(const int& index)
{
    setButton(index);
}
//-------------------------------------------------------------------------
void Button::setButton(const int& index)
{
    // set Rectangle
    m_button.setSize(sf::Vector2f(BUTTON_SIZE_WIDTH, BUTTON_SIZE_HEIGHT));
    m_button.setPosition(sf::Vector2f(WINDOW_WIDTH / 2, 300 + index * 150));
    m_button.setFillColor(sf::Color(204, 0, 0));
    m_button.setOutlineColor(sf::Color::Black);
    m_button.setOutlineThickness(2);
    m_button.setOrigin(sf::Vector2f(BUTTON_SIZE_WIDTH / 2, BUTTON_SIZE_HEIGHT / 2));

    // set text
    m_text.setFont(*Singleton::instance().getFont());
    m_text.setCharacterSize(25);
    m_text.setString(MENU_BUTTONS_TEXT[index]);
    m_text.setColor(sf::Color::White);
    m_text.setPosition(m_button.getPosition());
    auto textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.width / 2.0f, textRect.height / 2.0f);
}
//-------------------------------------------------------------------------
void Button::draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}
//-------------------------------------------------------------------------
bool Button::handleMouseOver(const sf::Vector2f& location)
{
    if (m_button.getGlobalBounds().contains(location))
        return true;
    return false;
}
//-------------------------------------------------------------------------
void Button::setColor(const sf::Color& color)
{
    m_button.setFillColor(color);
}

#pragma once
#include <string.h>
#include "macros.h"
#include "Singleton.h"

class Button
{
public:
	Button() = default;
	Button(const int& index);
	bool handleMouseOver(const sf::Vector2f& location);
	void draw(sf::RenderWindow& window);
	void setColor(const sf::Color& color);

private:
	void setButton(const int& index);

	sf::RectangleShape m_button;
	sf::Text m_text;
};

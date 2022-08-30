#include "InfoLine.h"

InfoLine::InfoLine()
:m_time_left(0), m_level(0)
{
	setText();
}
//-------------------------------------------------------------------------
void InfoLine::setText()
{
	m_text_timer.setFont(*Singleton::instance().getFont());
	int size = 40;
	m_text_timer.setCharacterSize(size);
	m_text_timer.setPosition(50, BOARD_HEIGHT + (WINDOW_HEIGHT - BOARD_HEIGHT) / 2 - size/2);
	m_text_timer.setColor(sf::Color::Red);
	m_text_timer.setOutlineColor(sf::Color::Black);
	m_text_timer.setOutlineThickness(3);
}
//-------------------------------------------------------------------------
void InfoLine::updateTime()
{
	m_time_left -= m_timer.getElapsedTime().asSeconds();
	int minutes = m_time_left / 60;
	int seconds = (int)m_time_left % 60;
	m_text_timer.setString("Time Left: " + 
						  (minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes)) + ":" +
						  (seconds < 10 ? "0" + std::to_string(seconds) : std::to_string(seconds)) + 
						  "     Level: " + std::to_string(m_level));
	m_timer.restart();
}
//-------------------------------------------------------------------------
float InfoLine::getTime() const
{
	return m_time_left;
}
//-------------------------------------------------------------------------
void InfoLine::setTimeLeft(const float& time)
{
	m_time_left = time;
} 
//-------------------------------------------------------------------------
void InfoLine::draw(sf::RenderWindow& window)
{
	updateTime();
	window.draw(m_text_timer);
}
//-------------------------------------------------------------------------
void InfoLine::updateLevel()
{
	m_level++;
	m_timer.restart();
}
//-------------------------------------------------------------------------
void InfoLine::restartTime()
{
	m_timer.restart();
}
//-------------------------------------------------------------------------
int InfoLine::getLevel() const
{
	return m_level;
}

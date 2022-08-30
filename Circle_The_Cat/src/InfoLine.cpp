#include <stack>
#include "InfoLine.h"

//-------------------------------------------------------------------------
InfoLine::InfoLine()
	:m_num_of_clicks(0), m_level(1)
{
	setTextClicks();
	setTextUndo();
	setTextLevel();
	m_player_actions.push(Location(-1, -1));
	m_cat_movement.push(Location(-1, -1));
	m_cat_movement.push(Location((int)BOARD_SIZE / 2, (int)BOARD_SIZE / 2));
}
//-------------------------------------------------------------------------
void InfoLine::setTextClicks()
{
	m_text_num_of_clicks.setFont(*Singleton::instance().getFont());
	m_text_num_of_clicks.setString("num of clicks: " + std::to_string(m_num_of_clicks));
	int size = 30;
	m_text_num_of_clicks.setCharacterSize(size);
	m_text_num_of_clicks.setPosition(25, BOARD_HEIGHT + (WINDOW_HEIGHT - BOARD_HEIGHT) / 2);
	m_text_num_of_clicks.setColor(sf::Color::Black);
}
//-------------------------------------------------------------------------
void InfoLine::addNumClicks(const int& click)
{
	m_num_of_clicks += click;
	m_text_num_of_clicks.setString("num of clicks: " + std::to_string(m_num_of_clicks));
}
//-------------------------------------------------------------------------
void InfoLine::setTextUndo()
{
	m_text_undo.setFont(*Singleton::instance().getFont());
	m_text_undo.setString("Undo");
	int size = 30;
	m_text_undo.setCharacterSize(size);
	m_text_undo.setPosition(850, BOARD_HEIGHT + (WINDOW_HEIGHT - BOARD_HEIGHT) / 2);
	m_text_undo.setColor(sf::Color::Black);
}
//-------------------------------------------------------------------------
void InfoLine::setTextLevel()
{
	m_text_level.setFont(*Singleton::instance().getFont());
	m_text_level.setString("Level: " + std::to_string(m_level));
	int size = 30;
	m_text_level.setCharacterSize(size);
	m_text_level.setPosition(450, BOARD_HEIGHT + (WINDOW_HEIGHT - BOARD_HEIGHT) / 2);
	m_text_level.setColor(sf::Color::Black);
}
//-------------------------------------------------------------------------
void InfoLine::draw(sf::RenderWindow& window) const
{
	window.draw(m_text_num_of_clicks);
	window.draw(m_text_level);
	window.draw(m_text_undo);
}
//-------------------------------------------------------------------------
void InfoLine::addCatMovement(const Location& loc)
{
	m_cat_movement.push(loc);
}
//-------------------------------------------------------------------------
void InfoLine::addPlayerAction(const Location& loc)
{
	m_player_actions.push(loc);
}
//-------------------------------------------------------------------------
bool InfoLine::handleClick(const sf::Vector2f& location)
{
	return m_text_undo.getGlobalBounds().contains(location);
}
//-------------------------------------------------------------------------
Location InfoLine::getLastPlayerAction()
{
	Location loc = m_player_actions.top();
	if (loc.row != -1)
		m_player_actions.pop();
	return loc;
}
//-------------------------------------------------------------------------
Location InfoLine::getLastCatMovement()
{
	if (m_num_of_clicks == 0)
		return Location(-1, -1);
	m_cat_movement.pop();
	Location loc = m_cat_movement.top();
	return loc;
}
//-------------------------------------------------------------------------
void InfoLine::newLevel()
{
	m_num_of_clicks = 0;
	m_text_num_of_clicks.setString("num of clicks: " + std::to_string(m_num_of_clicks));
	m_level++;
	m_text_level.setString("Level: " + std::to_string(m_level));
	Location loc = m_player_actions.top();
	while (loc.row != -1)
	{
		m_player_actions.pop();
		loc = m_player_actions.top();
	}
	loc = m_cat_movement.top();
	while (loc.row != -1)
	{
		m_cat_movement.pop();
		loc = m_cat_movement.top();
	}
	m_cat_movement.push(Location((int)BOARD_SIZE / 2, (int)BOARD_SIZE / 2));
}
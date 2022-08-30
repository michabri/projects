#pragma once
#include "macros.h"
#include "Singleton.h"
#include <stack>

class InfoLine
{
public:
	InfoLine();
	void addNumClicks(const int& click);
	void draw(sf::RenderWindow& window) const;
	void addCatMovement(const Location& loc);
	void addPlayerAction(const Location& loc);
	bool handleClick(const sf::Vector2f& location);
	Location getLastPlayerAction();
	Location getLastCatMovement();
	void newLevel();

private:
	void setTextClicks();
	void setTextUndo();
	void setTextLevel();

	sf::Text m_text_num_of_clicks;
	sf::Text m_text_undo;
	sf::Text m_text_level;

	std::stack<Location> m_cat_movement;
	std::stack<Location> m_player_actions;
	
	int m_num_of_clicks;
	int m_level;
};
#pragma once
#include <iostream>
#include "macros.h"
#include "Singleton.h"

class InfoLine
{
public:
	InfoLine();
	void updateTime();
	void updateLevel();
	float getTime() const;
	void setTimeLeft(const float& time);
	void restartTime();
	void draw(sf::RenderWindow& window);
	int getLevel() const;

private:
	void setText();

	int m_level;
	sf::Clock m_timer;
	float m_time_left;
	sf::Text m_text_timer;
};
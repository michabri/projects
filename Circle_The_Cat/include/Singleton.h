#pragma once
#include <SFML/Graphics.hpp>
#include "macros.h"

class Singleton {
public:
	~Singleton();
	static Singleton& instance();
	sf::Font* getFont();
	sf::Texture* getCat();
	sf::Texture* getLevelUp();
	sf::Texture* getLostLevel();
	sf::Texture* getGameOver();
private:
	Singleton();
	Singleton(const Singleton&) = default;
	Singleton& operator=(const Singleton&) = default;
	sf::Font m_font;
	sf::Texture m_cat;
	sf::Texture m_level_up;
	sf::Texture m_lost_level;
	sf::Texture m_game_over;
};
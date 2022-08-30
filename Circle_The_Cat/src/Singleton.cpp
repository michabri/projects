#include "Singleton.h"

//-------------------------------------------------------------------------
Singleton::Singleton()
{
	m_font.loadFromFile("Side Of Monster.ttf");
	m_cat.loadFromFile("resized_cat.png");
	m_level_up.loadFromFile("level_up.jpg");
	m_lost_level.loadFromFile("lost.jpg");
	m_game_over.loadFromFile("game_over.jpg");
}
//-------------------------------------------------------------------------
Singleton& Singleton::instance()
{
	static Singleton inst;
	return inst;
}
//-------------------------------------------------------------------------
sf::Font* Singleton::getFont()
{
	return &m_font;
}
//-------------------------------------------------------------------------
sf::Texture* Singleton::getCat()
{
	return &m_cat;
}
//-------------------------------------------------------------------------
sf::Texture* Singleton::getLevelUp()
{
	return &m_level_up;
}
//-------------------------------------------------------------------------
sf::Texture* Singleton::getLostLevel()
{
	return &m_lost_level;
}
//-------------------------------------------------------------------------
sf::Texture* Singleton::getGameOver()
{
	return &m_game_over;
}
//-------------------------------------------------------------------------
Singleton::~Singleton()
{}
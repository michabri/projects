#include "Cat.h"

//-------------------------------------------------------------------------
Cat::Cat()
	:m_loc(Location((int)BOARD_SIZE/2, (int)BOARD_SIZE / 2))
{
	buildCat();
}
//-------------------------------------------------------------------------
void Cat::buildCat()
{
	//texture
	m_cat.setTexture(*Singleton::instance().getCat());

	//scale
	float scale_cat = BOARD_WIDTH / BOARD_SIZE;
	m_cat.setScale(scale_cat / (float)(OBJECT_SIZE_PIXEL + 5), scale_cat / (float)(OBJECT_SIZE_PIXEL + 5));
	
	//location on the window
	sf::Vector2f loc((WINDOW_WIDTH - BOARD_WIDTH) / 2.f + (int)(BOARD_SIZE/2) * (SPACE + 2 * RADIUS_TILE),
		(WINDOW_HEIGHT - BOARD_HEIGHT) / 2.f + (int)(BOARD_SIZE / 2) * (SPACE + 2 * RADIUS_TILE));
	if ((int)BOARD_SIZE % 2 == 0)
		m_cat.setPosition(loc);
	else
		m_cat.setPosition(loc.x + RADIUS_TILE, loc.y);
	
	//origin
	m_cat.setOrigin(m_cat.getLocalBounds().width / 2, m_cat.getLocalBounds().height / 2);

}
//-------------------------------------------------------------------------
void Cat::draw(sf::RenderWindow& window) const
{
	window.draw(m_cat);
}
//-------------------------------------------------------------------------
const Location Cat::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------------------
void Cat::setLocation(const Location& loc)
{
	m_loc = loc;
	sf::Vector2f new_loc((WINDOW_WIDTH - BOARD_WIDTH) / 2.f + (float)loc.col * (SPACE + 2 * RADIUS_TILE),
		(WINDOW_HEIGHT - BOARD_HEIGHT) / 2.f + (float)loc.row * (SPACE + 2 * RADIUS_TILE));
	if (loc.row % 2 == 0)
		m_cat.setPosition(new_loc);
	else
		m_cat.setPosition(new_loc.x + RADIUS_TILE, new_loc.y);
	m_cat.setOrigin(m_cat.getLocalBounds().width / 2, m_cat.getLocalBounds().height / 2);
}
#include "Tile.h"

//-------------------------------------------------------------------------
Tile::Tile(const int& row, const int& col) 
	:m_is_pressed(false)
{
	buildTile(row, col);
}
//-------------------------------------------------------------------------
void Tile::buildTile(const int& row, const int& col)
{
	//build the circle
	m_tile.setFillColor(sf::Color(204, 255, 0));
	m_tile.setRadius(RADIUS_TILE);
	sf::Vector2f loc((WINDOW_WIDTH - BOARD_WIDTH) / 2.f + (float)col * (SPACE + 2 * RADIUS_TILE),
		(WINDOW_HEIGHT - BOARD_HEIGHT) / 2.f + (float)row * (SPACE + 2 * RADIUS_TILE));
	if (row % 2 == 0)
		m_tile.setPosition(loc);
	else
		m_tile.setPosition(loc.x + m_tile.getRadius(), loc.y);
	m_tile.setOrigin(m_tile.getLocalBounds().width / 2, m_tile.getLocalBounds().height / 2);
	
	//location in the vector (matrix)
	m_loc = Location(row, col);

	//find adjacent Tiles
	adjacentTiles(row, col);
}
//-------------------------------------------------------------------------
void Tile::adjacentTiles(const int& row, const int& col)
{
	if (row % 2 == 0)
	{
		if (row - 1 > -1 && col - 1 > -1)
			m_adj.push_back(Location(row-1, col-1));
		if (row + 1 < BOARD_SIZE && col - 1 > -1)
			m_adj.push_back(Location(row + 1, col - 1));
	}
	else
	{
		if (row - 1 > -1 && col + 1 < BOARD_SIZE)
			m_adj.push_back(Location(row - 1, col + 1));
		if (row + 1 < BOARD_SIZE && col + 1 < BOARD_SIZE)
			m_adj.push_back(Location(row + 1, col + 1));
	}
	if(col - 1 > -1)
		m_adj.push_back(Location(row, col -1));
	if (col + 1 < BOARD_SIZE)
		m_adj.push_back(Location(row, col + 1));
	if (row - 1 > -1)
		m_adj.push_back(Location(row - 1, col));
	if (row + 1 < BOARD_SIZE)
		m_adj.push_back(Location(row + 1, col));
	
}
//-------------------------------------------------------------------------
void Tile::draw(sf::RenderWindow& window) const
{
	window.draw(m_tile);
}
//-------------------------------------------------------------------------
bool Tile::handleClick(const sf::Vector2f& location, const Location& cat_location)
{
	if (m_tile.getGlobalBounds().contains(location) && !m_is_pressed && 
		(m_loc.row != cat_location.row || m_loc.col != cat_location.col))
	{
		setIsPressed(true);
		return true;
	}
	return false;
}
//-------------------------------------------------------------------------
int Tile::getSizeAdjTiles() const
{
	return m_adj.size();
}
//-------------------------------------------------------------------------
Location Tile::getIndexAdjacentTile(const int& index) const
{
	return m_adj[index];
}
//-------------------------------------------------------------------------
Location Tile::getLocation() const
{
	return m_loc;
}
//-------------------------------------------------------------------------
bool Tile::getIsPressed() const
{
	return m_is_pressed;
}
//-------------------------------------------------------------------------
void Tile::setIsPressed(const bool& is_pressed)
{
	if (is_pressed)
		m_tile.setFillColor(sf::Color(114, 133, 1));
	else
		m_tile.setFillColor(sf::Color(204, 255, 0));
	m_is_pressed = is_pressed;
}

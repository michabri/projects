#pragma once
#include <iostream>
#include "macros.h"
#include "Singleton.h"
#include <vector>
#include <algorithm>
#include <random>
#include <stdio.h>
#include <time.h>

class Tile 
{
public:
	Tile() = default;
	Tile(const int& row, const int& col);
	void draw(sf::RenderWindow& window) const;
	bool handleClick(const sf::Vector2f& location, const Location& cat_location);
	int getSizeAdjTiles() const;
	Location getLocation() const;
	Location getIndexAdjacentTile(const int& index) const;
	bool getIsPressed() const;
	void setIsPressed(const bool& is_pressed);

private:
	void buildTile(const int& row, const int& col);
	void adjacentTiles(const int& row, const int& col);

	sf::CircleShape m_tile;
	Location m_loc;
	std::vector <Location> m_adj;
	bool m_is_pressed;
};
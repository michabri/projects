#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include "macros.h"
#include "Singleton.h"
#include "Tile.h"
#include <stdio.h>
#include <time.h>


class Board 
{
public:
	Board();
	void draw(sf::RenderWindow& window) const;
	bool handleClick(const sf::Vector2f& location, const Location& cat_location, Location& player_action);
	Location getNextCatLocation(const Location& cat_location);
	void randomizeBoard(const int& level);
	void undoTile(const Location& loc);

private:
	void buildBoard();
	void clearBoard();
	bool BFS(int pred[], int dist[], int& destination, const Location& cat_location);
	std::vector<std::unique_ptr<Tile>> m_board;
};
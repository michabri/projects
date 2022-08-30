#pragma once
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <memory>
#include "macros.h"
#include "Singleton.h"
#include "GameObject.h"
#include "MovingObject.h"
#include "StaticObject.h"
#include "King.h"
#include "Mage.h"
#include "Warrior.h"
#include "Thief.h"
#include "Gnome.h"
#include "Teleport.h"
#include "Key.h"
#include "Wall.h"
#include "Throne.h"
#include "Gate.h"
#include "Ogre.h"
#include "Fire.h"
#include "Gift1.h"
#include "Gift2.h"
#include "Gift3.h"


class Board {
public:
	Board();
	void setBoard(std::string name_level,
				  std::vector< std::unique_ptr <MovingObject > > &characters, 
				  std::vector< std::unique_ptr <StaticObject > > &static_objects);
	void draw(sf::RenderWindow& window) const;
	
	const sf::Vector2f& findNextLocationTeleport(const sf::Vector2f& loc);
	void resizeObject(GameObject& game_object);

private:
	void createObject();
	void setLine();

	int m_rows;
	int m_cols;
	sf::RectangleShape m_line;

	std::vector< std::string> m_board;
	std::vector< std::unique_ptr <StaticObject > >* m_static_objects;
	std::vector< std::unique_ptr <MovingObject > >* m_characters;
	std::vector <std::unique_ptr <sf::Vector2f > > m_teleports;
};
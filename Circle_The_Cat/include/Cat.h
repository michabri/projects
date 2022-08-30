#pragma once
#include <iostream>
#include "macros.h"
#include "Singleton.h"

class Cat 
{
public:
	Cat();
	void draw(sf::RenderWindow& window) const;
	const Location getLocation() const;
	void setLocation(const Location& loc);

private:
	void buildCat();
	sf::Sprite m_cat;
	Location m_loc;
};
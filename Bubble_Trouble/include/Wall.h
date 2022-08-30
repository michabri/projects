#pragma once
#include "StaticObject.h"

static int id_wall = 0;

class Wall : public StaticObject 
{
public:
	Wall() = default;
	Wall(const sf::Vector2f& pos, b2World* world, const sf::Vector2f& scale);
	virtual int getValue() const override { return 0; }

private:
	void initWall(const sf::Vector2f& loc, b2World* world);
};
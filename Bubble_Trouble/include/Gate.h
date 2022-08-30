#pragma once
#include "StaticObject.h"

static int id_gate = 0;

class Gate : public StaticObject
{
public:
	Gate() = default;
	Gate(const sf::Vector2f& pos, b2World* world, const sf::Vector2f& scale);
	virtual int getValue() const override { return 0; }

private:
	void initGate(const sf::Vector2f& loc, b2World* world);
};
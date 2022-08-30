#pragma once
#include "StaticObject.h"

static int id_gift = 0;

class Gift : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Gift(const sf::Vector2f& loc, b2World* world, const int& value);
	virtual int getValue() const override;
	virtual void draw(sf::RenderWindow& window) const override;
	virtual bool updateObj() override;
	virtual void restartTimer() override;

private:
	int m_value;
	float m_count_down = 5;
	sf::Clock m_Timer;
};
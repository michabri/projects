#pragma once

#include "MovingObject.h"

static int id_ball = 0;

class Ball : public MovingObject 
{
public:
	using MovingObject::MovingObject;
	Ball(const sf::Vector2f& loc, float radius, b2World* world, const b2Vec2& velocity);
	virtual void draw(sf::RenderWindow& window) const override;
	bool getPopStatus() const;
	float getRadius() const;
	void upadateBall();
	virtual sf::Vector2f getLocation() const;

private:
	void initBall(const sf::Vector2f& loc, float radius, b2World* world, const b2Vec2& velocity);
	float getGravityScale() const;

	sf::CircleShape m_circle;
	b2CircleShape m_dynamicCircle;
	
	float m_radius;
	float m_angle;
	bool m_pop = false;
};
#include "Ball.h"

//=======================================================================================
Ball::Ball(const sf::Vector2f& loc, float radius, b2World* world, const b2Vec2& velocity)
	: m_radius(radius)
{
	initBall(loc, radius, world, velocity);
	
	m_angle = m_body->GetAngle();

	m_circle = sf::CircleShape(radius);
	if (radius == ballRadius::MEGA_BIG)
	{
		m_circle.setTexture(&(*Resources::instance().getTexture(gameObjects::PURPLE_BALL)));
	}
	else if (radius == ballRadius::BIG)
	{
		m_circle.setTexture(&(*Resources::instance().getTexture(gameObjects::BLUE_BALL)));
	}
	else if (radius == ballRadius::MEDIUM)
	{
		m_circle.setTexture(&(*Resources::instance().getTexture(gameObjects::ORANGE_BALL)));
	}
	else
	{
		m_circle.setTexture(&(*Resources::instance().getTexture(gameObjects::RED_BALL)));
	}
	m_circle.setOrigin(radius, radius);
	b2Vec2 physiceLoc(loc.x, loc.y);
	m_circle.setPosition(physiceLoc.x, physiceLoc.y);
}
//=======================================================================================
void Ball::initBall(const sf::Vector2f& loc, float radius, b2World* world, const b2Vec2& velocity)
{
	//b2Vec2 m_leftVelocity = b2Vec2(-40.f, 1.f);
	//b2Vec2 m_rightVelocity = b2Vec2(40.f, 1.f);
	m_dynamicCircle.m_p.Set(1.f, 1.f);
	m_dynamicCircle.m_radius = radius / 2.f;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(loc.x, loc.y);
	bodyDef.linearVelocity = velocity;

	bodyDef.gravityScale = getGravityScale();
	m_body = world->CreateBody(&bodyDef);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &m_dynamicCircle;
	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.f;
	fixtureDef.restitution = 1.f;
	fixtureDef.filter.categoryBits = entity::BALL;
	fixtureDef.filter.maskBits = entity::WEAPON | entity::WALL | entity::PLAYER |
								 entity::BORDER_FLOOR | entity::BORDER_CEILING | entity::SHIELD;
	fixtureDef.filter.groupIndex = id_ball++;
	m_fixture = m_body->CreateFixture(&fixtureDef);
}
//=======================================================================================
void Ball::draw(sf::RenderWindow& window) const
{
	window.draw(m_circle);
}
//=======================================================================================
bool Ball::getPopStatus() const
{
	return m_pop;
}
//=======================================================================================
float Ball::getRadius() const
{
	return m_radius;
}
//=======================================================================================
float Ball::getGravityScale() const
{
	auto val = int(m_dynamicCircle.m_radius * 2);
	switch (val)
	{
	case ballRadius::MEGA_BIG:
		return 1;
	case ballRadius::BIG:
		return 2.5;
	case ballRadius::MEDIUM:
		return 3.5;
	default:
		return 4;
	}
}
//=======================================================================================
sf::Vector2f Ball::getLocation() const
{
	return m_circle.getPosition();
}
//=======================================================================================
void Ball::upadateBall()
{
	auto& position = m_body->GetPosition();
	m_circle.setPosition(position.x, position.y);
}
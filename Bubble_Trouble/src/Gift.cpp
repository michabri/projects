#include "Gift.h"

//=======================================================================================
Gift::Gift(const sf::Vector2f& loc, b2World* world, const int& value)
	:m_value(value)
{
	m_obj.setSize(sf::Vector2f(25.f, 50.f));
	switch (value)
	{
	case gift::NORMAL_WEAPON : m_obj.setTexture(Resources::instance().getTexture(gameObjects::NORMAL_WEAPON_GIFT_GO)); break;
	case gift::HOOK_WEAPON: m_obj.setTexture(Resources::instance().getTexture(gameObjects::HOOK_WEAPON_GIFT_GO)); break;
	case gift::LASER_WEAPON: m_obj.setTexture(Resources::instance().getTexture(gameObjects::LASER_WEAPON_GO)); 
		m_obj.setSize(sf::Vector2f(50.f, 25.f)); break;
	case gift::GREEN_CLOCK: m_obj.setTexture(Resources::instance().getTexture(gameObjects::GREEN_CLOCK_GO)); 
		m_obj.setSize(sf::Vector2f(30.f, 30.f)); break;
	case gift::RED_CLOCK: m_obj.setTexture(Resources::instance().getTexture(gameObjects::RED_CLOCK_GO));
		m_obj.setSize(sf::Vector2f(30.f, 30.f)); break;
	case gift::SHIELD_GIFT: m_obj.setTexture(Resources::instance().getTexture(gameObjects::SHIELD_GO)); break;
	case gift::LIFE: m_obj.setTexture(Resources::instance().getTexture(gameObjects::LIFE_GO)); 
		m_obj.setSize(sf::Vector2f(30.f, 30.f)); break;
	}
	m_obj.setOrigin(m_obj.getSize() / 2.f);
	
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(loc.x, loc.y);
	bodyDef.linearVelocity = b2Vec2(0.f, 5.f);	
	bodyDef.gravityScale = 1;

	m_body = world->CreateBody(&bodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(m_obj.getSize().x / 2, m_obj.getSize().y / 2);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &groundBox;
	fixtureDef.density = 0.5;
	
	fixtureDef.filter.categoryBits = entity::GIFT;
	fixtureDef.filter.maskBits = entity::PLAYER |entity::BORDER_FLOOR;
	fixtureDef.filter.groupIndex = id_gift++;
	m_fixture = m_body->CreateFixture(&fixtureDef);
	m_obj.setPosition(loc);
}
//=======================================================================================
void Gift::draw(sf::RenderWindow& window) const
{
	window.draw(m_obj);
}
//=======================================================================================
int Gift::getValue() const
{
	return m_value;
}
//=======================================================================================
bool Gift::updateObj() 
{
	auto position = m_body->GetPosition();
	m_obj.setPosition(position.x, position.y);
	m_count_down -= m_Timer.getElapsedTime().asSeconds();
	m_Timer.restart();
	if (m_count_down < 0)
		return false;
	return true;
}
//=======================================================================================
void Gift::restartTimer()
{
	m_Timer.restart();
}
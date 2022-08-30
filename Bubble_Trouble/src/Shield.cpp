#include "Shield.h"

//=======================================================================================
Shield::Shield(b2World* world)
{
	m_count_down = 10.f;
	m_obj.setSize(sf::Vector2f(75.f, 150.f));
	m_obj.setOrigin(m_obj.getSize() / 2.f);
	m_obj.setTexture(Resources::instance().getTexture(gameObjects::SHIELD_GO));
	
	initShield(world);
	
}
//=======================================================================================
void Shield::initShield(b2World* world)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(-5 * STATIC_OBJECT_SIZE_PIXEL, WINDOW_HEIGHT);
	m_body = world->CreateBody(&bodyDef);
	
	b2PolygonShape groundBox;
	groundBox.SetAsBox(m_obj.getSize().x / 2.f, m_obj.getSize().y / 2.f);
	
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &groundBox;
	fixtureDef.filter.categoryBits = entity::SHIELD;
	fixtureDef.filter.maskBits = entity::BALL;
	fixtureDef.filter.groupIndex = id_weapon++;
	m_fixture = m_body->CreateFixture(&fixtureDef);
}
//=======================================================================================
void Shield::activate(const ContactListener& cl, const b2Vec2& pos)
{
	if (m_isActive)
	{
		m_count_down -= m_Timer.getElapsedTime().asSeconds();
		if (m_count_down < 0)
		{
			forceEnd();
			m_count_down = 10.f;
		}
		else
		{
			m_pos = pos;
			m_body->SetTransform(m_pos, m_body->GetAngle());
			m_obj.setPosition(sf::Vector2f(m_pos.x, m_pos.y));
		}
	}
	m_Timer.restart();
}
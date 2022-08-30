#include "LaserWeapon.h"

//=======================================================================================
LaserWeapon::LaserWeapon(b2World* world)
{
	m_obj.setSize(sf::Vector2f(50.f, 15));
	m_obj.setOrigin(m_obj.getSize() / 2.f);
	m_obj.setTexture(Resources::instance().getTexture(gameObjects::LASER_WEAPON_GO));
	//m_obj.setFillColor(sf::Color::Blue);
	initWeapon(world);
}
//=======================================================================================
void LaserWeapon::initWeapon(b2World* world)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(-5 * STATIC_OBJECT_SIZE_PIXEL, WINDOW_HEIGHT);
	m_body = world->CreateBody(&bodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(m_obj.getSize().x / 2.f, m_obj.getSize().y / 2.f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &groundBox;
	fixtureDef.filter.categoryBits = entity::WEAPON;
	fixtureDef.filter.maskBits = entity::BALL | entity::BORDER_CEILING;
	fixtureDef.filter.groupIndex = id_weapon++;
	m_fixture = m_body->CreateFixture(&fixtureDef);
}
//=======================================================================================
void LaserWeapon::activate(const ContactListener& cl, const b2Vec2& pos)
{
	b2Vec2 position = m_body->GetPosition();
	if (position.y < STATIC_OBJECT_SIZE_PIXEL)
		forceEnd();

	//if (cl.isWeaponHitCeiling())
	else if (m_isActive)
	{
		if (!m_isWeaponPosSet)
		{
			m_obj.setPosition(sf::Vector2f(pos.x, pos.y));
			m_body->SetTransform(pos, m_body->GetAngle());
			m_pos = pos;
			m_isWeaponPosSet = true;
		}
		m_body->SetTransform(b2Vec2(m_pos.x, m_pos.y -= 3), m_body->GetAngle());
		m_obj.setPosition(sf::Vector2f(m_pos.x, m_pos.y));
	}
}

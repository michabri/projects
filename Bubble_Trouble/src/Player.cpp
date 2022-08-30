#include "Player.h"

Player::Player(const sf::Vector2f& pos, b2World* world, const int& id_player)
	: m_curr_weapon(0)
{
	m_character.setSize(sf::Vector2f(50.0f, 100.0f));
	initPlayer(pos, world, id_player);

	switch (id_player)
	{
	case flows::BATMAN_FLOW:
		m_animation.setAnimation(Resources::instance().getFlow(flows::BATMAN_FLOW), sf::Vector2u(3, 3), 0.1f);
		m_character.setTexture(Resources::instance().getFlow(flows::BATMAN_FLOW));
		break;
	case flows::ROBIN_FLOW:
		m_animation.setAnimation(Resources::instance().getFlow(flows::ROBIN_FLOW), sf::Vector2u(3, 3), 0.1f);
		m_character.setTexture(Resources::instance().getFlow(flows::ROBIN_FLOW));
		break;
	default:
		break;
	}
	
	m_speed = 200.0f;
	m_row = 1;
	m_faceRight = true;
	m_character.setSize(sf::Vector2f(50.0f, 100.0f));
	m_character.setOrigin(m_character.getSize() / 2.f);
	
	m_weapons.push_back(std::make_unique<NormalWeapon>(world));
	m_weapons.push_back(std::make_unique<HookWeapon>(world));
	m_weapons.push_back(std::make_unique<LaserWeapon>(world));
	m_weapons.push_back(std::make_unique<Shield>(world));

	m_character.setPosition(sf::Vector2f(m_body->GetPosition().x, m_body->GetPosition().y));
	m_animation.Update(1, 0, true);
	m_character.setTextureRect(m_animation.uvRect);
}
//=======================================================================================
void Player::initPlayer(const sf::Vector2f& loc, b2World* world, const int& id_player)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(loc.x, loc.y);
	m_body = world->CreateBody(&bodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(m_character.getSize().x / 2.f, m_character.getSize().y / 2.f);

	b2FixtureDef fixtureDef;

	fixtureDef.shape = &groundBox;
	fixtureDef.filter.groupIndex = id_player;
	fixtureDef.filter.categoryBits = entity::PLAYER;
	fixtureDef.filter.maskBits = entity::BALL | entity::WALL | entity::GIFT | entity::BORDER_FLOOR;

	m_fixture = m_body->CreateFixture(&fixtureDef);
}
//=======================================================================================
void Player::draw(sf::RenderWindow& window) const
{
	for (int i = 0; i < m_weapons.size() - 1 ; i++)
		if(m_weapons[i]->isActive())
			m_weapons[i]->draw(window);
	
	window.draw(m_character);
	
	if (m_weapons[gift::SHIELD_GIFT]->isActive())
		m_weapons[gift::SHIELD_GIFT]->draw(window);
}
//=======================================================================================
void Player::move(ContactListener& cl, std::pair<sf::Vector2f, bool> input, float deltaTime)
{
	m_direction = input.first;
	DirectionImg(input.first.x, deltaTime);

	if (input.second)
	{
		shoot();
		SetStandingImage(1, 1.0f);
	}
	b2Vec2 pos = m_body->GetPosition();
	/*
	(blocked && m_lastDirection == m_direction) ? 
				m_body->SetTransform(b2Vec2(pos.x - m_direction.x, pos.y), m_body->GetAngle()) :
				m_body->SetTransform(b2Vec2(pos.x + m_direction.x, pos.y), m_body->GetAngle());
	*/

	m_body->SetTransform(b2Vec2(pos.x + m_direction.x, pos.y), m_body->GetAngle());
	int index = -1;
	if (cl.isPlayerBlocked(index) && getId() == index && m_lastDirection == m_direction)
	{
		m_body->SetTransform(b2Vec2(pos.x - m_direction.x, pos.y), m_body->GetAngle());
		cl.setBlock();
	}

	if (index == playerHit::BOTH)
	{
		m_body->SetTransform(b2Vec2(pos.x - m_direction.x, pos.y), m_body->GetAngle());
	}
		
	
	pos = m_body->GetPosition();
	m_character.setPosition(pos.x, pos.y);
	m_lastDirection = m_direction;
}
//=======================================================================================
void Player::shoot()
{
	m_weapons[m_curr_weapon]->setActivate();
}
//=======================================================================================
void Player::setShield()
{
	m_weapons[gift::SHIELD_GIFT]->setCountDown(10);
	m_weapons[gift::SHIELD_GIFT]->setActivate();
}
//=======================================================================================
void Player::handlePowers(const ContactListener& cl)
{
	for(int i = 0; i< m_weapons.size(); i++)
		m_weapons[i]->activate(cl, m_body->GetPosition());
}
//=======================================================================================
void Player::ballHit()
{
	m_weapons[m_curr_weapon]->forceEnd();
}
//=======================================================================================
void Player::setCurrWeapon(const int& weapon)
{
	m_curr_weapon = weapon;
}
//=======================================================================================
void Player::SetStandingImage(int image, float deltaTime)
{
	if (image == 0)
	{
		m_row = 1;
		m_animation.Update(m_row, deltaTime, m_faceRight);
		m_character.setTextureRect(m_animation.uvRect);
	}
	else if (image == 1)
	{
		m_row = 0;
		m_animation.Update(m_row, deltaTime, m_faceRight);
		m_character.setTextureRect(m_animation.uvRect);
	}

}
//=======================================================================================
void Player::DirectionImg(int dir, float deltaTime)
{
	if (dir == 1)
	{
		m_faceRight = false;
		m_row = 2;
		m_animation.Update(m_row, deltaTime, m_faceRight);
		m_character.setTextureRect(m_animation.uvRect);

	}
	else if (dir == -1)
	{
		m_faceRight = true;
		m_row = 2;
		m_animation.Update(m_row, deltaTime, m_faceRight);
		m_character.setTextureRect(m_animation.uvRect);

	}
}

#include "ContactListener.h"
#include <iostream>

//=======================================================================================
void ContactListener::BeginContact(b2Contact* contact)
{
	checkBeginCollision(contact, entity::BALL, entity::WEAPON, m_collision_ball_weapon);
	checkBeginCollision(contact, entity::BALL, entity::PLAYER, m_collision_ball_player);
	checkBeginCollisionPlayer(contact, entity::GIFT, entity::PLAYER, m_collision_gift_player);
	checkBeginCollisionPlayer(contact, entity::PLAYER, entity::WALL, m_collision_player_wall);
	checkBeginCollision(contact, entity::WEAPON, entity::BORDER_CEILING, m_collision_weapon_ceiling);
}
//=======================================================================================
void ContactListener::EndContact(b2Contact* contact)
{
	b2Filter fa = contact->GetFixtureA()->GetFilterData();
	b2Filter fb = contact->GetFixtureB()->GetFilterData();

	checkEndCollision(contact, entity::WALL, entity::PLAYER, m_collision_player_wall);
	checkEndCollision(contact, entity::WEAPON, entity::BORDER_CEILING, m_collision_weapon_ceiling);
	checkEndCollision(contact, entity::GIFT, entity::PLAYER, m_collision_gift_player);
	checkEndCollision(contact, entity::BALL, entity::WEAPON, m_collision_ball_weapon);
	
}
//=======================================================================================
bool ContactListener::isWeaponHitBall(int& index) const
{
	index = m_collision_ball_weapon.m_obj_index;
	return m_collision_ball_weapon.m_collision;
}
//=======================================================================================
bool ContactListener::isPlayerHitGift(int& index, int& index_player) const
{
	index = m_collision_gift_player.m_obj_index;
	index_player = m_collision_gift_player.m_player_index;
	return m_collision_gift_player.m_collision;
}
//=======================================================================================
bool ContactListener::isPlayerBlocked(int& index) const
{
	if (m_collision_player_wall.m_collision)
	{
		if (m_collision_player_wall.m_numOfContacts > playerHit::BOTH && m_collision_player_wall.m_numOfContacts <= 2 * playerHit::BOTH)
		{
			index = playerHit::BOTH;
		}
		else
		{
			index = m_collision_player_wall.m_player_index;
		}
		return true;
	}
	return false;
}
//=======================================================================================
bool ContactListener::isBallHitPlayer(int& index) const
{
	index = m_collision_ball_player.m_player_index;
	return m_collision_ball_player.m_collision;
}

//=======================================================================================
bool ContactListener::isWeaponHitCeiling() const
{
	return m_collision_weapon_ceiling.m_collision;
}
//=======================================================================================
void ContactListener::checkBeginCollision(b2Contact* contact,
									 const entity& entity_a, const entity& entity_b, collision& collision)
{
	b2Filter fa = contact->GetFixtureA()->GetFilterData();
	b2Filter fb = contact->GetFixtureB()->GetFilterData();

	if ((fb.categoryBits == entity_a && fa.categoryBits == entity_b) ||
		(fa.categoryBits == entity_a && fb.categoryBits == entity_b))
	{
		collision.m_obj_index = fb.groupIndex;
		collision.m_player_index = fa.groupIndex;
		collision.m_collision = true;
		collision.m_numOfContacts++;
	}
}
//=======================================================================================
void ContactListener::checkBeginCollisionPlayer(b2Contact* contact,
	const entity& entity_a, const entity& entity_b, collision& collision)
{
	b2Filter fa = contact->GetFixtureA()->GetFilterData();
	b2Filter fb = contact->GetFixtureB()->GetFilterData();

	if ((fb.categoryBits == entity_a && fa.categoryBits == entity_b) ||
		(fa.categoryBits == entity_a && fb.categoryBits == entity_b))
	{
		if (fa.categoryBits == entity::PLAYER)
		{
			collision.m_player_index = fa.groupIndex;
			collision.m_obj_index = fb.groupIndex;
		}
		else
		{
			collision.m_player_index = fb.groupIndex;
			collision.m_obj_index = fa.groupIndex;
		}
		collision.m_collision = true;
		collision.m_numOfContacts++;
	}
}
//=======================================================================================
void ContactListener::checkEndCollision(b2Contact* contact,
	const entity& entity_a, const entity& entity_b, collision& collision)
{
	b2Filter fa = contact->GetFixtureA()->GetFilterData();
	b2Filter fb = contact->GetFixtureB()->GetFilterData();

	if ((fb.categoryBits == entity_a && fa.categoryBits == entity_b) ||
		(fa.categoryBits == entity_a && fb.categoryBits == entity_b))
	{
		collision.m_player_index = -1;
		collision.m_obj_index = -1;
		collision.m_collision = false;
		collision.m_numOfContacts--;
	}
}
//=======================================================================================
void ContactListener::restartFlags()
{
	m_collision_ball_player.reset();
	m_collision_player_wall.reset();
	m_collision_ball_weapon.reset();
	m_collision_gift_player.reset();
	m_collision_weapon_ceiling.reset();
}

void ContactListener::setBlock()
{
	m_collision_player_wall.m_collision = false;
}
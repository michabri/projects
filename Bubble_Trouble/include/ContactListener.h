#pragma once

#include "macros.h"

enum playerHit
{
	NONE = -1,
	P_ONE,
	P_TWO,
	BOTH,
};

class ContactListener : public b2ContactListener
{
public:
	virtual void BeginContact(b2Contact* contact) override;
	virtual void EndContact(b2Contact* contact) override;

	bool isWeaponHitBall(int &index) const;
	bool isPlayerHitGift(int& index, int& index_player) const;
	bool isBallHitPlayer(int& index) const;
	bool isPlayerBlocked(int& index) const;
	//int setPlayerBlock(b2Contact* contact);
	bool isWeaponHitCeiling() const;
	void restartFlags();
	void setBlock();

private:
	struct collision
	{
		bool m_collision = false;
		int m_obj_index = -1;
		int m_player_index = -1;
		int m_numOfContacts = 0;

		void reset()
		{
			m_collision = false;
			m_obj_index = -1;
			m_player_index = -1;
			m_numOfContacts = 0;
		}
	};
	
	void checkBeginCollision(b2Contact* contact,
		const entity& entity_a, const entity& entity_b, collision& collision);

	void checkBeginCollisionPlayer(b2Contact* contact,
		const entity& entity_a, const entity& entity_b, collision& collision);

	void checkEndCollision(b2Contact* contact,
		const entity& entity_a, const entity& entity_b, collision& collision);
	
	collision m_collision_ball_weapon;
	collision m_collision_gift_player;
	collision m_collision_player_wall;
	collision m_collision_ball_player;
	collision m_collision_weapon_ceiling;
};
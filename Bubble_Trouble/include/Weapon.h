#pragma once
#include "StaticObject.h"

static int id_weapon = 0;

class Weapon : public StaticObject
{
public:
	using StaticObject::StaticObject;
	bool isActive() const;
	void setActivate();
	void forceEnd();
	void setCountDown(const float& cd);
	virtual void activate(const ContactListener& , const b2Vec2& ) = 0;
	virtual void draw(sf::RenderWindow& window) const override;

protected:
	bool m_isActive = false ;
	bool m_isWeaponPosSet = false ;
	float m_count_down;
	sf::Clock m_Timer;
	b2Vec2 m_pos;

};
#pragma once
#include "Weapon.h"

class HookWeapon : public Weapon 
{
public:
	using Weapon::Weapon;
	HookWeapon(b2World * world);
	virtual void activate(const ContactListener& cl, const b2Vec2&) override;
	virtual int getValue() const override { return 0; }

private:
	void initWeapon(b2World* world);
};
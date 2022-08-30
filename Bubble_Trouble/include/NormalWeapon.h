#pragma once
#include "Weapon.h"

class NormalWeapon : public Weapon 
{
public:
	using Weapon::Weapon;
	NormalWeapon(b2World* world);
	virtual void activate(const ContactListener& cl, const b2Vec2& pos) override;
	virtual int getValue() const override { return 0; }

private:
	void initWeapon(b2World* world);
};
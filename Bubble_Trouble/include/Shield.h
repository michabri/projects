#pragma once
#include "Weapon.h"

class Shield : public Weapon
{
public:
	using Weapon::Weapon;
	Shield(b2World* world);
	virtual void activate(const ContactListener& cl, const b2Vec2& pos) override;
	virtual int getValue() const override { return 0; }

private:
	void initShield(b2World* world);
	
};
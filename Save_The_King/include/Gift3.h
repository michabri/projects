#pragma once
#include "Gift.h"

class Gift3 : public Gift
{
public:
	using Gift::Gift;
	virtual void handleCollision(const GameObject& character) override;
	virtual void handleCollision(const King& king) override;
	virtual void handleCollision(const Mage& mage) override;
	virtual void handleCollision(const Warrior& warrior) override;
	virtual void handleCollision(const Thief& thief) override;
	virtual void handleCollision(const Gnome& gnome) override;

private:
};
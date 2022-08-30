#pragma once
#include "StaticObject.h"
#include "Thief.h"

class Gate : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(const GameObject& character) override;
	virtual void handleCollision(const King& king) override;
	virtual void handleCollision(const Mage& mage) override;
	virtual void handleCollision(const Warrior& warrior) override;
	virtual void handleCollision(const Thief& thief) override;
	virtual void handleCollision(const Gnome& gnome) override;

private:
};
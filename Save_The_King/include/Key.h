#pragma once
#include "StaticObject.h"
#include "Thief.h"

class Key : public StaticObject
{
public:
	using StaticObject::StaticObject;
	virtual void handleCollision(const GameObject& character) override;
	virtual void handleCollision(const King& character) override;
	virtual void handleCollision(const Mage& character) override;
	virtual void handleCollision(const Warrior& character) override;
	virtual void handleCollision(const Thief& character) override;
	virtual void handleCollision(const Gnome& character) override;

private:
};
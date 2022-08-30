#pragma once
#include "MovingObject.h"

class Warrior : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual void handleCollision(GameObject& character) override;

private:
};
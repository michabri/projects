#pragma once
#include "MovingObject.h"

class Mage : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual void handleCollision(GameObject& character) override;

private:
};
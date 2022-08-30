#pragma once
#include "MovingObject.h"

class King : public MovingObject
{
public:
	using MovingObject::MovingObject;
	virtual void handleCollision(GameObject& character) override;
	
private:
};
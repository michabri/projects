#pragma once
#include "MovingObject.h"

class Thief : public MovingObject
{
public:
	using MovingObject::MovingObject;
	bool hasKey() const;
	void setKey();

	virtual void handleCollision(GameObject& character) override;
	
private:
	bool m_key= false;
};
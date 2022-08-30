#pragma once
#include "GameObject.h"

class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	Collisions getCollision();
	
	virtual void handleCollision(const Fire&) override {}
	virtual void handleCollision(const Gate&) override {}
	virtual void handleCollision(const Gift1&) override {}
	virtual void handleCollision(const Gift2&) override {}
	virtual void handleCollision(const Gift3&) override {}
	virtual void handleCollision(const Key&) override {}
	virtual void handleCollision(const Ogre&) override {}
	virtual void handleCollision(const Teleport&) override {}
	virtual void handleCollision(const Throne&) override {}
	virtual void handleCollision(const Wall&) override {}
	virtual ~StaticObject() = default;

protected:
	Collisions m_collision ;
};
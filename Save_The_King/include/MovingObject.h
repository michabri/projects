#pragma once
#include "GameObject.h"

class MovingObject : public GameObject
{
public:
	using GameObject::GameObject;
	virtual void setDirection(const sf::Keyboard::Key& key);
	void rotateSprite(const float& new_width_sclae, const float& new_height_sclae);
	void move(sf::Time deltaTime);
	bool isOnTeleport() const;
	bool isRightPressed() const;
	void setIsOnTeleport(const bool& is_on);
	
	virtual void handleCollision(const GameObject&) = 0;
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
	virtual ~MovingObject() = default;

protected:
	sf::Vector2f m_direction;
	float m_speed_per_second = 150.f;
	bool m_is_on_teleport = false;
	bool m_right_pressed = false;
};
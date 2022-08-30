#pragma once
#include "macros.h"
class King;
class Mage;
class Warrior;
class Thief;
class Gnome;
class Fire;
class Gate;
class Gift1;
class Gift2;
class Gift3;
class Key;
class Ogre;
class Teleport;
class Throne;
class Wall;

class GameObject
{
public:
	GameObject(const sf::Vector2f& loc, const sf::Texture *texture); 
	void setSpriteScale(const float& new_width_scale, const float& new_height_sclae);
	void draw(sf::RenderWindow& window) const;
	bool checkCollision(const GameObject& other);
	void setLocation(const sf::Vector2f& loc);
	void setTexture(const sf::Texture* texture);
	const sf::Vector2f& getLocation() const;
	sf::FloatRect getGlobalBoundsSprite() const;
	sf::Vector2f getScaleSprite() const;
	virtual ~GameObject() = default;

	virtual void handleCollision(const GameObject&) = 0;
	virtual void handleCollision(const King&) = 0;
	virtual void handleCollision(const Mage&) = 0;
	virtual void handleCollision(const Warrior&) = 0;
	virtual void handleCollision(const Thief&) = 0;
	virtual void handleCollision(const Gnome&) = 0;
	virtual void handleCollision(const Fire&) = 0;
	virtual void handleCollision(const Gate&) = 0;
	virtual void handleCollision(const Gift1&) = 0;
	virtual void handleCollision(const Gift2&) = 0;
	virtual void handleCollision(const Gift3&) = 0;
	virtual void handleCollision(const Key&) = 0;
	virtual void handleCollision(const Ogre&) = 0;
	virtual void handleCollision(const Teleport&) = 0;
	virtual void handleCollision(const Throne&) = 0;
	virtual void handleCollision(const Wall&) = 0;
	
protected:
	sf::Sprite m_sprite;
};
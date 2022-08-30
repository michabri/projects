#pragma once
#include "MovingObject.h"
#include "NormalWeapon.h"
#include "HookWeapon.h"
#include "LaserWeapon.h"
#include "Animation.h"
#include "Shield.h"


class Player : public MovingObject
{
public:
	using MovingObject::MovingObject;
	Player(const sf::Vector2f& pos, b2World* world, const int& numOfPlayers);

	void move(ContactListener& cl, std::pair<sf::Vector2f, bool> input, float deltaTime);
	void DirectionImg(int dir, float deltaTime);
	void SetStandingImage(int image, float deltaTime);
	void shoot();
	void setShield();
	void handlePowers(const ContactListener& cl);
	void ballHit();
	
	virtual void draw(sf::RenderWindow& window) const override;
	void setCurrWeapon(const int& weapon);
	
private:
	void initPlayer(const sf::Vector2f& loc, b2World* world, const int& numOfPlayers);

	sf::RectangleShape m_character;
	Animation m_animation;
	unsigned int m_row = 1;
	float m_speed = 0.0f;
	bool m_faceRight = true;

	std::vector< std::unique_ptr<Weapon> > m_weapons;
	int m_curr_weapon;
};
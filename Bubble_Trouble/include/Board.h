#pragma once

#include <iostream>
#include <fstream>
#include "macros.h"
#include "GameObject.h"
#include "StaticObject.h"
#include "Wall.h"
#include "Gift.h"
#include "Ball.h"
#include "ContactListener.h"
#include "Gate.h"


class Board 
{
public:
	Board() = default;
	void setBoard(std::string name_level, b2World* world);
	bool checkAllBallsCleared() const;
	int addGift(const sf::Vector2f& loc, b2World* world);
	void addGift(const sf::Vector2f& loc, b2World* world, int type);
	bool checkSplit(ContactListener& cl, b2World* world, playerData& onlineData);
	bool checkHitGift(ContactListener& cl, b2World* world, int& value, int& index_player);
	void checkAllBallsToTheRightAndDownGone(b2World* world);
	void updateObjects(b2World* world);
	void restartTimers();
	void draw(sf::RenderWindow& window);
	void clearBoard();
	void usingSocket(bool isHost);

	~Board() = default;

private:
	void buildFloor(b2World* world);
	void buildCeiling(b2World* world);
	void createObject(b2World* world);
	sf::Vector2f resizeObject();

	int m_rows = 0;
	int m_cols = 0;
	int m_num_gates = 0;
	std::vector<std::string> m_board;
	std::vector<std::unique_ptr<Ball>> m_balls;
	std::vector<std::unique_ptr<StaticObject>> m_static_objects;
	
	//floor
	sf::RectangleShape m_floor;
	b2Body* m_body_floor;
	b2Fixture* m_fixture_floor;

	//ceiling
	sf::RectangleShape m_ceiling;
	b2Body* m_body_ceiling;
	b2Fixture* m_fixture_ceiling;

	bool m_usingSocket = false;
	bool m_host = false;
};
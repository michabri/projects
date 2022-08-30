#pragma once
#include <iostream>
#include <fstream>
#include "Board.h"
#include "Player.h"
#include "Ball.h"
#include "Wall.h"
#include "Caption.h"
#include "ContactListener.h"

class Controller 
{
public:
	Controller() = default;
	Controller(const int& num_of_players);
	Controller(Socket* socket, bool isHost);
	void run(sf::RenderWindow& window);

private:
	void setLevel();
	bool eventHandler(sf::Event& event, sf::RenderWindow& window);
	bool checkCollisions(sf::RenderWindow& window, sf::Event event);
	bool checkLivesPlayers();
	bool checkTimeOver(sf::RenderWindow& window);
	bool pauseMenu(sf::RenderWindow& window);
	std::pair<sf::Vector2f, bool> getInput(int playerId);
	sf::Vector2f directionInput(int playerId);
	bool shootingInput(int playerId);
	void movementManger(float deltaTime);
	void setMusic(const bool& returtn_menu);
	
	Board m_board;
	std::vector<std::unique_ptr<Player>> m_players; 
	ContactListener m_cl;
	Caption m_caption;

	b2Vec2 m_garvity = b2Vec2(0.f, 10.0f);
	std::unique_ptr<b2World> m_world;

	float m_timeStep = 1.f / 60.0f;
	int32 m_velocityIterations = 6;
	int32 m_positionIterations = 2;
	

	std::fstream m_file_levels;
	bool m_new_level = true;
	bool m_end_game = false;
	std::string m_curr_level;

	int m_numOfPlayers;
	int m_ball_hit = false;

	Socket* m_socket;
	bool m_usingSocket = false;
	bool m_isHost = false;

	playerData m_onlineData;
	std::pair<sf::Vector2f, bool> getOnlineInput();
};
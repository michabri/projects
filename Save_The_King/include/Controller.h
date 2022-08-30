#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include "Board.h"
#include "InfoLine.h"
#include "macros.h"
#include "Singleton.h"

class Controller {
public:
	Controller(sf::RenderWindow& window);
	void run();
	~Controller();

private:
	void setPauseMessage();
	void setLevel();
	void setRectPlayer();
	void nextCharacter();
	void manageCollision(sf::Time& deltaTime, sf::Clock& clock);
	void collisionWithBoundaries(const sf::Vector2f& last_location);
	void collisionWithCharacters(const sf::Vector2f& last_location);
	void collisionWithStasticObjects(const sf::Vector2f& last_location);
	void eraseStaticObject(StaticObject& static_object);
	//void createSound();
	void eraseGnomes();

	Board m_board;
	InfoLine m_info_line;
	sf::RenderWindow* m_window;
	std::vector< std::unique_ptr <MovingObject > > m_characters;
	std::vector< std::unique_ptr <StaticObject > > m_static_objects;
	std::vector < sf::Clock > m_clock_gnomes;
	//std::vector <std::unique_ptr <sf::Sound > > m_sounds;
	bool m_is_playing;
	bool m_new_level;
	bool m_end_game;
	std::string m_curr_level;
	std::fstream m_file_levels;
	sf::Text m_pause_message;
	int m_curr_character;
	sf::RectangleShape m_rect_player;
};


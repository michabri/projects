#pragma once
#include <string>
#include "macros.h"
#include "Resources.h"

class Caption
{
public:
	Caption();
	~Caption();

	void updateTime(float timeToAdd,const bool& new_level); // add amount of time to the timer
	void updateLevel(); // increase the level
	void updateLives(const int& lives, const int& player);
	void setNumOfPlayers(const int& num_of_players);

	int getLevel() const; // get current level
	float getTime() const; //get current time left
	int getLives(const int& id) const;
	bool isAlive(const int& id) const;
	void resetTime(); // reset the timer to 0
	void draw(sf::RenderWindow&);
	

	// print an end messege ( next level / lose / victory)
	void printMessege(const sf::String text, sf::RenderWindow& window, const bool &time_based);

	int handleClick(const sf::Vector2f location);

private:

	bool clicked(int index, const sf::Vector2f location);


	// set the text settings and set the position based on i
	void setText(sf::Text& text, int i);
	void setLivesRect(const int& index);

	sf::Clock m_Timer;
	float m_stageTime;
	int m_level;
	std::vector<int> m_lives;
	std::vector<bool> m_alive;

	sf::Text m_stageTimeText;
	sf::Text m_levelText;
	std::vector<sf::Text> m_liveText;
	std::vector<std::vector<sf::RectangleShape>> m_lives_rect;

};
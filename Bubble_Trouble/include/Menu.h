#pragma once

#include "Controller.h"
#include "Button.h"
#include "macros.h"

class Menu
{
public:
	Menu();
	void run(); // run the menu 
	void draw(); 

private:

	// this function will handle clicks on the buttons
	void handleButtons(const sf::Vector2f& location);

	// this function will handle when the mouse hovers over a button.
	void handleHover(const sf::Vector2f& location);  

	// this function is getting events from the user.
	void eventsHandler();

	void initButtons();

	void initMultiplayerTexts();
	void hostWaitMenu();
	std::string getIp();

	sf::RenderWindow m_window; 
	std::vector<std::string> m_buttonsTexts = { "Start game", "Help", "Exit" };
	std::vector<std::string> m_gameModeTexts = { "Solo", "Dou", "Multiplayer" ,"Back" };
	std::vector<std::string> m_multiplayerTexts = { "Host", "Connect", "Back"};

	std::vector<Button> m_buttons; // menu buttons
	std::vector<Button> m_gameModeButtons; // menu buttons
	std::vector<Button> m_multiplayerButtons;

	bool m_need_help; // check if 'HELP' is pressed
	bool m_gameOn; // check if 'START GAME' is pressed
	bool m_multiplayer;
	int m_lastHover = 0; // last button hovered over
	int m_lastHoverGM = 0;
	int m_lastHoverMulti = 0;

	sf::RectangleShape m_help_bar;
	sf::Sprite m_bg; // menu background

	Socket m_socket;
	sf::Text m_head;
	sf::Text m_ipInput;
};
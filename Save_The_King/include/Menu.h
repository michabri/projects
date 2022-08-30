#pragma once
#include <string>
#include <vector>
#include "macros.h"
#include "Singleton.h"
#include "Controller.h"
#include "Button.h"

class Menu
{
public:
	Menu();
	void run();

private:
	void doButton(const int index, bool& instruction_pressed);
	void drawButtons();

	Controller m_controller;
	sf::RenderWindow m_window;
	Button m_buttons[NUM_OF_BUTTONS];
};
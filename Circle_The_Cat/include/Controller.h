#pragma once
#include <iostream>
#include <stdlib.h>
#include "macros.h"
#include "Board.h"
#include "Singleton.h"
#include "Cat.h"
#include "InfoLine.h"

class Controller 
{
public:
	Controller();
	void run();

private:
	bool checkLose() const;
	void redoLevel();

	sf::RenderWindow m_window;
	Board m_board;
	Cat m_cat;
	InfoLine m_info_line;
};
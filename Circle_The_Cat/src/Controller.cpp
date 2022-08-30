#include "Controller.h"

//-------------------------------------------------------------------------
Controller::Controller() 
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "BOARD GAME")
{}
//-------------------------------------------------------------------------
void Controller::run() 
{
	//initialize before the game start
	auto level = 1;
	m_board.randomizeBoard(level);
	sf::Sprite level_up_sprite(*Singleton::instance().getLevelUp());
	sf::Sprite lost_level_sprite(*Singleton::instance().getLostLevel());
	sf::Sprite game_over_sprite(*Singleton::instance().getGameOver());
	bool won_level = false;
	bool lost_level = false;

	while (m_window.isOpen()) 
	{
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
				{
					m_window.close();
					break;
				}
				
				case sf::Event::MouseButtonReleased:
				{
					auto mouse_click_loc = sf::Mouse::getPosition(m_window);
					Location player_action(-1, -1);
					
					if(won_level && level == 3)
						m_window.close();
					
					else if (won_level)
					{
						level++;
						won_level = false;
						m_info_line.newLevel();
						m_board.randomizeBoard(level);
						m_cat.setLocation(Location((int)BOARD_SIZE / 2, (int)BOARD_SIZE / 2));
					}
				
					else if (lost_level)
					{
						redoLevel();
						lost_level = false;
					}
					
					else if (m_board.handleClick((sf::Vector2f)mouse_click_loc, m_cat.getLocation(), player_action))
					{
						m_info_line.addPlayerAction(player_action);
						if (checkLose())
							lost_level = true;
						else
						{
							Location cat_movement = m_board.getNextCatLocation(m_cat.getLocation());
							if (cat_movement.row != -1)
							{
								m_info_line.addCatMovement(cat_movement);
								m_cat.setLocation(cat_movement);
							}
							else
								won_level = true;
						}
						m_info_line.addNumClicks(1);
					}
					
					else if (m_info_line.handleClick((sf::Vector2f)mouse_click_loc))
					{
						Location last_cat_loc = m_info_line.getLastCatMovement();
						Location last_player_action = m_info_line.getLastPlayerAction();
						if (last_cat_loc.row != -1)
							m_cat.setLocation(last_cat_loc);
						if (last_player_action.row != -1)
						{
							m_board.undoTile(last_player_action);
							m_info_line.addNumClicks(-1);
						}
					}
				}
				break;
			}
		}

		m_window.clear(sf::Color::White);
		if (won_level && level == 3)
			m_window.draw(game_over_sprite);
		else if (won_level)
			m_window.draw(level_up_sprite);
		else if (lost_level)
			m_window.draw(lost_level_sprite);
		else
		{
			m_board.draw(m_window);
			m_cat.draw(m_window);
			m_info_line.draw(m_window);
		}
		m_window.display();
	}
}
//-------------------------------------------------------------------------
bool Controller::checkLose() const
{
	if (m_cat.getLocation().row == 0 || m_cat.getLocation().row == BOARD_SIZE - 1 ||
		m_cat.getLocation().col == 0 || m_cat.getLocation().col == BOARD_SIZE - 1)
		return true;
	return false;
}
//-------------------------------------------------------------------------
void Controller::redoLevel()
{
	Location action_loc = m_info_line.getLastPlayerAction();
	while (action_loc.row != -1)
	{
		m_board.undoTile(action_loc);
		m_info_line.addNumClicks(-1);
		action_loc = m_info_line.getLastPlayerAction();
	}
	Location cat_movement = m_info_line.getLastCatMovement();
	while (cat_movement.row != -1)
		cat_movement = m_info_line.getLastCatMovement();
	m_info_line.addCatMovement(Location((int)BOARD_SIZE / 2, (int)BOARD_SIZE / 2));
	m_cat.setLocation(Location((int)BOARD_SIZE / 2, (int)BOARD_SIZE / 2));
}
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//-------------------------------------------------------------------------
//Window related
constexpr auto WINDOW_WIDTH = 1600;
constexpr auto WINDOW_HEIGHT = 800;
//-------------------------------------------------------------------------
//Menu related
constexpr auto NUM_OF_BUTTONS = 3;
constexpr auto BUTTON_SIZE_WIDTH = 300;
constexpr auto BUTTON_SIZE_HEIGHT = 80;
constexpr auto NUM_OF_MENU_PICS = 3;
//-------------------------------------------------------------------------
//Board related
constexpr auto BOARD_WIDTH = 1600;
constexpr auto BOARD_HEIGHT = 650;
constexpr auto NUM_OF_OBJECT_PICS = 14;
constexpr auto CHARACTERS = 4;
constexpr auto OBJECT_SIZE_PIXEL = 100;
constexpr auto NUM_OF_SOUNDS = 12;
//-------------------------------------------------------------------------
//Clock related
constexpr auto ADD_TIME = 5.f;
//-------------------------------------------------------------------------
enum MenuPics
{
	MENU_BACKGROUND_PIC, INSTRUCTION_PIC , CONTROLLER_PIC
};
//-------------------------------------------------------------------------
enum MenuButtons
{
	START, INSTRUCTIONS, EXIT
};
//-------------------------------------------------------------------------
enum Objects
{
	KING, MAGE, WARRIOR, THIEF, THIEF_KEY, OGRE, KEY, TELEPORT, FIRE, 
	THRONE, WALL, GATE, GNOME, GIFT
};
//-------------------------------------------------------------------------
enum class Collisions
{
	NO_COLLISION, REGULAR_COLLISION, KEY, GATE, FIRE, OGRE, WON, TELEPORT,
	GIFT1, GIFT2, GIFT3
};
//-------------------------------------------------------------------------
const std::string MENU_BUTTONS_TEXT[NUM_OF_BUTTONS] = { "Start", 
														"Instructions", 
														"Exit" 
													   };
//-------------------------------------------------------------------------
const std::string OBJECT_TEXTURES[NUM_OF_OBJECT_PICS] = { 
												   "king.png", 
												   "mage.png", 
												   "warrior.png", 
												   "thief.png",
												   "thiefKey.png",
												   "ogre.png",
												   "key.png",
												   "portal.png",
												   "fire.png", 
												   "throne.png", 
												   "wall.png",
												   "gate.png", 
												   "gnome.png",
												   "gift.png"
												   };
//-------------------------------------------------------------------------
const std::string MENU_TEXTURES[NUM_OF_MENU_PICS] = { "bg_menu.jpg",
													  "instructions.png",
													  "bg_controller.jpg"
													};
//-------------------------------------------------------------------------
enum Sounds
{
	TELEPORT_SOUND, OGRE_SOUND, THRONE_SOUND, WALL_SOUND, FIRE_SOUND, KEY_SOUND, 
	GATE_SOUND, SWITCH_SOUND, START_SOUND, GOOD_GIFT_SOUND, BAD_GIFT_SOUND, REMOVE_GNOME_SOUND
};
//-------------------------------------------------------------------------
const std::string sound_names[NUM_OF_SOUNDS] = { "teleport.wav",
												 "sword.wav",
												 "victory.wav",
												 "bump.wav",
												 "magic.wav",
												 "key.wav",
												 "gate.wav",
												 "switch.wav",
												 "begin.wav",
											     "goodgift.wav",
												 "badgift.wav",
												 "removegnome.wav"
};
//-------------------------------------------------------------------------

#pragma once
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include "macros.h"

class Singleton {
public:
	~Singleton();
	static Singleton& instance();
	sf::Sprite getMenuSprite(const int index) const;
	sf::Texture* getObjectTexture(const int index);
	sf::Font* getFont();
	void playSound(const int index);
	void playMusic();

private:
	Singleton();
	Singleton(const Singleton&) = default;
	Singleton& operator=(const Singleton&) = default;
	
	void loadSounds();
	void loadTexturesObjects();
	void loadMenuPictures();
	void loadFont();
	
	sf::SoundBuffer m_buffer[NUM_OF_SOUNDS];
	sf::Sound m_sound[NUM_OF_SOUNDS];
	sf::Texture m_textures_menu[NUM_OF_MENU_PICS];
	sf::Texture m_textures_objects[NUM_OF_OBJECT_PICS];
	sf::Font m_font;
	sf::Music m_music;
};
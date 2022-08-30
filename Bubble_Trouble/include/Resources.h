#pragma once

#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "macros.h"


class Resources
{
public:
	~Resources();
	static Resources& instance();

	sf::Texture* getTexture(int i);
	sf::Texture* getBackground(int index);
	sf::Texture* getFlow(int index);
	sf::RectangleShape* getPauseButtons(int index);
	sf::Font* getFont();
	void drawPauseScreen(sf::RenderWindow& window);
	void setMusic(const int& index, const bool& returtn_menu);
	void playSound(int index);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator=(const Resources&) = default;

	std::vector<sf::SoundBuffer> m_buffers;
	std::vector<sf::Sound> m_sounds;
	sf::Music m_background_song;
	sf::Music m_menu_song;

	void loadTextures();
	void loadSounds();
	void setPauseScreen();
	void SetButtons();

	sf::RectangleShape m_pauseWindow;
	std::vector<sf::RectangleShape> m_pauseButtons;
	sf::Text m_pauseText;

	std::vector<sf::Texture> m_pauseTextures;
	std::vector<sf::Texture> m_textures_objects;
	std::vector < sf::Texture > m_bg;
	std::vector < sf::Texture > m_flows;
	
	sf::Font m_font;
	bool musicOn[2] = { false };

	const std::vector<std::string> m_string_button_textures = 
	{ 
		"home-button.png" , 
		"restart-button.png" , 
		"music-button.png" 
	};

	const std::vector<std::string> m_string_buffers = 
	{
		"GTA_WASTED.wav",
		"GAME_OVER.wav"
	};
	
	const std::vector<std::string> m_string_music =
	{
		"BACKGROUND_SONG.wav",
		"MENU_SONG.wav"
	};

	const std::vector<std::string> m_string_background_textures =
	{
		"menu-background.jpg",
		"instructions.jpg",
		"faded_background.jpeg"
	};

	const std::vector<std::string> m_string_object_textures = 
	{
		"red_ball.png", 
		"wall.png", 
		"gate.png",
		"purple_ball.png",
		"blue_ball.png",
		"orange_ball.png",
		"arrow.png",
		"hookWeapon.png",
		"laser.png",
		"green-clock.png",
		"red-clock.png",
		"shield.png",
		"life.png",
		"x-lives.png",
		"regular-weapon.png",
		"hook-weapon.png",
		"quick-weapon.png"
	};

	const std::vector<std::string> m_string_flows =
	{
		"batman-flow.png",
		"robin-flow.png"
	};
};


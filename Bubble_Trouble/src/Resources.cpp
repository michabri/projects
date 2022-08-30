#include "Resources.h"

Resources::Resources()
{
	try {
		m_font.loadFromFile("font.ttf");
		loadTextures();
		loadSounds();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	setPauseScreen();
	
}
//=======================================================================================
Resources::~Resources() 
{
}
//=======================================================================================
Resources& Resources::instance()
{
	static Resources inst;
	return inst;
}
//=======================================================================================
void Resources::setPauseScreen()
{
	m_pauseWindow.setFillColor(sf::Color(179, 218, 255, 255));
	m_pauseWindow.setPosition(sf::Vector2f(600, 250));
	m_pauseWindow.setSize(sf::Vector2f(340, 230));
	m_pauseWindow.setOutlineThickness(3);
	m_pauseWindow.setOutlineColor(sf::Color::Black);
	auto buttonSize = sf::Vector2f(30, 30);
	auto buttonPos = sf::Vector2f(550, 450);

	m_pauseText.setFont(m_font);
	m_pauseText.setString("Pause");
	m_pauseText.Bold;
	m_pauseText.setOutlineColor(sf::Color(12, 36, 97, 255));
	m_pauseText.setOutlineThickness(3);
	m_pauseText.setCharacterSize(80);
	m_pauseText.setColor(sf::Color(29, 209, 161, 255));
	m_pauseText.setPosition(sf::Vector2f(660, 260));
	SetButtons();
}

//=======================================================================================
void Resources::SetButtons()
{
	m_pauseButtons.resize(m_string_button_textures.size());
	for (int i = 0; i < m_string_button_textures.size(); i++)
	{
		m_pauseButtons[i].setTexture(&m_pauseTextures[i]);
		m_pauseButtons[i].setSize(sf::Vector2f(90, 90));
		m_pauseButtons[i].setPosition(sf::Vector2f(620 + i * 100, 380));
	}
	m_pauseButtons[MUSIC].setOutlineThickness(4);
	m_pauseButtons[MUSIC].setOutlineColor(sf::Color::Green);
}

//=======================================================================================
void Resources::loadTextures()
{
	m_textures_objects.resize(m_string_object_textures.size());
	m_pauseTextures.resize(m_string_button_textures.size());
	m_bg.resize(m_string_background_textures.size());
	m_flows.resize(m_string_flows.size());

	for (int i = 0; i < m_string_object_textures.size(); i++)
		m_textures_objects[i].loadFromFile(m_string_object_textures[i]);

	for (int i = 0; i < m_string_button_textures.size(); i++)
		m_pauseTextures[i].loadFromFile(m_string_button_textures[i]);

	for (int i = 0; i < m_string_background_textures.size(); i++)
		m_bg[i].loadFromFile(m_string_background_textures[i]);

	for (int i = 0; i < m_string_flows.size(); i++)
		m_flows[i].loadFromFile(m_string_flows[i]);

}
//=======================================================================================
sf::Texture* Resources::getTexture(int index)
{
	return &m_textures_objects[index];
}

//=======================================================================================
sf::Texture* Resources::getBackground(int index)
{
	return &m_bg[index];
}
//=======================================================================================
sf::Texture* Resources::getFlow(int index)
{
	return &m_flows[index];
}
//=======================================================================================
sf::RectangleShape* Resources::getPauseButtons(int index)
{
	return &m_pauseButtons[index];
}
//=======================================================================================
void Resources::loadSounds()
{
	m_buffers.resize(m_string_buffers.size());
	m_sounds.resize(m_string_buffers.size());
	for (int i = 0; i < m_string_buffers.size(); i++)
	{
		m_buffers[i].loadFromFile(m_string_buffers[i]);
		m_sounds[i].setBuffer(m_buffers[i]);
		m_sounds[i].setVolume(15.f);
	}
	m_background_song.openFromFile(m_string_music[music_song::BACKGROUND_SONG]);
	m_background_song.setVolume(10.f);
	m_menu_song.openFromFile(m_string_music[music_song::MENU_SONG]);
	m_menu_song.setVolume(10.f);
	
}

//=======================================================================================
void Resources::playSound(int index)
{
	m_sounds[index].play();
}
//=======================================================================================
void Resources::drawPauseScreen(sf::RenderWindow& window)
{
	window.draw(m_pauseWindow);
	window.draw(m_pauseText);
	for (int i = 0; i < 3; i++)
	{
		window.draw(m_pauseButtons[i]);
	}
}

//=======================================================================================
sf::Font* Resources::getFont()
{
	return &m_font;
}

//=======================================================================================
void Resources::setMusic(const int& index, const bool& returtn_menu)
{
	if (!musicOn[index])
	{
		switch (index)
		{
		case music_song::BACKGROUND_SONG:
			if (!returtn_menu)
			{
				m_background_song.play();
				m_pauseButtons[MUSIC].setOutlineColor(sf::Color::Green);
			}
			break;
		case music_song::MENU_SONG: m_menu_song.play(); break;
		}
		musicOn[index] = true;
		return;
	}
	switch (index)
	{
	case music_song::BACKGROUND_SONG: 
		m_background_song.pause(); 
		m_pauseButtons[MUSIC].setOutlineColor(sf::Color::Red); 
		break;
	case music_song::MENU_SONG: m_menu_song.pause(); break;
	}
	musicOn[index] = false;
}
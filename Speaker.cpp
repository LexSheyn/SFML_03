#include "stdafx.h"
#include "Speaker.h"

//Private functions
void Speaker::initVariables()
{
	this->trackNumberMax = 0;
	this->trackNumber = 0;
}

void Speaker::initSound(std::string buffer_name, std::string sound_name, std::string file_path)
{
	if (!this->buffers[buffer_name].loadFromFile(file_path))
	{
		std::cout << "ERROR::SPEAKER::INITSOUND::Failed to load " << file_path;
	}

	this->sounds[sound_name].setBuffer(this->buffers[buffer_name]);
}

//Constructors and Distructors
Speaker::Speaker()
{	
	//Init variables
	this->initVariables();

	//Init sounds
	this->initSound("blaster_buffer", "blaster", "../Sounds/Sounds/blaster.ogg");
	this->initSound("player_impact_01_buffer", "player_impact_01", "../Sounds/Sounds/player_impact_01.ogg");
	this->initSound("player_impact_02_buffer", "player_impact_02", "../Sounds/Sounds/player_impact_02.ogg");
	this->initSound("player_impact_03_buffer", "player_impact_03", "../Sounds/Sounds/player_impact_03.ogg");
	this->initSound("heal_buffer", "heal", "../Sounds/Sounds/heal.ogg");
	this->initSound("game_over_buffer", "game_over", "../Sounds/Sounds/game_over.ogg");
	this->initSound("menu_open_buffer", "menu_open", "../Sounds/Sounds/menu_open.ogg");
	this->initSound("menu_click_buffer", "menu_click", "../Sounds/Sounds/menu_click.ogg");
	this->initSound("menu_highlight_buffer", "menu_highlight", "../Sounds/Sounds/menu_highlight.ogg");
}

Speaker::~Speaker()
{

}

//Accessors
sf::SoundSource::Status Speaker::getMusicStatus(std::string music_name)
{
	return this->music[music_name].getStatus();
}

const int& Speaker::getTracksAmount() const
{
	return this->trackNumberMax;
}

//Modifires
void Speaker::setTrackNumber(const int number)
{
	this->trackNumber = number;
}

void Speaker::addTrack()
{
	this->trackNumberMax++;
}

void Speaker::nullifyTracksAmount()
{
	this->trackNumberMax = 0;
}

//Functions
// 
// - Sounds
void Speaker::playSounds()
{	
	this->sounds["blaster"].setPlayingOffset(this->sounds["blaster"].getPlayingOffset());
	this->sounds["blaster"].play();
}

void Speaker::playSound(std::string sound_name)
{	
	this->sounds[sound_name].play();
}

void Speaker::playRandomSound(std::string event_name)
{
	if (event_name == "player_impact")
	{
		int queue_num = rand() % 3 + 1;
		switch (queue_num)
		{
		case 1:
			this->sounds["player_impact_01"].play();
			break;
		case 2:
			this->sounds["player_impact_02"].play();
			break;
		case 3:
			this->sounds["player_impact_03"].play();
			break;
		}
	}
}

void Speaker::pauseSounds()
{
	this->sounds["blaster"].pause();
}

void Speaker::pauseSound(std::string sound_name)
{
	this->sounds[sound_name].pause();
}

void Speaker::stopSounds()
{
	this->sounds["blaster"].stop();
}

void Speaker::stopSound(std::string sound_name)
{
	this->sounds[sound_name].stop();
}

void Speaker::setSoundsLoop(bool toggle_loop)
{
	if (toggle_loop == true)
	{
		this->sounds["blaster"].setLoop(true);
	}
	else
	{
		this->sounds["blaster"].setLoop(false);
	}
}

void Speaker::setSoundLoop(std::string sound_name, bool toggle_loop)
{
	if (toggle_loop == true)
	{
		this->sounds[sound_name].setLoop(true);
	}
	else
	{
		this->sounds[sound_name].setLoop(false);
	}
}

void Speaker::setSoundsVolume(float volume)
{
	this->sounds["blaster"].setVolume(volume);
	this->sounds["player_impact_01"].setVolume(volume);
	this->sounds["player_impact_02"].setVolume(volume);
	this->sounds["player_impact_03"].setVolume(volume);
	this->sounds["heal"].setVolume(volume);
	this->sounds["game_over"].setVolume(volume);
	this->sounds["menu_open"].setVolume(volume);
	this->sounds["menu_click"].setVolume(volume);
	this->sounds["menu_highlight"].setVolume(volume);
}

void Speaker::setSoundVolume(std::string sound_name, float volume)
{
	this->sounds[sound_name].setVolume(volume);
}
//
// - Music
void Speaker::openMusic(std::string music_name, std::string file_path)
{
	if (!this->music[music_name].openFromFile(file_path))
	{
		std::cout << "ERROR::SPEAKER::INITMUSIC::Failed to load" << file_path;
	}
}

void Speaker::playMusic(std::string music_name)
{
	this->music[music_name].play();
}

void Speaker::pauseMusic(std::string music_name)
{
	this->music[music_name].pause();
}

void Speaker::stopMusic(std::string music_name)
{
	this->music[music_name].stop();
}

void Speaker::setMusicLoop(std::string music_name, bool toggle_loop)
{
	if (toggle_loop == true)
	{
		this->music[music_name].setLoop(true);
	}
	else
	{
		this->music[music_name].setLoop(false);
	}
}

void Speaker::setMusicVolume(std::string music_name, float volume)
{
	this->music[music_name].setVolume(volume);
}
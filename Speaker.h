#pragma once
class Speaker
{
private:
	//Variables
	unsigned trackNumberMax;
	unsigned trackNumber;

	//Sounds
	std::map<std::string, sf::SoundBuffer> buffers;
	std::map<std::string, sf::Sound> sounds;

	//Music
	std::map<std::string, sf::Music> music;

	//Private functions
	void initVariables();
	void initSound(std::string buffer_name, std::string sound_name, std::string file_path);

public:
	//Constructors and Distructors
	Speaker();
	virtual ~Speaker();

	//Accessors
	sf::SoundSource::Status getMusicStatus(std::string music_name);
	const int& getTracksAmount() const;

	//Modifires
	void setTrackNumber(const int number);
	void addTrack();
	void nullifyTracksAmount();

	//Functions
	// 
	// - Sounds
	void playSounds();
	void playSound(std::string sound_name);
	void playRandomSound(std::string event_name);

	void pauseSounds();
	void pauseSound(std::string sound_name);

	void stopSounds();
	void stopSound(std::string sound_name);

	void setSoundsLoop(bool toggle_loop);
	void setSoundLoop(std::string sound_name, bool toggle_loop);

	void setSoundsVolume(float volume);
	void setSoundVolume(std::string sound_name, float volume);
	//
	// - Music
	void openMusic(std::string music_name, std::string file_path);

	void playMusic(std::string music_name);

	//void pauseMusic();
	void pauseMusic(std::string music_name);

	//void stopMusic();
	void stopMusic(std::string music_name);

	void setMusicLoop(std::string music_name, bool toggle_loop);

	//void setMusicVolume();
	void setMusicVolume(std::string music_name, float volume);
};


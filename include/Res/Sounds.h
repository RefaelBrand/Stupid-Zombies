#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>


using std::string;

const std::string SOUND_EXTENTION = ".wav";

namespace Resources {

	enum class SoundNames {
		BONE_BRAKE,
		BOX_BRAKE,
		BEEP,
		CARDBOARD_BOXES_FALLING,
		DROPPING_A_CARDBOARD_BOX,
		EXPLOSION,
		GROUP_OF_ZOMBIES_GROWLING,
		GUN_SHOT,
		METAL_BOX,
		SHOTGUN_FIREING,
		SHOTGUN_FIRING,
		ZOMBIE_GROWL,
		PRESS_CLICK,
		KNOCK,
		HIT_BOX,
		HIT_BRICK
	};    

	enum class MusicNames {
		BG1,
		BG2,
		TerrorBG,
		NATURE
	};

	 
	class Sounds {

	private:
		std::map<SoundNames, std::pair<sf::Sound, sf::SoundBuffer>> m_sounds;
		std::map<MusicNames,sf::Music> m_music;

		Sounds();
		Sounds(Sounds&) = delete;
		Sounds operator=(Sounds&) = delete;

		void loadSounds();
		void loadMusic();



	public:

		static Sounds* getInstance();
		sf::Sound& getSound(SoundNames soundName);
		sf::Music& getMusic(MusicNames musicName);

		void setSoundsVolume(float v);
		void setMusicVolume(float v);

		void stopMusics();

	};


}
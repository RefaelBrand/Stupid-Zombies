#include "Sounds.h"



namespace Resources {

	Sounds::Sounds()
	{
		loadMusic();
		loadSounds();
	}

	Sounds* Sounds::getInstance()
	{
		static Sounds sounds;
		return &sounds;
	}

	sf::Sound& Sounds::getSound(SoundNames soundName)
	{
		return m_sounds[soundName].first;
	}

	sf::Music& Sounds::getMusic(MusicNames musicName)
	{
		if (m_music.find(musicName) == m_music.end())	throw std::exception("Unknown music name");

		return m_music[musicName];
	}



	void Sounds::loadSounds()
	{

		m_sounds[SoundNames::BONE_BRAKE]				.second.loadFromFile("bone brake.wav");
		m_sounds[SoundNames::BOX_BRAKE]					.second.loadFromFile("box brake.wav");
		m_sounds[SoundNames::CARDBOARD_BOXES_FALLING]	.second.loadFromFile("Cardboard-Boxes-Falling.wav");
		m_sounds[SoundNames::DROPPING_A_CARDBOARD_BOX]	.second.loadFromFile("Dropping-A-Cardboard-Box.wav");
		m_sounds[SoundNames::EXPLOSION]					.second.loadFromFile("explosion.wav");
		m_sounds[SoundNames::GROUP_OF_ZOMBIES_GROWLING]	.second.loadFromFile("Group-Of-Zombies-Growling.wav");
		m_sounds[SoundNames::GUN_SHOT]					.second.loadFromFile("gun shot.wav");
		m_sounds[SoundNames::METAL_BOX]					.second.loadFromFile("metal Box.wav");
		m_sounds[SoundNames::SHOTGUN_FIREING]			.second.loadFromFile("shotgun fireing.wav");
		m_sounds[SoundNames::SHOTGUN_FIRING]			.second.loadFromFile("shotgun-firing.wav");
		m_sounds[SoundNames::ZOMBIE_GROWL]				.second.loadFromFile("zombie-growl.wav");
		m_sounds[SoundNames::PRESS_CLICK]				.second.loadFromFile("press_click.wav");
		m_sounds[SoundNames::BEEP]						.second.loadFromFile("beep.wav");
		m_sounds[SoundNames::KNOCK]						.second.loadFromFile("knock.wav");
		m_sounds[SoundNames::HIT_BOX]					.second.loadFromFile("hitBox.wav");
		m_sounds[SoundNames::HIT_BRICK]					.second.loadFromFile("hitBrick.wav");

		/*}
		catch (std::exception& e)
		{
			throw std::exception("load sound failed");
		}*/
			
		// sets the buffers into the sounds
		for (auto& p : m_sounds)
			p.second.first.setBuffer(p.second.second);
	
	}

	void Sounds::loadMusic()
	{
		m_music[MusicNames::BG1].openFromFile("backgroundMusic1.wav");
		m_music[MusicNames::BG2].openFromFile("backgroundMusic2.wav");
		m_music[MusicNames::TerrorBG].openFromFile("nature.wav");
		m_music[MusicNames::NATURE].openFromFile("terrorMusicBG.wav");

		//set loop
		std::for_each(m_music.begin(), m_music.end(), []
		(auto& p) {p.second.setLoop(true);		});
	}

	void Sounds::setSoundsVolume(float v)
	{
		std::for_each(m_sounds.begin(), m_sounds.end(), [v]
		(auto& s) {
				s.second.first.setVolume(v);		});
	}

	void Sounds::setMusicVolume(float v)
	{
		std::for_each(m_music.begin(), m_music.end(), [v]
		(auto& m) {m.second.setVolume(v);		});
	}

	void Sounds::stopMusics()
	{
		std::for_each(m_music.begin(), m_music.end(), []
		(auto& m) {m.second.stop();		});
	}
}
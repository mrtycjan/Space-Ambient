#include <SFML/Audio.hpp>

#pragma once
class Audio
{
public:

    void setVol(int);
    void mute(bool);
    void play(int);
    void stop(int);
	void pause(int);

    unsigned int volume;
    explicit Audio(void);

private:

	sf::SoundBuffer buffer;
	sf::Music music;
    sf::Sound sound;
};

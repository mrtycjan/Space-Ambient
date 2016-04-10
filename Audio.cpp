

#include "Audio.h"

void Audio::play(int index)
{
	if (index == 0)
		sound.play();
	else if (index == 1)
		music.play();
}

void Audio::stop(int index)
{
	if (index == 0)
		sound.stop();
	else if(index == 1)
		music.stop();
}

void Audio::pause(int index)
{
	if (index == 0)
		sound.pause();
	else if (index == 1)
		music.pause();
}

void Audio::mute(bool mute)
{
    if(mute)
    {
        sound.setVolume(0);
		music.setVolume(0);
    }
    else if(!mute)
    {
        sound.setVolume(volume);
		music.setVolume(volume);
    }
}

void Audio::setVol(int vol)
{
	volume = vol;
	sound.setVolume(volume);
	music.setVolume(volume/2);
}


Audio::Audio()
{
	volume = 80;

	buffer.loadFromFile("data/audio/sfx_laser2.ogg");
	music.openFromFile("data/audio/Tobacco.ogg");
	sound.setBuffer(buffer);	
	sound.setVolume(volume);
	music.setLoop(true);
	music.setVolume(volume/2);


}

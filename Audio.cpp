#pragma once

#include "Audio.h"

void Audio::play(int index)
{
    sound[index].play();
}

void Audio::stop(int index)
{
    sound[index].stop();
}

void Audio::mute(bool mute)
{
    if(mute)
    {
        for(int i=0; i<2; i++)
            sound[i].setVolume(0);
    }
    else if(!mute)
    {
        for(int i=0; i<2; i++)
            sound[i].setVolume(volume);
    }
}

void Audio::setVol(int vol)
{
	volume = vol;
    for(int i=0; i<2; i++)
        sound[i].setVolume(volume);
}

Audio::Audio(void)
{
    volume = 80;

    for(int i=0; i<2; i++)
    {
         sound[i].setVolume(volume);
         sound[i].setLoop(true);
    }
}

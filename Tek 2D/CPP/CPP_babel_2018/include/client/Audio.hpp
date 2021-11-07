/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_
#include "portaudio.h"
#include <vector>
#include <iostream>
#include <list>
#define PA_SAMPLE_TYPE  paInt16
#define SAMPLE_RATE  (48000)
#define FRAMES_PER_BUFFER (960)
#define NUM_CHANNELS    (2)
#define NUM_SECONDS     (2)
class Audio{
	public:
        Audio();
        ~Audio();
        void init();
        void play();
        void record();
        void clean_audio();
        std::list<std::vector<unsigned short>> list_to_play;
        int sampleRate = 48000;
        int bufferSize = 960;
        int channels = 2;
        PaError paErr;
        std::vector<unsigned short> captured;
        PaStream* stream = nullptr;
};

#endif /* !AUDIO_HPP_ */
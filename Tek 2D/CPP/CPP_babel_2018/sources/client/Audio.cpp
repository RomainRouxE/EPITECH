/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Audio 
*/

#include "Audio.hpp"

Audio::Audio()
{

}
Audio::~Audio()
{

}

void Audio::init()
{
    if ((paErr = Pa_Initialize()) != paNoError)
        std::cout << "Pa_Initialize failed: " << Pa_GetErrorText(paErr) << std::endl;
    if ((paErr = Pa_OpenDefaultStream(&stream, channels, channels, paInt16, sampleRate,
        bufferSize, nullptr, nullptr)) != paNoError)
        std::cout << "Pa_OpenDefaultStream failed: " << Pa_GetErrorText(paErr) << std::endl;
    if ((paErr = Pa_StartStream(stream)) != paNoError)
        std::cout << "Pa_StartStream failed: " << Pa_GetErrorText(paErr) << std::endl;
    captured.resize(960*2);
}

void Audio::play()
{
    while (!list_to_play.empty()){
        if ((paErr = Pa_WriteStream(stream, list_to_play.front().data(), bufferSize)) != paNoError)
            std::cout << "Pa_WriteStream failed: " << Pa_GetErrorText(paErr) << std::endl;
        list_to_play.pop_front();
    }
}

void Audio::record()
{
    if ((paErr = Pa_ReadStream(stream, captured.data(), bufferSize)) != paNoError)
            std::cout << "Pa_ReadStream failed: " << Pa_GetErrorText(paErr) << std::endl;
}

void Audio::clean_audio()
{
    if ((paErr = Pa_StopStream(stream)) != paNoError)
        std::cout << "Pa_StopStream failed: " << Pa_GetErrorText(paErr) << std::endl;
    if ((paErr = Pa_CloseStream(stream)) != paNoError) 
        std::cout << "Pa_CloseStream failed: " << Pa_GetErrorText(paErr) << std::endl;
    if ((paErr = Pa_Terminate()) != paNoError) 
        std::cout << "Pa_Terminate failed: " << Pa_GetErrorText(paErr) << std::endl;
}
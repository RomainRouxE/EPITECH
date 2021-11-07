/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Encoder
*/

#include "Encoder.hpp"

Encoder::Encoder()
{

}

Encoder::~Encoder()
{

}

void Encoder::init_encoder()
{
    enc = opus_encoder_create(sampleRate, channels, OPUS_APPLICATION_AUDIO, &opusErr);
    if (opusErr != OPUS_OK)
        std::cout << "opus_encoder_create failed: " << opusErr << std::endl;
    encoded.resize(bufferSize * channels * 2);
}

void Encoder::init_decoder()
{
    dec = opus_decoder_create(sampleRate, channels, &opusErr);
    if (opusErr != OPUS_OK)
        std::cout << "opus_decoder_create failed: " << opusErr << std::endl;
    decoded.resize(bufferSize * channels);
}

void Encoder::encode(std::vector<unsigned short> captured)
{
    if ((enc_bytes = opus_encode(enc, reinterpret_cast<opus_int16 const*>(
        captured.data()), bufferSize, encoded.data(), encoded.size())) < 0)
        std::cout << "opus_encode failed: " << enc_bytes << std::endl;  
}

void Encoder::decode(std::vector<unsigned char> to_decode, int enc_b)
{
    if ((dec_bytes = opus_decode(dec, to_decode.data(), enc_b,
        reinterpret_cast<opus_int16*>(decoded.data()), bufferSize, 0)) < 0)
        std::cout << "opus_decode failed: " << dec_bytes << std::endl;
}

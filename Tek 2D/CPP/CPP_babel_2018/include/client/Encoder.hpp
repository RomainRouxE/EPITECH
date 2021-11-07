/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Encoder
*/

#ifndef ENCODER_HPP_
#define ENCODER_HPP_
#include <opus.h>
#include <vector>
#include <iostream>
class Encoder{
	public:
		Encoder();
		~Encoder();
        void init_encoder();
        void init_decoder();
        void encode(std::vector<unsigned short> captured);
        void decode(std::vector<unsigned char> to_decode, int enc_b);
        int opusErr;
        int sampleRate = 48000;
        int channels = 2;
        opus_int32 enc_bytes;
        opus_int32 dec_bytes;
        int bufferSize = 960;
        std::vector<unsigned short> decoded;
        std::vector<unsigned char> encoded;
        OpusDecoder* dec;
        OpusEncoder* enc;
};

#endif /* !Encoder_HPP_ */
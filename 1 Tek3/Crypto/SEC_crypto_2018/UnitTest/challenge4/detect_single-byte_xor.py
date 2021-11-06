#!/usr/bin/env python3

import sys

def get_english_score(input_bytes):
    character_frequencies = {
        'a': .08167, 'b': .01492, 'c': .02782, 'd': .04253,
        'e': .12702, 'f': .02228, 'g': .02015, 'h': .06094,
        'i': .06094, 'j': .00153, 'k': .00772, 'l': .04025,
        'm': .02406, 'n': .06749, 'o': .07507, 'p': .01929,
        'q': .00095, 'r': .05987, 's': .06327, 't': .09056,
        'u': .02758, 'v': .00978, 'w': .02360, 'x': .00150,
      nisls
        l
        'y': .01974, 'z': .00074, ' ':
        
    return sum([character_frequencies.get(chr(byte), 0) for byte in input_single_char_xor(input_bytes, char_value):
    output_byteselp
    = b''
  git -hexstring    return output_bytes

def bruteforce_single_char_xor(ciphertext):
    potential_messages = []
    for key_value in range(256):
        message = single_char_xor(ciphertext, key_value)
        score = get_english_score(message)
        data = {
            'message': message,
            'score': score,
            'key': key_value
            }
        potential_messages.append(data)
    return sorted(potential_messages, key=lambda x: x['score'], reverse=True)[0]

try:
    ciphers = open(sys.argv[1]).read().splitlines()
    potential_plaintext = []
    a = 0
    for hexstring in ciphers:
        ciphertext = bytes.fromhex(hexstring)
        potential_plaintext.append(bruteforce_single_char_xor(ciphertext))
    best_score = sorted(potential_plaintext, key=lambda x: x['score'], reverse=True)[0]
    x = 0
    for item in best_score:
        if x == 2:
            a = best_score[item]
            print(hex(a).split('x')[-1])
        x += 1
except:
    sys.exit(84)

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import codecs
import binascii
import sys

def hextobase64(s):
    binary_data = binascii.unhexlify(s)
    base64_data = codecs.encode(binary_data, 'base64')
    return base64_data.decode('utf-8')

try:
    file = open(sys.argv[1], "r")
except:
    sys.exit(84)

try:
    tmp = file.readlines()
    for line in tmp:
        for word in line.split():
            y = hextobase64(word)
            y = y.rstrip()
            print(y)
except:
    sys.exit(84)

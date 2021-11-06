#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

def challenge2(string1, string2):
        a = len(string1)
        b = len(string2)
        if (a != b or a % 2 != 0 or b % 2 != 0):
            sys.exit(84)

        result = int(string1, 16) ^ int(string2, 16)
        xor = '{:x}'.format(result)

        return(xor.upper())

    
res = challenge2("5374616C6C6D616E", "426C61636B486174")
print(res)
    

#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys

try:
    with open(sys.argv[1]) as fp:
        tmp = fp.readline()
        str1 = tmp.strip()
        a = len(tmp) - 1
        tmp2 = fp.readline()
        str2 = tmp2.strip()
        b = len(tmp) - 1
        if (a != b or a % 2 != 0 or b % 2 != 0):
            sys.exit(84)

        result = int(str1, 16) ^ int(str2, 16)
        xor = '{:x}'.format(result)

        print(xor.upper())
except:
        sys.exit(84)

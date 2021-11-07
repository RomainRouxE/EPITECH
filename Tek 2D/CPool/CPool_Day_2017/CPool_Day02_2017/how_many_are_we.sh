#!/bin/bash
if [ "$#" == 0 ] ; then
    wc -l
fi
if [ "$#" == 1 ]; then
    cut -d ";" -f 3 | grep -i "$1" | wc -l
fi

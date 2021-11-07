#!/bin/bash
git add .
if [$# -gt 0]
then
    git commit -m "$1"
else
   git  commit -m "default"
fi
git push

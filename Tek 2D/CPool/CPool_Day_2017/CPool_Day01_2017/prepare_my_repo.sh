#!/bin/bash
blih -u romain.roux@epitech.eu repository create "$1"
blih -u romain.roux@epitech.eu repository setacl "$1" ramassage-tek r
blih -u romain.roux@epitech.eu repository getacl "$1"

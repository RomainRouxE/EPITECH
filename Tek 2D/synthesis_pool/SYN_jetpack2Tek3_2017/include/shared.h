/*
** EPITECH PROJECT, 2018
** jetpack
** File description:
** shared header
*/

#pragma once

#define SUCCESS 0
#define FAILURE 84
#define DEBUG_MODE 0
#define BUFFSIZE 4096
#define MAX_CLIENTS 2

#define DEBUG(str, ...) if (DEBUG_MODE)\
do {\
	fprintf(stderr, "\x1b[33m<debug>\x1b[0m" str "$\n", ##__VA_ARGS__);\
} while (0)

#define PRINT_ERR(str, ...) do {\
	fprintf(stderr, "\x1b[41m\x1b[93mError: " str "\x1b[0m\n", ##__VA_ARGS__);\
} while (0)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>
#include <semaphore.h>
#include <sys/mman.h>

#include <sys/socket.h>
#include <sys/types.h> 
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

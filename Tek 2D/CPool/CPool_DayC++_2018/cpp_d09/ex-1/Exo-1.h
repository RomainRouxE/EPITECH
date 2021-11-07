//
// EPITECH PROJECT, 2018
// Exo-1.hpp
// File description:
// Exo-1.hpp
//

#ifndef __EXO_1_H_
#define __EXO_1_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_cthulhu {
	int m_power;
	char *m_name;
} cthulhu_t;

typedef struct s_koala {
	cthulhu_t m_parent;
	char m_isALegend;
} koala_t;

cthulhu_t *NewCthulhu();
void Attack(cthulhu_t *this);
void Sleeping(cthulhu_t *this);

koala_t *NewKoala(char *name, char _isALegend);
void Eat(koala_t *this);

static void CthulhuInitializer(cthulhu_t *this);
static void KoalaInitializer(koala_t *this, char *_name, char _isALegend);

#endif

//
// EPITECH PROJECT, 2018
// Exo-1.cpp
// File description:
// Exo-1.cpp
//

#include "Exo-1.h"

cthulhu_t *NewCthulhu() {
	cthulhu_t *this = malloc(sizeof(cthulhu_t));
	CthulhuInitializer(this);
	return this;
}

void PrintPower(cthulhu_t *this) {
	printf("Power => %i\n", this->m_power);
}

void Attack(cthulhu_t *this) {
	if (this->m_power >= 42) {
		this->m_power -= 42;
		printf("%s attacks and destroys the city\n", this->m_name);
	}
	else {
		printf("%s can't attack, he doesn't have enough power\n", this->m_name);
	}
}

void Sleeping(cthulhu_t *this) {
	this->m_power += 42000;
	printf("%s sleeps\n", this->m_name);
}

koala_t *NewKoala(char *name, char _isALegend) {
	koala_t *this = malloc(sizeof(koala_t));
	KoalaInitializer(this, name, _isALegend);
	return this;
}

void Eat(koala_t *this) {
	this->m_parent.m_power += 42;
	printf("%s eats\n", this->m_parent.m_name);
}

static void CthulhuInitializer(cthulhu_t *this) {
	printf("----\n");
	this->m_name = malloc(8);
	strcpy(this->m_name, "Cthulhu");
	this->m_power = 42;
	printf("Building Cthulhu\n");
}

static void KoalaInitializer(koala_t *this, char *_name, char _isALegend) {
	CthulhuInitializer(&this->m_parent);
	this->m_parent.m_name = _name;
	this->m_parent.m_power = (_isALegend ? 42 : 0);
	this->m_isALegend = _isALegend;
	printf("Building %s\n", this->m_parent.m_name);
}

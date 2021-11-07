/*
** EPITECH PROJECT, 2018
** babel
** File description:
** Account
*/

#include "Account.hpp"

Account::Account(std::string n, int input): id(input), name(n)
{
}

Account::~Account()
{
}

int Account::getId()
{
    return id;
}
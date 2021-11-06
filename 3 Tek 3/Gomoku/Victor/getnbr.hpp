/*
** EPITECH PROJECT, 2018
** getnbr.hpp
** File description:
** getnbr
*/

#pragma once

#include <exception>
#include <stdexcept>
#include <cmath>
#include <limits>

template<typename T>
T getnbr(char const *str)
{
    short s = 1;
    T n = 0;
    T d = 0;
    T pow10 = 1;
    T max = std::numeric_limits<T>::max();
    T min = std::numeric_limits<T>::min();
    T low = std::numeric_limits<T>::lowest();

    while (*str == '+' || *str == '-') {
        if (*str == '-')
            s *= -1;
        ++str;
    }
    while (*str >= '0' && *str <= '9') {
        if (n > max/10 || (s < 0 && low >= 0) || n*s < low/10)
            throw std::out_of_range("invalid number format");
        n = n*10 + (*str-'0')*s;
        if ((n == max/10 && str[1] > fmod(max,10.0) + '0') ||
            (n == low/10 && str[1] > fmod(low,10.0) + '0'))
            throw std::out_of_range("invalid number format");
        ++str;
    }
    if (*str == '.' && min < 1 && min > 0) {
        ++str;
        while (*str >= '0' && *str <= '9') {
            if (d && d < min)
                throw std::out_of_range("invalid number format");
            pow10 /= 10;
            d += (*str-'0')*pow10;
            ++str;
        }
    }
    if (*str != '\0')
        throw std::invalid_argument("invalid number format");
    n += s*d;
    return (n);
}

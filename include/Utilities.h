// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_UTILITIES_H
#define ANIMALS_UTILITIES_H

#include <iostream>

size_t getStrLength(const char * str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}

#endif //ANIMALS_UTILITIES_H

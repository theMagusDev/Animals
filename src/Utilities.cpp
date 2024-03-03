// Copyright (C) 2024 Yuriy Magus

#ifndef ANIMALS_UTILITIES_CPP
#define ANIMALS_UTILITIES_CPP

#include <iostream>

inline size_t getStrLength(const char * str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}

#endif //ANIMALS_UTILITIES_CPP

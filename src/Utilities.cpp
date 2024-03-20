// Copyright (C) 2024 Yuriy Magus

#include "../include/Utilities.h"

size_t getStrLength(const char * str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i;
}

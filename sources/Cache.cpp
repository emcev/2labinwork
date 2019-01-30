//
//  main_rand.cpp
//  cache
//
//  Created by Алексей Мирный on 17/12/2018.
//  Copyright © 2018 alexey. All rights reserved.
//  work please

#include "Cache.hpp"
__int64_t sum_random_detour(unsigned int* array, unsigned int capacity) {
    __int64_t sum = 0;
    while (capacity != 0) {
        unsigned delete_element = std::rand() % capacity;
        sum += array[delete_element];
        std::swap(array[delete_element], array[capacity - 1]);
        capacity--;
    }
    return sum;
}

__int64_t sum_reverse_detour(unsigned int* array, unsigned int capacity) {
    __int64_t sum = 0;
    for (int i = capacity - 1; i > -1; i--)
        sum += array[i];
    return sum;
}

__int64_t sum_straight_detour(unsigned int* array, unsigned int capacity) {
    __int64_t sum = 0;
    for (unsigned i = 0; i < capacity; i++)
        sum += array[i];
    return sum;
}

//
//  main.cpp
//  cache
//
//  Created by Алексей Мирный on 07/10/2018.
//  Copyright © 2018 alexey. All rights reserved.


#include <chrono>
#include <fstream>
#include "Cache.hpp"
int main() {
    std::ofstream file;
    file.open("Otchet.txt");
    unsigned capacity = 4096;
    while (capacity != 35389440) {
        unsigned* array = new unsigned[capacity];
        for (unsigned i = 0; i < capacity; i++) {
            array[i] = std::rand() % 3;
        }
        sum_straight_detour(array, capacity);
        auto start_time = std::chrono::high_resolution_clock::now();
        for (unsigned i = 0; i < 1000; i++)
            sum_straight_detour(array, capacity);
        auto end_time = std::chrono::high_resolution_clock::now();
        auto diff = std::chrono::duration_cast<std::chrono::milliseconds>
            (end_time - start_time);
        file << "count_elements=" << capacity;
        file << " " << "time:" << diff.count();
        file << " " << "straight detour" << std::endl;
        file << std::endl;
        delete[] array;
        unsigned* array1 = new unsigned[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            array1[i] = std::rand() % 3;
        }
        sum_reverse_detour(array1, capacity);
        start_time = std::chrono::high_resolution_clock::now();
        for (unsigned i = 0; i < 1000; i++)
            sum_reverse_detour(array1, capacity);
        end_time = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>
            (end_time - start_time);
        file << "count_elements=" << capacity << " ";
        file << "time:" << diff.count() << " " << "reverse detour" << std::endl;
        file << std::endl;
        delete[] array1;
        unsigned* array2 = new unsigned[capacity];
        for (unsigned i = 0; i < capacity; i++) {
            array2[i] = std::rand() % 3;
        }
        sum_random_detour(array2, capacity);
        start_time = std::chrono::high_resolution_clock::now();
        for (unsigned i = 0; i < 1000; i++)
            sum_random_detour(array2, capacity);
        end_time = std::chrono::high_resolution_clock::now();
        diff = std::chrono::duration_cast<std::chrono::milliseconds>
            (end_time - start_time);
        file << "count_elements=" << capacity << " ";
        file << "time:" << diff.count() << " " << "random detour" << std::endl;
        file << std::endl;
        delete[] array2;
        if (capacity == 16777216)
            capacity = 17694720;
        else
            capacity = capacity * 2;
    }
}

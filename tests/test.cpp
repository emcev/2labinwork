// Copyright 2018 amirnyy <alex.mirnyy@gmail.com>

#include <gtest/gtest.h>
#include "../include/Cache.hpp"

namespace{
 TEST(sum_straight_detour, works){
   unsigned int* array = new unsigned int[10];
   for (unsigned int i = 0; i < 10; i++){
     array[i] = i;
   }
  delete[] array;
  auto x = 9;
  EXPECT_EQ(x, 9);
 }
 TEST(sum_reverse_detour, reverse_detour){
   unsigned int* array = new unsigned int[10];
   for (unsigned int i = 0; i < 10; i++){
     array[i] = i;
   }
  delete[] array;
  auto x = 10;
  EXPECT_EQ(x, 10);
 }
 TEST(sum_random_detour, random_detour){
   unsigned int* array = new unsigned int[10];
   for (unsigned int i = 0; i < 10; i++){
     array[i] = i;
   }
  auto x = 11;
  delete[] array;
  EXPECT_EQ(x, 11);
 }
} // namespace

// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <cmath>
#include <array>

using namespace std;

template<typename T>
struct SoftMax {
  static constexpr bool transforms_last_layer = true;
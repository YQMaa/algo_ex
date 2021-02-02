// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef SUM_OF_SQUARES_H
#define SUM_OF_SQUARES_H

#include <cmath>
#include <array>

template<typename T>
struct SumOfSquares {
  static constexpr bool transforms_last_layer = false;
  static constexpr bool supports_backpropagation = true;

  template<typename LayerSize>
  using Output = std::array<T, LayerSi
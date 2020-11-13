
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef RMSE_H
#define RMSE_H

#include <cmath>
#include <cstddef>
#include <array>

template<typename T>
struct RMSE {
  static constexpr bool transforms_last_layer = false;
  static constexpr bool supports_backpropagation = false;

  template<typename LayerSize>
  using Output = std::array<T, LayerSize::length>;

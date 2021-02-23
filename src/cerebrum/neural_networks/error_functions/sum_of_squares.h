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
  using Output = std::array<T, LayerSize::length>;

  template<typename LayerSize, size_t batch_size>
  using Outputs = std::array<Output<LayerSize>, batch_size>;

  template<typename LayerSize, size_t batch_size>
  inline static T
  error(const Outputs<LayerSize, batch_size>& y,
        const Outputs<LayerSize, batch_size>& t) {
    T err = 0;
    for (size_t n = 0; n < batch_size; n++)
      for (size_t i = 0; i < LayerSize::length; i++)
        err += (t[n][i] - y[n][i]) * (t[n][i] - y[n][i]);
    return err / (T)2;
  }

  template<typename LayerSize, size_t batch_size>
  inline static void
  dError(c
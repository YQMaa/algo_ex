// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <cmath>
#include <array>

using namespace std;

template<typename T>
struct SoftMax {
  static constexpr bool transforms_last_layer = true;
  static constexpr bool supports_backpropagation = true;

  template<typename LayerSize>
  using Output = array<T, LayerSize::length>;

  template<typename LayerSize, size_t batch_size>
  using Outputs = array<Output<LayerSize>, batch_size>;

  template<typename LayerSize, size_t batch_size>
  inline static void
  f(const Outputs<LayerSize, batch_size>& a,
    Outputs<LayerSize, batch_size>& y) {
    for (size_t n = 0; n < batch_size; n++) {
      T sum = 0;
      Output<LayerSize>* const y_row =
        reinterpret_cast<Output<LayerSize>*>(y[n].data());
      for (size_t i = 0; i < L
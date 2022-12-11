
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef LOGISTIC_H
#define LOGISTIC_H

#include <cmath>
#include <array>

template<typename T>
struct Logistic;

template<typename T>
struct Logistic {
  /* One at a time */
  inline static T f(T x) {
    return (T)1 / ((T)1 + exp(-x));
  }
  inline static T df(T y) {
    return y * ((T)1 - y);
  }

  /* All neurons on a layer */
  template<typename LayerSize>
  using Neurons = std::array<T, LayerSize::length>;

  template<typename LayerSize>
  inline static void
  f_layer(const Neurons<LayerSize>& Z, Neurons<LayerSize>& A) {
    for (size_t j = 0; j < LayerSize::length; j++) {
      A[j] = f(Z[j]);
    }
  }

  template<typename LayerSize>
  inline static void
  df_layer(const Neurons<LayerSize>& A, Neurons<LayerSize>& Err){
    for (size_t j = 0; j < LayerSize::length; j++) {
      Err[j] *= A[j] * ((T)1 - A[j]);
    }
  }

  /* All neurons in a batch */
  template<typename LayerSize, size_t batch_size>
  using Batch = std::array<Neurons<LayerSize>, batch_size>;

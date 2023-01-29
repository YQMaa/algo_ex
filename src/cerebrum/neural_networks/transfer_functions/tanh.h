// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef HYPERBOLIC_TANGENT_H
#define HYPERBOLIC_TANGENT_H

#include <cmath>
#include <array>

template<typename T>
struct HyperbolicTangent;

template<typename T>
struct HyperbolicTangent {
  inline static T f(T x) {
    const T e2x = exp(-2 * x);
    return ((T)1 - e2x) / ((T)1 + e2x);
  }

  inline static T df(T y) {
    return (T)1 - y * y;
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
      Err[j] *= ((T)1 - A[j] * A[j]);
    }
  }

  /* All neurons in a batch */
  template<typename LayerSize, size_t batch_size>
  using Batch = std::array<Neurons<LayerSize>, batch_size>;

  template<typename LayerSize, size_t batch_size>
  inline static void
  f_batch(const Batch<LayerSize, batch_size>& Z,
          Batch<LayerSize, batch_size>& A) {
    constexpr size_t full_length = LayerSize::length * batch_size;
    using LinearBatch = std::array<T, LayerSize::le
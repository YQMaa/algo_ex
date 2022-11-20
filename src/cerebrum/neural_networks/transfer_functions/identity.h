// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef IDENTITY_H
#define IDENTITY_H

#include <cstring>
#include <cmath>
#include <array>

template<typename T>
struct Identity {
  inline static T f(T x) {
    return x;
  }

  inline static T df(T) {
    return (T)1;
  }

  /* All neurons on a layer */
  template<typename LayerSize>
  using Neurons = std::array<T, LayerSize::length>;

  template<typename LayerSize>
  inline static void
  f_layer(const Neurons<LayerSize>& Z, Neurons<LayerSize>& A) {
   
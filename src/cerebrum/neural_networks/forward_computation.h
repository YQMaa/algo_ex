
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef FORWARD_COMPUTATION_H
#define FORWARD_COMPUTATION_H

#include <cstddef>
#include <array>
#include <type_traits>

#include "cerebrum/neural_networks/parameters.h"

template<typename T, size_t batch_size,
         typename ErrorFunction, bool computes,
         typename InputSize, typename... OtherLayers>
struct _ForwardComputation;

template<typename T, size_t batch_size, typename ErrorFunction,
         typename LastSize>
struct _ForwardComputation<T, batch_size, ErrorFunction, false, LastSize> {

  using NetOutputs = std::array<std::array<T, LastSize::length>, batch_size>;
  const NetOutputs* y;

  const NetOutputs&
  forward(const NetOutputs& outputs, bool parameters) {
    y = &outputs;
    return outputs;
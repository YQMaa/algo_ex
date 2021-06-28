// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef DROPOUT_H
#define DROPOUT_H

#include <cstddef>
#include <cstring>
#include <array>
#include <random>

#include "cerebrum/include_cblas.h"
#include "cerebrum/size.h"

template<size_t active_no>
struct Dropout { 

  /* -------------------- OutputSize -------------------- */

 public:

  template<typename InputSize>
  using OutputSize = InputSize;

  /* -------------------- Parameters -------------------- */

 public:

  template<typename InputSize>
  static constexpr size_t
  parameters_array_size() {
    return 0ul;
  }

  template<typename InputSize>
  static constexpr size_t
  parameters_no() {
    return 0ul;
  }

  template<typename T, typename InputSize>
  using Parameters = std::array<T, 0>;

  template<typename T, typename InputSize>
  inline static void
  init_parameters(Parameters<T, InputSize>&) { }

  /* -------------------- Inputs, Hidden, and Outputs -------------------- */
 public:

  template<typename T, typename InputSize>
  using Input = std::array<T, InputSize::length>;

  template<typename T, typename InputSize, size_t batch_size>
  using Inputs = std::array<Input<T, InputSize>, batch_size>;

  template<typename T, typename InputSize>
  using Output = Input<T, InputSize>;

  template<typename T, typename InputSize, size_t batch_size>
  using Outputs = Inputs
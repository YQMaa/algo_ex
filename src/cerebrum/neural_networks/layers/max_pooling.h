// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef MAX_POOLING_H
#define MAX_POOLING_H

#include <cstddef>
#include <limits>
#include <array>

#include "cerebrum/size.h"

template<size_t pool_height, size_t pool_width>
struct MaxPooling {

  /* -------------------- OutputSize -------------------- */

 public:

  template<typename InputSize>
  using OutputSize =
    Size<InputSize::maps_no,
         InputSize::height / pool_height,
         InputSize::width / pool_width>;

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

  template <typename T, typename InputSize, size_t batch_size>
  using Inputs = std::array<Input<T, InputSize>, batch_size>;

 private:

  template<typename T, typename InputSize>
  using _InputMap =
    std::array<std::array<T, InputSize::width>, InputSize::height>;

  template<typename T, typename InputSize>
  using _InputMaps =
    std::array<_InputMap<T, InputSize>, InputSize::maps_no>;

  template<typename T, typename InputSize, size_t batch_size>
  using _Inputs = std::array<_InputMaps<T, InputSize>, batch_size>;

 public:

  template<typename T, typename InputSize>
  using Output = std::array<T, OutputSize<InputSize>::length>;

  template <typename T, typename InputSize, size_t batch_size>
  using Outputs = std::array<Output<T, InputSize>, batch_size>;

 private:

  template<typename T, typename InputSize>
  using _OutputMap =
    std::array<std::array<T, OutputSize<InputSize>::width>,
               OutputSize<InputSize>::height>;

  template<typename T, typename InputSize>
  using _OutputMaps =
    std::array<_OutputMap<T, InputSize>, OutputSize<InputSize>::maps_no>;

  tem
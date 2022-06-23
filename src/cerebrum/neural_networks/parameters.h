// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <cstddef>
#include <iostream>
#include <random>

template<typename T, typename InputSize, typename... Other>
struct _Parameters;

template<typename T, typename InputSize, typename LastLayer>
struct _Parameters<T, InputSize, LastLayer> {
  typename LastLayer::template Parameters<T, InputSize> values;
  bool next;

  _Parameters() {
    LastLayer::template init_parameters<T, InputSize>(values);
  }

  _Parameters(T value) {
    for (size_t i = 0;
         i < LastLayer::template parameters_array_size<InputSize>();
         i++)
      values[i] = value;
  }

  _Parameters(T min, T max) {
    std::random_device rd { };
    std::default_random_engine e {rd()};
    std::uniform_real_distribution<T> next_parameter(min, max);
    for (size_t i = 0;
         i < LastLayer::template parameters_array_size<InputSize>();
         i++)
      values[i] = next_parameter(e
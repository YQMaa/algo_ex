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
    LastLayer::template init_parameters<T, InputS
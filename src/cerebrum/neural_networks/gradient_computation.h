// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef GRADIENT_COMPUTATION_H
#define GRADIENT_COMPUTATION_H

#include <array>
#include "cerebrum/neural_networks/parameters.h"

template<typename T, size_t batch_size, typename ErrorFunction, bool computes,
         typename InputSize, typename... OtherLayers>
struct _GradientComputation;

template<typename T, size_t batch_size, typename ErrorFunction,
         typename InputSize>
struct _GradientComputation<T, batch_size, ErrorFunction, true, InputSize> {

  using NetOutputs = std::array<std::array<T, InputSize::length>, batch_size>;
  NetOutputs y;

  T computeGradient(const NetOutputs& outputs, bool parameters,
                    const NetOutputs& labels,
                    NetOutputs& prev_errors, bool gradient) {
    ErrorFunction::template f<InputSize, batch_size>(outputs, y);
    ErrorFunction::template
      dError<InputSize, batch_size>(y, labels, prev_errors);
    return ErrorFunction::template error<InputSize, batch_size>(y, labels);
  }
};

template<typename T, size_t batch_size, typename ErrorFunction,
         typename InputSize>
struct _GradientComputation<T, batch_size, ErrorFunction, false, InputSize> {

  using NetOutputs = std::array<std::array<T, InputSize::length>, batch_size>;

  T computeGradient(const NetOutputs& outputs, bool parameters,
                    const NetOutputs& labels,
              
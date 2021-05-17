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
struct _GradientComputation<T, batch_size
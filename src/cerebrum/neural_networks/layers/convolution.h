
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <cstddef>
#include <array>
#include <random>

#include "cerebrum/include_cblas.h"
#include "cerebrum/size.h"
#include "cerebrum/meta/meta_matrix.h"

template<size_t maps_no, size_t conv_height, size_t conv_width, size_t stride,
         typename Mapping, template<typename> class TransferFunction>
struct _Convolution;

template<size_t maps_no, size_t conv_height, size_t conv_width, size_t stride,
         typename Mapping, template<typename> class TransferFunction>
struct Convolution;
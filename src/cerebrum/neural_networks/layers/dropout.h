// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef DROPOUT_H
#define DROPOUT_H

#include <cstddef>
#include <cstring>
#include <array>
#include <random>

#include "cerebrum/include_cblas.h"
#include "cerebrum/size.h"

template<size_t
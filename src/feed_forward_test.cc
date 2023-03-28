
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#include <iostream>
#include <random>
#include <typeinfo>
#include <chrono>

//#include <fenv.h>

#include "cerebrum/size.h"
#include "cerebrum/neural_networks.h"

template<typename T, size_t batch_size, size_t length>
using Arr = std::array<std::array<T, length>, batch_size>;

template<typename T, size_t batch_size, size_t length>
Arr<T, batch_size, length>* get_dummy_example() {
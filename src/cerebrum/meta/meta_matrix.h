// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef META_MATRIX_H
#define META_MATRIX_H

#include <cstddef>

template<typename T, size_t height, size_t width, T... values>
struct MetaMatrix { };

template<typename T, size_t height, size_t width>
struct MetaMatrix<T, height, width> {

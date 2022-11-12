// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef IDENTITY_H
#define IDENTITY_H

#include <cstring>
#include <cmath>
#include <array>

template<typename T>
struct Identity {
  inline static T f(T x) {

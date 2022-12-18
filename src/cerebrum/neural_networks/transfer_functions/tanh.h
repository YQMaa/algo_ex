// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef HYPERBOLIC_TANGENT_H
#define HYPERBOLIC_TANGENT_H

#include <cmath>
#include <array>

template<typename T>
struct HyperbolicTangent;

template<typename T>
struct HyperbolicTangent {
  inline static T f(T x) {
    const T 
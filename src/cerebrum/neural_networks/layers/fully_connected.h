
// Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

#ifndef FULLY_CONNECTED_H
#define FULLY_CONNECTED_H

#include <cstddef>
#include <array>
#include <random>

#include "cerebrum/include_cblas.h"
#include "cerebrum/size.h"

template<size_t length, template <typename> class TransferFunction>
struct FullyConnected {

  /* -------------------- OutputSize -------------------- */

 public:

  template<typename InputSize>
  using OutputSize = Size<length>;

  /* -------------------- Parameters -------------------- */

 public:

  template<typename InputSize>
  static constexpr size_t
  parameters_array_size() {
    return (InputSize::length + 1) * length;
  }

  template<typename InputSize>
  static constexpr size_t
  parameters_no() {
    return parameters_array_size<InputSize>();
  }

  template<typename T, typename InputSize>
  using Parameters = std::array<T, (InputSize::length + 1) * length>;

 private:

  template<typename T, typename InputSize, size_t batch_size>
  using _LinearInputs = std::array<T, InputSize::length * batch_size>;

  template<typename T, typename InputSize, size_t batch_size>
  using _LinearOutputs = std::array<T, length * batch_size>;

  template<typename T, typename InputSize>
  using _Biases = std::array<T, OutputSize<InputSize>::length>;

  template<typename T, typename InputSize>
  using _WeightsRow = std::array<T, InputSize::length>;

  template<typename T, typename InputSize>
  using _Weights =
    std::array<_WeightsRow<T, InputSize>, OutputSize<InputSize>::length>;

  template<typename T, typename InputSize>
  using _LinearWeights = std::array<T, InputSize::length * length>;

 public:

  template<typename T, typename InputSize>
  inline static void
  init_parameters(Parameters<T, InputSize>& parameters) {
    std::random_device rd { };
    std::default_random_engine e {rd()};
    std::normal_distribution<T> next_parameter(0.0, 0.1);

    for (size_t i = 0; i < parameters_array_size<InputSize>(); i++)
      parameters[i] = next_parameter(e);
  }


  /* -------------------- Inputs, Hidden, and Outputs -------------------- */
 public:

  template<typename T, typename InputSize>
  using Input = std::array<T, InputSize::length>;

  template<typename T, typename InputSize, size_t batch_size>
  using Inputs = std::array<Input<T, InputSize>, batch_size>;

  template<typename T, typename InputSize>
  using Output = std::array<T, OutputSize<InputSize>::length>;

  template<typename T, typename InputSize, size_t batch_size>
  using Outputs = std::array<Output<T, InputSize>, batch_size>;

  template<typename T, typename InputSize, size_t batch_size>
  using Hidden = Outputs<T, OutputSize<InputSize>, batch_size>;

  /* -------------------- Forward phase -------------------- */

  template<typename T, typename InputSize, size_t batch_size, bool train>
  struct _Forward;

  template<typename T, typename InputSize, size_t batch_size, bool train>
  inline static void
  forward(const Inputs<T, InputSize, batch_size>& inputs,
          const Parameters<T, InputSize>& parameters,
          Hidden<T, InputSize, batch_size>& hidden,
          Outputs<T, InputSize, batch_size>& outputs) {
    _Forward<T, InputSize, batch_size, train>::
      forward(inputs, parameters, hidden, outputs);
  }


#ifdef USE_CBLAS

  template<typename InputSize, size_t batch_size, bool train>
  struct _Forward<float, InputSize, batch_size, train> {
    static void forward(const Inputs<float, InputSize, batch_size>& inputs,
                        const Parameters<float, InputSize>& parameters,
                        Hidden<float, InputSize, batch_size>& hidden,
                        Outputs<float, InputSize, batch_size>& outputs) {
      for (size_t n = 0; n < batch_size; n++) {
        cblas_scopy(length,
                    reinterpret_cast<const float*>(parameters.data()), 1,
                    reinterpret_cast<float*>(hidden[n].data()), 1);
      }
      cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasTrans,
                  batch_size, length, InputSize::length,
                  1.0, reinterpret_cast<const float*>(inputs.data()),
                  InputSize::length,
                  reinterpret_cast<const float*>(&(parameters[length])),
                  InputSize::length,
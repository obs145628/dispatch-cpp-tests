#pragma once

#include <iostream>
#include "vector_defs.hh"

#ifdef HAS_INS_AVX

template<>
struct VectorOpDef<OpVadd, InsAvx>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vadd[AVX](const float*, const float*, float*, std::size_t)\n";
  }
};

template<>
struct VectorOpDef<OpVsub, InsAvx>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vsub[AVX](const float*, const float*, float*, std::size_t)\n";
  }
};

#endif

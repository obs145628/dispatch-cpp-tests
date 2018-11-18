#pragma once

#include <iostream>
#include "vector_defs.hh"

#ifdef HAS_INS_SSE

template<>
struct VectorOpDef<OpVadd, InsSse>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vadd[SSE](const float*, const float*, float*, std::size_t)\n";
  }
};

template<>
struct VectorOpDef<OpVsub, InsSse>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vsub[SSE](const float*, const float*, float*, std::size_t)\n";
  }
};

#endif

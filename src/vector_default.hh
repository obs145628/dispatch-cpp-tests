#pragma once

#include <iostream>
#include "vector_defs.hh"

#ifdef HAS_INS_DEFAULT

template<>
struct VectorOpDef<OpVadd, InsDefault>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vadd[DEFAULT](const float*, const float*, float*, std::size_t)\n";
  }
};

template<>
struct VectorOpDef<OpVsub, InsDefault>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vsub[DEFAULT](const float*, const float*, float*, std::size_t)\n";
  }
};

#endif

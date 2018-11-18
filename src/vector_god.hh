#pragma once

#include <iostream>
#include "vector_defs.hh"

#ifdef HAS_INS_GOD

template<>
struct VectorOpDef<OpVadd, InsGod>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vadd[GOD](const float*, const float*, float*, std::size_t)\n";
  }
};

template<>
struct VectorOpDef<OpVsub, InsGod>
{
  static constexpr bool defined = true;

  static void call_loop(const float*, const float*, float*, std::size_t)
  {
    std::cout << "vsub[GOD](const float*, const float*, float*, std::size_t)\n";
  }
};

#endif

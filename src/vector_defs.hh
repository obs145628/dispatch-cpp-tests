#pragma once

#include <cstddef>
#include <iostream>

#define SYS_INS_SSE
#define SYS_INS_AVX
#define SYS_INS_DEFAULT



#if defined(SYS_INS_AVX) && defined(USE_AVX)
# define HAS_INS_AVX
#endif
#if defined(SYS_INS_DEFAULT) && defined(USE_DEFAULT)
# define HAS_INS_DEFAULT
#endif
#if defined(SYS_INS_GOD) && defined(USE_GOD)
# define HAS_INS_GOD
#endif
#if defined(SYS_INS_SSE) && defined(USE_SSE)
# define HAS_INS_SSE
#endif


struct InfosIns
{

  #ifdef HAS_INS_SSE
  static constexpr bool has_sse = true;
  #else
  static constexpr bool has_sse = false;
  #endif

  #ifdef HAS_INS_AVX
  static constexpr bool has_avx = true;
  #else
  static constexpr bool has_avx = false;
  #endif

  #ifdef HAS_INS_GOD
  static constexpr bool has_god = true;
  #else
  static constexpr bool has_god = false;
  #endif

  #ifdef HAS_INS_DEFAULT
  static constexpr bool has_default = true;
  #else
  static constexpr bool has_default = false;
  #endif
};

struct OpVadd
{
  static constexpr const char* name = "vadd";
};

struct OpVsub
{
  static constexpr const char* name = "vsub";
};

struct OpVmul
{
  static constexpr const char* name = "vmul";
};

struct InsSse
{
};

struct InsAvx
{
};

struct InsDefault
{
};

struct InsGod
{
};

template <class Op, class Ins>
struct VectorOpDef
{
  static constexpr bool defined = false; 
};


template <class Op, class Ins, class... Args>
void call_vector_op(Args... args)
{
  VectorOpDef<Op, Ins>::call_loop(args...);
}


template <class... Ins>
struct VectorOpCaller;

template<class Op>
struct VectorOpCaller<Op>
{

  template <class... Args>
  static void call(Args...)
  {
    std::cout << "No implementation found for " << Op::name << "\n";
  }
  
};
 

template <class Op, class Head, class ...Tail>
struct VectorOpCaller<Op, Head, Tail...>
{
  template <class... Args>
  static void call(Args... args)
  //static void call(const float* a, const float* b, float* out , std::size_t len)
  {
    if constexpr (VectorOpDef<Op, Head>::defined)
      call_vector_op<Op, Head>(args...);
    else
      VectorOpCaller<Op, Tail...>::call(args...);
  }
};

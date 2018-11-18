#include "vector_ops.hh"

#include "vector_defs.hh"
#include "vector_avx.hh"
#include "vector_default.hh"
#include "vector_god.hh"
#include "vector_sse.hh"

void op_vadd(const float* a, const float* b, float* out, std::size_t len)
{
  VectorOpCaller<OpVadd,
		 InsGod, InsSse, InsAvx, InsDefault>::call(a, b, out, len);
}

void op_vsub(const float* a, const float* b, float* out, std::size_t len)
{
  VectorOpCaller<OpVsub,
		 InsGod, InsAvx, InsDefault>::call(a, b, out, len);
}

void op_vmul(const float* a, const float* b, float* out, std::size_t len)
{
  VectorOpCaller<OpVmul,
		 InsGod, InsSse, InsDefault>::call(a, b, out, len);
}

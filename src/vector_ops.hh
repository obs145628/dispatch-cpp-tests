#pragma once

#include <cstddef>


void op_vadd(const float* a, const float* b, float* out, std::size_t len);
void op_vsub(const float* a, const float* b, float* out, std::size_t len);
void op_vmul(const float* a, const float* b, float* out, std::size_t len);

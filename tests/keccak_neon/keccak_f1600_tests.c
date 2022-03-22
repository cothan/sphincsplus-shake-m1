/*
 * Copyright (c) 2021 Arm Limited
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

//
// Author: Hanno Becker <hanno.becker@arm.com>
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "keccak_f1600_tests.h"
#include "keccak_f1600_variants.h"

#include "misc.h"
#include "cycles.h"

void zip_f1600_states( int num, uint64_t *dst, uint64_t const  *src )
{
    for( int i=0; i < KECCAK_F1600_X1_STATE_SIZE_UINT64; i++ )
        for( int j=0; j<num; j++ )
            dst[num*i+j] = src[j*KECCAK_F1600_X1_STATE_SIZE_UINT64+i];
}

static int cmp_uint64_t(const void *a, const void *b)
{
    return (int)((*((const uint64_t *)a)) - (*((const uint64_t *)b)));
}

#define stringify(x) stringify_(x)
#define stringify_(x) #x

#define MAKE_VALIDATE_F1600_X_GENERIC(testname,funcname,NUM)            \
int testname (void)                                                     \
{                                                                       \
    debug_test_start( stringify(testname) );                            \
                                                                        \
    ALIGN(64)                                                           \
    uint64_t state[NUM*KECCAK_F1600_X1_STATE_SIZE_UINT64] = { 0 };      \
    ALIGN(64)                                                           \
    uint64_t ref_state[NUM*KECCAK_F1600_X1_STATE_SIZE_UINT64] = { 0 };  \
    ALIGN(64)                                                           \
    uint64_t ref_state_[NUM*KECCAK_F1600_X1_STATE_SIZE_UINT64] = { 0 }; \
                                                                        \
    zip_f1600_states( NUM, state, ref_state );                          \
                                                                        \
    funcname( state );                                                  \
                                                                        \
    for( int i=0; i<NUM; i++ )                                          \
    {                                                                   \
        keccak_f1600_x1_scalar_C_original( ref_state +                  \
                               i * KECCAK_F1600_X1_STATE_SIZE_UINT64 ); \
    }                                                                   \
                                                                        \
    zip_f1600_states( NUM, ref_state_, ref_state );                     \
                                                                        \
    if( compare_buf_u8( (uint8_t*) state, (uint8_t*) ref_state_,        \
                        NUM * KECCAK_F1600_X1_STATE_SIZE_BYTES ) != 0 ) \
    {                                                                   \
        debug_print_buf_u8( (uint8_t*) ref_state_,                      \
                            NUM * KECCAK_F1600_X1_STATE_SIZE_BYTES,     \
                            "Reference" );                              \
        debug_print_buf_u8( (uint8_t*) state,                           \
                            NUM * KECCAK_F1600_X1_STATE_SIZE_BYTES,     \
                            "Actual" );                                 \
        debug_test_fail();                                              \
    }                                                                   \
                                                                        \
    debug_test_ok();                                                    \
    return 0;                                                           \
}

#define MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(testname,funcname,NUM)    \
int testname (void)                                                     \
{                                                                       \
    debug_test_start( stringify(testname) );                            \
                                                                        \
    ALIGN(64)                                                           \
    uint64_t state [NUM*KECCAK_F1600_X1_STATE_SIZE_UINT64] = { 0 };     \
                                                                        \
    fill_random_u8( (uint8_t*) state,                                   \
                    NUM*KECCAK_F1600_X1_STATE_SIZE_BYTES );             \
                                                                        \
    uint64_t t0, t1;                                                    \
    uint64_t cycles[TEST_ITERATIONS];                                   \
                                                                        \
    for(unsigned cnt=0; cnt < TEST_WARMUP; cnt++)                       \
        funcname( state );                                              \
                                                                        \
    for(unsigned cnt=0; cnt < TEST_ITERATIONS; cnt++)                   \
    {                                                                   \
        t0 = get_cyclecounter();                                        \
        funcname( state );                                              \
        t1 = get_cyclecounter();                                        \
        cycles[cnt] = t1 - t0;                                          \
    }                                                                   \
                                                                        \
    /* Report median */                                                 \
    qsort( cycles, TEST_ITERATIONS, sizeof(uint64_t), cmp_uint64_t );   \
    debug_printf( "Median after %u tests: %lld cycles\n",               \
                  TEST_ITERATIONS, cycles[TEST_ITERATIONS >> 1] );      \
                                                                        \
    debug_test_ok();                                                    \
    return( 0 );                                                        \
}

#define KECCAK_F1600_X2_FUNCNAME(variant) keccak_f1600_x2_v8_4a_ ## variant
#define KECCAK_F1600_X2_TESTNAME(variant) validate_keccak_f1600_x2_ ## variant
#if defined(KECCAK_F1600_TEST_HAVE_SHA3_EXTENSION)
#define MAKE_VALIDATE_F1600_X2(variant)                                 \
    MAKE_VALIDATE_F1600_X_GENERIC(KECCAK_F1600_X2_TESTNAME(variant),    \
                                  KECCAK_F1600_X2_FUNCNAME(variant), 2)
#else
#define MAKE_VALIDATE_F1600_X2(variant)                                 \
int validate_keccak_f1600_x2(void)                                      \
{                                                                       \
    return( 0 );                                                        \
}
#endif /* KECCAK_F1600_TEST_HAVE_SHA3_EXTENSION */


#define KECCAK_F1600_X1_FUNCNAME(variant) keccak_f1600_x1_ ## variant
#define KECCAK_F1600_X1_TESTNAME(variant) validate_keccak_f1600_x1_ ## variant
#define MAKE_VALIDATE_F1600_X1(variant)                                 \
    MAKE_VALIDATE_F1600_X_GENERIC(KECCAK_F1600_X1_TESTNAME(variant),    \
                                  KECCAK_F1600_X1_FUNCNAME(variant),1)

#define KECCAK_F1600_X2_BENCHMARK_SINGLE_TESTNAME(variant)      \
benchmark_single_keccak_f1600_x2_ ## variant

#if defined(KECCAK_F1600_TEST_HAVE_SHA3_EXTENSION)
#define MAKE_BENCHMARK_SINGLE_F1600_X2(variant)                         \
    MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(                              \
        KECCAK_F1600_X2_BENCHMARK_SINGLE_TESTNAME(variant),             \
        KECCAK_F1600_X2_FUNCNAME(variant),2)
#else
#define MAKE_BENCHMARK_SINGLE_F1600_X2(variant)                         \
int benchmark_single_keccak_f1600_x2_ ## variant (void)                 \
{                                                                       \
    return;                                                             \
}
#endif /* KECCAK_F1600_TEST_HAVE_SHA3_EXTENSION */

#define KECCAK_F1600_X1_BENCHMARK_SINGLE_TESTNAME(variant)      \
    benchmark_single_keccak_f1600_x1_ ## variant

#define MAKE_BENCHMARK_SINGLE_F1600_X1(variant)                         \
    MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(                              \
        KECCAK_F1600_X1_BENCHMARK_SINGLE_TESTNAME(variant),             \
        KECCAK_F1600_X1_FUNCNAME(variant),1)

/////////////////////////////// TEST CASES ////////////////////////////////////

MAKE_VALIDATE_F1600_X1(scalar_asm_v1)
MAKE_VALIDATE_F1600_X1(scalar_asm_v2)
MAKE_VALIDATE_F1600_X1(scalar_asm_v3)
MAKE_VALIDATE_F1600_X1(scalar_C_v0)
MAKE_VALIDATE_F1600_X1(scalar_C_v1)

MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_asm_v1)
MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_asm_v2)
MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_asm_v3)
MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_C_v0)
MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_C_v1)
MAKE_BENCHMARK_SINGLE_F1600_X1(scalar_C_original)

MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_scalar_asm_v1,
                              keccak_f1600_x4_scalar_asm_v1,4)

MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x2_v84a_asm_v1,
                              keccak_f1600_x1_v84a_asm_v1,2)
MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x2_v84a_asm_v2,
                              keccak_f1600_x1_v84a_asm_v2,2)

MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_hybrid_asm_v1,
                              keccak_f1600_x4_hybrid_asm_v1,4)
MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_hybrid_asm_v2,
                              keccak_f1600_x4_hybrid_asm_v2,4)
MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_hybrid_asm_v3,
                              keccak_f1600_x4_hybrid_asm_v3,4)
MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_hybrid_asm_v3p,
                              keccak_f1600_x4_hybrid_asm_v3p,4)
MAKE_VALIDATE_F1600_X_GENERIC(validate_keccak_f1600_x4_hybrid_asm_v4,
                              keccak_f1600_x4_hybrid_asm_v4,4)

MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x4_hybrid_asm_v1,
                              keccak_f1600_x4_hybrid_asm_v1,4)
MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x4_hybrid_asm_v2,
                              keccak_f1600_x4_hybrid_asm_v2,4)
MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x4_hybrid_asm_v3,
                              keccak_f1600_x4_hybrid_asm_v3,4)
MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x4_hybrid_asm_v3p,
                              keccak_f1600_x4_hybrid_asm_v3p,4)
MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x4_hybrid_asm_v4,
                              keccak_f1600_x4_hybrid_asm_v4,4)

MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x2_v84a_asm_v1,
                              keccak_f1600_x1_v84a_asm_v1,2)
MAKE_BENCHMARK_SINGLE_F1600_X_GENERIC(benchmark_single_keccak_f1600_x2_v84a_asm_v2,
                              keccak_f1600_x1_v84a_asm_v2,2)

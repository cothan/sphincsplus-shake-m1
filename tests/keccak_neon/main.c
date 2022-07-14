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
#include "cycles.h"

int main(void)
{
#if defined(KECCAK_F1600_TEST_VALIDATE)

    if( validate_keccak_f1600_x1_scalar_C_v0() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x1_scalar_C_v1() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x1_scalar_asm_v1() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x1_scalar_asm_v2() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x1_scalar_asm_v2() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x2_v84a_asm_v1() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x2_v84a_asm_v2() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_scalar_asm_v1() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_hybrid_asm_v1() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_hybrid_asm_v2() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_hybrid_asm_v3() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_hybrid_asm_v3p() != 0 )
        return( 1 );
    if( validate_keccak_f1600_x4_hybrid_asm_v4() != 0 )
        return( 1 );
#endif /* KECCAK_F1600_TEST_VALIDATE */

#if defined(KECCAK_F1600_TEST_BENCHMARK)
    enable_cyclecounter();

    benchmark_single_keccak_f1600_x1_scalar_C_original();
    benchmark_single_keccak_f1600_x1_scalar_C_v0();
    benchmark_single_keccak_f1600_x1_scalar_C_v1();
    benchmark_single_keccak_f1600_x1_scalar_asm_v1();
    benchmark_single_keccak_f1600_x1_scalar_asm_v2();
    benchmark_single_keccak_f1600_x1_scalar_asm_v3();

    benchmark_single_keccak_f1600_x2_v84a_asm_v1();
    benchmark_single_keccak_f1600_x2_v84a_asm_v2();

    benchmark_single_keccak_f1600_x4_hybrid_asm_v1();
    benchmark_single_keccak_f1600_x4_hybrid_asm_v2();
    benchmark_single_keccak_f1600_x4_hybrid_asm_v3();
    benchmark_single_keccak_f1600_x4_hybrid_asm_v3p();
    benchmark_single_keccak_f1600_x4_hybrid_asm_v4();

    disable_cyclecounter();
#endif /* KECCAK_F1600_TEST_BENCHMARK */

    return( 0 );
}

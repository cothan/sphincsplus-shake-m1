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

#ifndef KECCAK_F1600_X2_TEST_H
#define KECCAK_F1600_X2_TEST_H

#define TEST_WARMUP     10 //100
#define TEST_ITERATIONS 10 //100

#define KECCAK_F1600_TEST_HAVE_SHA3_EXTENSION

#define KECCAK_F1600_TEST_BENCHMARK
#define KECCAK_F1600_TEST_VALIDATE

int validate_keccak_f1600_x1_scalar_C_v0(void);
int validate_keccak_f1600_x1_scalar_C_v1(void);
int validate_keccak_f1600_x1_scalar_asm_v1();
int validate_keccak_f1600_x1_scalar_asm_v2();
int validate_keccak_f1600_x1_scalar_asm_v3();

int validate_keccak_f1600_x4_scalar_asm_v1(void);

int validate_keccak_f1600_x4_hybrid_asm_v1(void);
int validate_keccak_f1600_x4_hybrid_asm_v2(void);
int validate_keccak_f1600_x4_hybrid_asm_v3(void);
int validate_keccak_f1600_x4_hybrid_asm_v3p(void);
int validate_keccak_f1600_x4_hybrid_asm_v4(void);

int validate_keccak_f1600_x2_v84a_asm_v1(void);
int validate_keccak_f1600_x2_v84a_asm_v2(void);
int benchmark_single_keccak_f1600_x2_v84a_asm_v1(void);
int benchmark_single_keccak_f1600_x2_v84a_asm_v2(void);

int benchmark_single_keccak_f1600_x1_scalar_C_original(void);
int benchmark_single_keccak_f1600_x1_scalar_C_v0(void);
int benchmark_single_keccak_f1600_x1_scalar_C_v1(void);

int benchmark_single_keccak_f1600_x1_scalar_asm_v1(void);
int benchmark_single_keccak_f1600_x1_scalar_asm_v2(void);
int benchmark_single_keccak_f1600_x1_scalar_asm_v3(void);

int benchmark_single_keccak_f1600_x4_scalar_asm_v1(void);

int benchmark_single_keccak_f1600_x4_hybrid_asm_v1(void);
int benchmark_single_keccak_f1600_x4_hybrid_asm_v2(void);
int benchmark_single_keccak_f1600_x4_hybrid_asm_v3(void);
int benchmark_single_keccak_f1600_x4_hybrid_asm_v3p(void);
int benchmark_single_keccak_f1600_x4_hybrid_asm_v4(void);


#endif /* KECCAK_F1600_X2_TEST_H */

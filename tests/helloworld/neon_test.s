        .text
        .type neon_test, %function
        .global neon_test
neon_test:
        ldr q0, [x0]
        addv h0, v0.8h
        smov w0, v0.h[0]
        strh w0, [x1]
        ret

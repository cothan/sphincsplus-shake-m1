.PHONY: all clean codegen

# All code generation sources
PYTH_SRCS := $(wildcard *.py) $(wildcard */*.py) $(wildcard */*/*.py) $(wildcard */*/*/*.py)

AUTOGEN_DIR = auto

PY_CODEGEN_NTT_NEON_TEST  = ./scripts/ntt_neon/ntt_neon.py
PY_CODEGEN_NTT_FULL_NEON_TEST  = ./scripts/ntt_neon/ntt_neon_full.py

PY_CODEGEN_NTT_SVE2_TEST  = ./scripts/ntt_sve2/ntt_sve2.py
PY_CODEGEN_NTT_FULL_SVE2_TEST  = ./scripts/ntt_sve2/ntt_sve2_full.py

# Autogenerated files for Neon-NTT
AUTOGEN_NTT_NEON_DIR = $(AUTOGEN_DIR)/ntt_neon
NTT_NEON_SRCS := $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_0_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_1_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_2_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_4_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_5_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_6_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_7_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_8_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_9_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_10_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_11_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_12_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_13_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_14_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_15_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_16_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_17_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_18_0.s      \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_0.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_1.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_2.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_3.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_4.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z2_5.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z4_0.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z4_1.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z4_2.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z4_3.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_full_33556993_28678040_var_4_4_3_z4_4.s    \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_0.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_1.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_2.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_3.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_4.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_5.s       \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_0_0.s     \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_0_z4_16.s   \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_24_z4_0.s   \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_24_z4_16.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_0_z4_0.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_0.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_1.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_2.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_3.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_4.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_5.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_0.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_1.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_2.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_3.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_4.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_5.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_6.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_8.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_9.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_10.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_8_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_9_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_10_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_11_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_12_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_13_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_14_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_15_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_16_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_17_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_18_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_19_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_20_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_21_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_7.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_8.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_9.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_10.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_11.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_12.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_13.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_14.s  \
                 $(AUTOGEN_NTT_NEON_DIR)/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_15.s  \

# Autogenerated files for Sve2-NTT
AUTOGEN_NTT_SVE2_DIR = $(AUTOGEN_DIR)/ntt_sve2
NTT_SVE2_SRCS := $(AUTOGEN_NTT_SVE2_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_0.s                   \
                 $(AUTOGEN_NTT_SVE2_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_1.s                   \
                 $(AUTOGEN_NTT_SVE2_DIR)/ntt_u32_incomplete_33556993_28678040_var_3_3_2.s                   \
                 $(AUTOGEN_NTT_SVE2_DIR)/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_0.s \
                 $(AUTOGEN_NTT_SVE2_DIR)/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_1.s \
                 $(AUTOGEN_NTT_SVE2_DIR)/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_2.s \

# User source files.
AUTOGEN_SRCS := $(NTT_NEON_SRCS) $(NTT_SVE2_SRCS)

CODEGEN_SOURCES = $(wildcard %.s, ./*.py) $(wildcard %.s, ./*/*.py) $(wildcard %.s, ./*/*/*.py) $(wildcard %.s, ./*/*/*/*.py) $(wildcard %.s, ./*/*/*/*/*.py)

.phony: codegen
codegen: $(AUTOGEN_SRCS) $(CODEGEN_SOURCES)

##################################################################################
##                               NEON                                           ##
##################################################################################

# Neon NTT, incomplete

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 0,0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 1,1 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_1

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 2,2 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_2

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_3.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 3,3 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_3

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_4.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 4,4 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_4

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_3_3_5.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 3,3 --schedule 5,5 33556993 28678040 ntt_u32_incomplete_neon_asm_var_3_3_5

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_0_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 0,0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_0_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_0_z4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 0,z4_0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_0_z4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_1 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_1

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_2 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_2

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_3.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_3 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_3

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_4.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_4 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_4

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_3_z4_5.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 3,z4_5 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_3_z4_5

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_1 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_1

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_2 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_2

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_3.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_3 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_3

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_4.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_4 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_4

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_5.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_5 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_5

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_6.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_6 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_6

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_8.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_8 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_8

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_9.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_9 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_9

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_7_z4_10.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 7,z4_10 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_7_z4_10

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_8_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 8,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_8_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_8_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 8,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_8_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_9_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 9,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_9_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_10_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 10,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_10_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_11_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 11,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_11_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_12_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 12,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_12_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_13_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 13,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_13_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_14_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 14,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_14_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_15_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 15,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_15_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_16_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 16,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_16_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_17_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 17,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_17_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_18_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 18,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_18_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_19_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 19,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_19_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_20_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 20,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_20_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_21_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 21,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_21_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_7.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_7 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_7

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_8.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_8 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_8

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_9.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_9 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_9

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_10.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_10 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_10

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_11.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_11 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_11

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_12.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_12 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_12

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_13.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_13 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_13

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_14.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_14 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_14

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_22_z4_15.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 22,z4_15 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_22_z4_15

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_0_z4_16.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 0,z4_16 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_0_z4_16

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_24_z4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 24,z4_0 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_24_z4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_incomplete_33556993_28678040_var_4_2_24_z4_16.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,2 --schedule 24,z4_16 33556993 28678040 ntt_u32_incomplete_neon_asm_var_4_2_24_z4_16

# Neon NTT, complete

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_0_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 0,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_0_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_1_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 1,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_1_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_2_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 2,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_2_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 4,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_5_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 5,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_5_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_6_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 6,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_6_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_7_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 7,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_7_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_8_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 8,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_8_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_9_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 9,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_9_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_10_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 10,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_10_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_11_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 11,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_11_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_12_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 12,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_12_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_13_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 13,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_13_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_14_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 14,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_14_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_15_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 15,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_15_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_16_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 16,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_16_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_17_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 17,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_17_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_18_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 18,0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_18_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_1 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_1

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_2 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_2

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_3.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_3 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_3

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_4.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_4 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_4

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z2_5.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z2_5 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z2_5

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z4_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z4_0 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z4_0

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z4_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z4_1 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z4_1

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z4_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z4_2 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z4_2

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z4_3.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z4_3 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z4_3

$(AUTOGEN_DIR)/ntt_neon/ntt_u32_full_33556993_28678040_var_4_4_3_z4_4.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_NEON_TEST) --out $@ 256 --layers 4,4 --schedule 3,z4_4 33556993 28678040 ntt_u32_full_neon_asm_var_4_4_3_z4_4

##################################################################################
##                               SVE2                                           ##
##################################################################################

# Sve2 NTT, incomplete

$(AUTOGEN_DIR)/ntt_sve2/ntt_u32_incomplete_33556993_28678040_var_3_3_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --out $@ 256 --layers 3,3 --schedule 0,0 33556993 28678040 ntt_u32_incomplete_sve2_asm_var_3_3_0

$(AUTOGEN_DIR)/ntt_sve2/ntt_u32_incomplete_33556993_28678040_var_3_3_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --out $@ 256 --layers 3,3 --schedule 1,11 33556993 28678040 ntt_u32_incomplete_sve2_asm_var_3_3_1

$(AUTOGEN_DIR)/ntt_sve2/ntt_u32_incomplete_33556993_28678040_var_3_3_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --out $@ 256 --layers 3,3 --schedule 2,2 33556993 28678040 ntt_u32_incomplete_sve2_asm_var_3_3_2

$(AUTOGEN_DIR)/ntt_sve2/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_0.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --bitwidth 64 --out $@ 256 --layers 3,3 --schedule 0,0 72057594067788289 60277548896192635 ntt_u64_incomplete_sve2_asm_var_3_3_0

$(AUTOGEN_DIR)/ntt_sve2/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_1.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --bitwidth 64 --out $@ 256 --layers 3,3 --schedule 1,11 72057594067788289 60277548896192635 ntt_u64_incomplete_sve2_asm_var_3_3_1

$(AUTOGEN_DIR)/ntt_sve2/ntt_u64_incomplete_72057594067788289_60277548896192635_var_3_3_2.s: $(PYTH_SRCS)
	mkdir -p $(@D)
	python3 $(PY_CODEGEN_NTT_SVE2_TEST) --bitwidth 64 --out $@ 256 --layers 3,3 --schedule 2,2 72057594067788289 60277548896192635 ntt_u64_incomplete_sve2_asm_var_3_3_2

clean:
	rm -rf $(C_OBJS) $(ASM_OBJS) $(CMSIS_OBJS) $(AUTOGEN_SRCS) $(AUTOGEN_SRCS)
	rm -rf $(TARGET)

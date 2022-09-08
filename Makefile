
CODEGEN_DIR=asm

MANUAL_SRCS_DIR=$(CODEGEN_DIR)/manual
MANUAL_SRCS_KECCAK_NEON_DIR=$(MANUAL_SRCS_DIR)/keccak_f1600

AUTOGEN_SRCS_DIR=$(CODEGEN_DIR)/auto
AUTOGEN_SRCS_NTT_NEON_DIR=$(AUTOGEN_SRCS_DIR)/ntt_neon

AUTOGEN_SRCS_ALL=$(wildcard $(AUTOGEN_SRCS_DIR)/*.s)     \
                 $(wildcard $(AUTOGEN_SRCS_DIR)/*/*.s)   \
                 $(wildcard $(AUTOGEN_SRCS_DIR)/*/*/*.s) \
                 $(wildcard $(AUTOGEN_SRCS_DIR)/*/*/*/*/*.s)

MANUAL_SRCS_ALL=$(wildcard $(MANUAL_SRCS_DIR)/*.s)     \
                $(wildcard $(MANUAL_SRCS_DIR)/*/*.s)   \
                $(wildcard $(MANUAL_SRCS_DIR)/*/*/*.s) \
                $(wildcard $(MANUAL_SRCS_DIR)/*/*/*/*/*.s)

AUTOGEN_SRCS_NTT_NEON_ALL=$(wildcard $(AUTOGEN_SRCS_NTT_NEON_DIR)/*.s)     \
                          $(wildcard $(AUTOGEN_SRCS_NTT_NEON_DIR)/*/*.s)   \
                          $(wildcard $(AUTOGEN_SRCS_NTT_NEON_DIR)/*/*/*.s) \
                          $(wildcard $(AUTOGEN_SRCS_NTT_NEON_DIR)/*/*/*/*.s)

MANUAL_SRCS_KECCAK_NEON_ALL=$(wildcard $(MANUAL_SRCS_KECCAK_NEON_DIR)/*.[sch])     \
                      $(wildcard $(MANUAL_SRCS_KECCAK_NEON_DIR)/*/*.[sch])   \
                      $(wildcard $(MANUAL_SRCS_KECCAK_NEON_DIR)/*/*/*.[sch]) \
                      $(wildcard $(MANUAL_SRCS_KECCAK_NEON_DIR)/*/*/*/*.[sch])

TEST_BASE_DIR=tests

# Directory and sources for Helloworld dummy test
TEST_HELLOWORLD_DIR=$(TEST_BASE_DIR)/helloworld
TEST_HELLOWORLD_SOURCES_AUTO_DIR=$(TEST_HELLOWORLD_DIR)/auto
TEST_HELLOWORLD_SRC_C=$(wildcard $(TEST_HELLOWORLD_DIR)/*.c) \
                      $(wildcard $(TEST_HELLOWORLD_DIR)/*/*.c)
TEST_HELLOWORLD_SRC_ALL=$(TEST_HELLOWORLD_SRC_C)

# Directory and sources for Neon-NTT test
TEST_NTT_NEON_DIR=$(TEST_BASE_DIR)/ntt_neon
TEST_NTT_NEON_SOURCES_AUTO_DIR=$(TEST_NTT_NEON_DIR)/auto
TEST_NTT_NEON_SRC_C=$(wildcard $(TEST_NTT_NEON_DIR)/*.c) \
                    $(wildcard $(TEST_NTT_NEON_DIR)/*/*.c)
TEST_NTT_NEON_SRC_AUTO=$(patsubst $(AUTOGEN_SRCS_NTT_NEON_DIR)/%.s,      \
                                  $(TEST_NTT_NEON_SOURCES_AUTO_DIR)/%.s, \
                                  $(AUTOGEN_SRCS_NTT_NEON_ALL))
TEST_NTT_NEON_SRC_ALL=$(TEST_NTT_NEON_SRC_C) $(TEST_NTT_NEON_SRC_AUTO)

# Directory and sources for KECCAK test
TEST_KECCAK_NEON_DIR=$(TEST_BASE_DIR)/keccak_neon
TEST_KECCAK_NEON_SRC_C=$(wildcard $(TEST_KECCAK_NEON_DIR)/*.c) \
                       $(wildcard $(TEST_KECCAK_NEON_DIR)/*/*.c)
TEST_KECCAK_NEON_SOURCES_MANUAL_DIR=$(TEST_KECCAK_NEON_DIR)/manual
TEST_KECCAK_NEON_SRC_MANUAL__=$(patsubst $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.s,    \
                                  $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.s, \
                                  $(MANUAL_SRCS_KECCAK_NEON_ALL))
TEST_KECCAK_NEON_SRC_MANUAL_=$(patsubst $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.c,    \
                                  $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.c, \
                                  $(TEST_KECCAK_NEON_SRC_MANUAL__))
TEST_KECCAK_NEON_SRC_MANUAL=$(patsubst $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.h,    \
                                  $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.h, \
                                  $(TEST_KECCAK_NEON_SRC_MANUAL_))

TEST_KECCAK_NEON_SRC_ALL=$(TEST_KECCAK_NEON_SRC_C) $(TEST_KECCAK_NEON_SRC_MANUAL)


# All sources
TEST_SRC_AUTO_ALL= $(TEST_NTT_NEON_SRC_AUTO) $(TEST_KECCAK_NEON_SRC_MANUAL)

#
# Test environments
#

TEST_ENVS_BASE_DIR=envs

# QEMU test environment
TEST_ENV_CROSS_BASE=$(TEST_ENVS_BASE_DIR)/cross
TEST_ENV_CROSS_SRC=$(TEST_ENV_CROSS_BASE)/src
TEST_ENV_CROSS_SYMLINK=$(TEST_ENV_CROSS_SRC)/test_src

# Native test environment
TEST_ENV_NATIVE_BASE=$(TEST_ENVS_BASE_DIR)/native
TEST_ENV_NATIVE_SRC=$(TEST_ENV_NATIVE_BASE)/src
TEST_ENV_NATIVE_SYMLINK=$(TEST_ENV_NATIVE_SRC)/test_src


# Code generation files
PYTHON_SRCS=$(wildcard $(CODEGEN_DIR)/*.py)          \
            $(wildcard $(CODEGEN_DIR)/*/*.py)        \
            $(wildcard $(CODEGEN_DIR)/*/*/*.py)      \
            $(wildcard $(CODEGEN_DIR)/*/*/*/*/*.py)

.PHONY: all
all: codegen $(TEST_SRC_AUTO_ALL)

.PHONY: clean
clean:
	make clean -C $(TEST_ENV_CROSS_BASE)
	make clean -C $(TEST_ENV_NATIVE_BASE)
	rm -f $(TEST_SRC_AUTO_ALL)
	rm -f $(TEST_ENV_CROSS_SYMLINK)
	rm -f $(TEST_ENV_NATIVE_SYMLINK)

.PHONY: cleanasm
cleanasm:
	make clean -C $(CODEGEN_DIR)

.PHONY: cleanall
cleanall: clean cleanasm

$(AUTOGEN_SRCS_ALL): $(PYTHON_SRCS)
	make -C $(CODEGEN_DIR)

$(TEST_NTT_NEON_SRC_AUTO): $(TEST_NTT_NEON_SOURCES_AUTO_DIR)/%.s: $(AUTOGEN_SRCS_NTT_NEON_DIR)/%.s
	mkdir -p $(@D)
	cp $< $@

$(TEST_KECCAK_NEON_SRC_MANUAL): $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.c: $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.c
	mkdir -p $(@D)
	cp $< $@
$(TEST_KECCAK_NEON_SRC_MANUAL): $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.s: $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.s
	mkdir -p $(@D)
	cp $< $@
$(TEST_KECCAK_NEON_SRC_MANUAL): $(TEST_KECCAK_NEON_SOURCES_MANUAL_DIR)/%.h: $(MANUAL_SRCS_KECCAK_NEON_DIR)/%.h
	mkdir -p $(@D)
	cp $< $@

.PHONY: codegen
codegen:
	make codegen -C $(CODEGEN_DIR)

# Template on CROSS

TEST_ENV_CROSS_LINK_HELLOWORLD = $(TEST_ENV_CROSS_BASE)/test_loaded_helloworld
$(TEST_ENV_CROSS_LINK_HELLOWORLD):
	rm -f $(TEST_ENV_CROSS_SYMLINK)
	ln -s ../../../$(TEST_HELLOWORLD_DIR) $(TEST_ENV_CROSS_SYMLINK)
	rm -f $(TEST_ENV_CROSS_BASE)/test_loaded_*
	make -C $(TEST_ENV_CROSS_BASE) clean
	touch $@

.PHONY: build-cross-helloworld
build-cross-helloworld: $(TEST_ENV_CROSS_LINK_HELLOWORLD)
	make -C $(TEST_ENV_CROSS_BASE)

.PHONY: run-cross-helloworld
run-cross-helloworld: $(TEST_ENV_CROSS_LINK_HELLOWORLD)
	make run -C $(TEST_ENV_CROSS_BASE)

# NTT test on cross

TEST_ENV_CROSS_LINK_NTT_NEON = $(TEST_ENV_CROSS_BASE)/test_loaded_ntt_neon
$(TEST_ENV_CROSS_LINK_NTT_NEON): $(TEST_NTT_NEON_SRC_AUTO)
	rm -f $(TEST_ENV_CROSS_SYMLINK)
	ln -s ../../../$(TEST_NTT_NEON_DIR) $(TEST_ENV_CROSS_SYMLINK)
	rm -f $(TEST_ENV_CROSS_BASE)/test_loaded_*
	make -C $(TEST_ENV_CROSS_BASE) clean
	touch $@

.PHONY: build-cross-ntt_neon
build-cross-ntt_neon: $(TEST_ENV_CROSS_LINK_NTT_NEON)
	make -C $(TEST_ENV_CROSS_BASE)

.PHONY: run-cross-ntt_neon
run-cross-ntt_neon: $(TEST_ENV_CROSS_LINK_NTT_NEON)
	make run -C $(TEST_ENV_CROSS_BASE)

.PHONY: debug-cross-ntt_neon
debug-cross-ntt_neon: $(TEST_ENV_CROSS_LINK_NTT_NEON)
	make debug -C $(TEST_ENV_CROSS_BASE)

# Keccak on CROSS

TEST_ENV_CROSS_LINK_KECCAK_NEON = $(TEST_ENV_CROSS_BASE)/test_loaded_keccak_neon
$(TEST_ENV_CROSS_LINK_KECCAK_NEON): $(TEST_KECCAK_NEON_SRC_MANUAL)
	rm -f $(TEST_ENV_CROSS_SYMLINK)
	ln -s ../../../$(TEST_KECCAK_NEON_DIR) $(TEST_ENV_CROSS_SYMLINK)
	rm -f $(TEST_ENV_CROSS_BASE)/test_loaded_*
	make -C $(TEST_ENV_CROSS_BASE) clean
	touch $@

.PHONY: build-cross-keccak_neon
build-cross-keccak_neon: $(TEST_ENV_CROSS_LINK_KECCAK_NEON)
	make -C $(TEST_ENV_CROSS_BASE)

.PHONY: run-cross-keccak_neon
run-cross-keccak_neon: $(TEST_ENV_CROSS_LINK_KECCAK_NEON)
	make run -C $(TEST_ENV_CROSS_BASE)


# Keccak native

TEST_ENV_NATIVE_LINK_KECCAK_NEON = $(TEST_ENV_NATIVE_BASE)/test_loaded_keccak_neon
$(TEST_ENV_NATIVE_LINK_KECCAK_NEON): $(TEST_KECCAK_NEON_SRC_MANUAL)
	rm -f $(TEST_ENV_NATIVE_SYMLINK)
	ln -s ../../../$(TEST_KECCAK_NEON_DIR) $(TEST_ENV_NATIVE_SYMLINK)
	rm -f $(TEST_ENV_NATIVE_BASE)/test_loaded_*
	make -C $(TEST_ENV_NATIVE_BASE) clean
	touch $@

.PHONY: build-native-keccak_neon
build-native-keccak_neon: $(TEST_ENV_NATIVE_LINK_KECCAK_NEON)
	make -C $(TEST_ENV_NATIVE_BASE)

.PHONY: run-native-keccak_neon
run-native-keccak_neon: $(TEST_ENV_NATIVE_LINK_KECCAK_NEON)
	make run -C $(TEST_ENV_NATIVE_BASE)

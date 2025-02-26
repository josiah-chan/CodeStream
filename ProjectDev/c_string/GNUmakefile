# 编译器设置
CC ?= gcc
CFLAGS += -Wall -Wextra -I./include -std=c11
LDFLAGS += -static

# 目录
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = $(BUILD_DIR)/lib
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj
TEST_DIR = test

# 源文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c) $(wildcard $(TEST_DIR)/unit/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.c=$(OBJ_DIR)/test/%.o)

# 目标文件
LIB = $(LIB_DIR)/libc_string.a
TEST_BIN = $(BIN_DIR)/test_runner

.PHONY: all clean test dirs

all: dirs $(LIB)

dirs:
	@mkdir -p $(BUILD_DIR) $(LIB_DIR) $(BIN_DIR) $(OBJ_DIR) $(OBJ_DIR)/test

# 编译库
$(LIB): $(OBJS)
	@mkdir -p $(dir $@)
	ar rcs $@ $^

# 编译源文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# 编译和运行测试
test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJS) $(LIB)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/test/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
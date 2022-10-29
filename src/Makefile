CC = gcc

WARNING    = -Wall -Werror -Wextra
CFLAGS     = -std=c11 -pedantic $(WARNING)
LFLAGS    ?= $(shell pkg-config --cflags --libs check)
INC_CHECK ?= $(shell pkg-config --cflags check)

SRC_DIR  = .
SRC     := $(shell find $(SRC_DIR) -name "s21*.c" | sed -e 's/\.\///')

TEST_DIR    = tests
TEST       := $(shell find $(TEST_DIR) -name "*.c" | sed -e 's/\.\///')
TEST_FLAGS := --coverage -c -g

INC_DIRS   := $(shell find $(SRC_DIR) -type d)
INC_FLAGS  := $(addprefix -I, $(INC_DIRS))

BUILD_DIR       = obj
BUILD_TEST_DIR  = obj_test
GCOV_OBJ_DIR   := gcov_res

OBJS      := $(SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST:%.c=$(BUILD_TEST_DIR)/%.o)
GCOV_OBJS := $(SRC:%.c=$(GCOV_OBJ_DIR)/%.o)

DEC_TEST := calculate_t.c
LIB      := s21_calc.a
lgtk=$(shell pkg-config --cflags gtk+-3.0)
llgtk=$(shell pkg-config --libs gtk+-3.0)

#all: algo #example

all: $(LIB) test

test: test.out
	./test.out

algo:
	gcc stack/stack.c calculate/parse_calc.c -o hello

# example:
# 	gcc $(lgtk) -o example-0 gui/example-0.c $(llgtk) 
# 
# example1:
# 	gcc $(lgtk) -o example-1 gui/example-1.c $(llgtk) 
# 
# example2:
# 	gcc $(lgtk) -o example-2 gui/example-2.c $(llgtk) 

example3:
	gcc $(lgtk) -o example-3 gui/example-3.c $(llgtk) 

rebuild: clean all

.PHONY: clean rebuild lint 
clean: 
	rm -f *.gcda *.gcov *.o *.gcno
	rm -f $(LIB)
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_TEST_DIR)
	rm -rf $(GCOV_OBJ_DIR)
	rm -f test.out

test.out: $(LIB) $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o
	$(CC) $(CFLAGS) $(LFLAGS) $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o $(LIB) -o test.out

$(LIB): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

gcov_report: $(TEST_OBJS) $(GCOV_OBJS) $(BUILD_TEST_DIR)/main.o $(SRC)
	@mkdir -p $(GCOV_OBJ_DIR)
	ar rc $(LIB) $(GCOV_OBJS)
	ranlib $(LIB)
	$(CC) $(LFLAGS) --coverage $(TEST_OBJS) $(BUILD_TEST_DIR)/main.o $(LIB) -o test.out
	- ./test.out
	./../materials/lcov/bin/lcov -f -c --directory . -o ./gcov_res/coverage.info 
	./../materials/lcov/bin/genhtml gcov_res/coverage.info --output-directory=gcov_res
	open gcov_res/index.html

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_TEST_DIR)/main.o: $(DEC_TEST) 
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(CFLAGS) $(INC_CHECK) -c -o $(BUILD_TEST_DIR)/main.o $(DEC_TEST)

$(BUILD_TEST_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_CHECK) -c $^ -o $@

$(GCOV_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(TEST_FLAGS) -c $< -o $@

#leaks: test.out

lint:
	-cp ../materials/linters/.clang-format .
	-find . -type f -name "*.c" | xargs clang-format -n
	-find . -type f -name "*.h" | xargs clang-format -n
	-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

flint: lint
	-find . -type f -name "*.c" | xargs clang-format --style=Google -i
	-find . -type f -name "*.h" | xargs clang-format --style=Google -i


lgtk=$(shell pkg-config --cflags gtk+-3.0)
llgtk=$(shell pkg-config --libs gtk+-3.0)

all:
	gcc $(lgtk) -o example-0 example-0.c $(llgtk) 

rebuild: clean all

.PHONY: clean rebuild lint 
clean: 
	rm -f *.gcda *.gcov *.o *.gcno
	rm -f $(LIB)
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_TEST_DIR)
	rm -rf $(GCOV_OBJ_DIR)
	rm -f test.out

#leaks: test.out

lint:
	-cp ../materials/linters/.clang-format .
	-find . -type f -name "*.c" | xargs clang-format -n
	-find . -type f -name "*.h" | xargs clang-format -n
	-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

flint: lint
	clang-format --style=file -i *.c */*.c *.h */*.h
	

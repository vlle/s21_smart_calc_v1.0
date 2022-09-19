lgtk=$(shell pkg-config --cflags gtk+-3.0)
llgtk=$(shell pkg-config --libs gtk+-3.0)

all: algo #example

algo:
	gcc stack/stack.c calculate/parse_calc.c -o hello


example:
	gcc $(lgtk) -o example-0 gui/example-0.c $(llgtk) 

example1:
	gcc $(lgtk) -o example-1 gui/example-1.c $(llgtk) 

example2:
	gcc $(lgtk) -o example-2 gui/example-2.c $(llgtk) 

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

#leaks: test.out

lint:
	-cp ../materials/linters/.clang-format .
	-find . -type f -name "*.c" | xargs clang-format -n
	-find . -type f -name "*.h" | xargs clang-format -n
	-find . -type f -name "*.c" | xargs cppcheck --enable=all --suppress=missingIncludeSystem

flint: lint
	-find . -type f -name "*.c" | xargs clang-format --style=Google -i
	-find . -type f -name "*.h" | xargs clang-format --style=Google -i
	

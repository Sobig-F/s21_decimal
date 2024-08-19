CC         = gcc
CFLAGS     = -Wall -Werror -Wextra -std=c11
GCOVFLAGS  = -fprofile-arcs -ftest-coverage
LIB_NAME   = s21_decimal.a
SOURCE     = *.c
OBJ        = $(SOURCE:.c=.o)
TSRC       = tests/s21_test*.c
CHECKFLAGS = -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit

# ifeq ($(OS), Ubuntu)
# 	CFLAGS+=           -D OS_LINUX
# 	CHECKFLAGS=        -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
# 	OPEN_CMD=          xdg-open
# endif
# ifeq ($(OS), Darwin)
# 	CFLAGS+=           -D OS_MAC
# 	CHECKFLAGS=        $(shell pkg-config --cflags --libs check)
# 	#CHECKFLAGS=       -lcheck
# 	OPEN_CMD=          open
# endif

all: clean $(LIB_NAME)

$(LIB_NAME):
	$(CC) $(CFLAGS) -c $(SOURCE)
	ar rc $(LIB_NAME) $(OBJ)
	ranlib $(LIB_NAME)

test: clean
	$(CC) $(CFLAGS) $(SOURCE) $(TSRC) $(CHECKFLAGS) -o test
	./test
	# valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

gcov_report: rebuild
	$(CC) $(GCOVFLAGS) $(TSRC) $(SOURCE) $(CHECKFLAGS) -lm -o GcovReport
	./GcovReport
	lcov -t "GcovReport" -o GcovReport.info -c -d .
	genhtml -o gcov_report GcovReport.info
	rm -rf ./*.gcno ./*gcda ./GcovReport
	open ./gcov_report/index.html


rebuild: clean $(LIB_NAME)

style: 
	clang-format -style=Google -n *.h *.c ./tests/*.c ./tests/*.h

clean:
	rm -rf $(OBJ) $(LIB_NAME) s21_decimal *.gc* ./test gcov_report GcovReport GcovReport.info

clang:
	clang-format -n -style=Google *.c *.h

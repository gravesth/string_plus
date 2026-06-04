CС = gcc 
CLAGS = -Wall -Werror -Wextra -Include

# TEST_TARGET = gcov_report
TARGET = s21_string.a

OBJ = s21_memchr.o 

$(TARGET): $(OBJ)
	ar -cvq $(TARGET) $(OBJ)

all: $(TARGET)

s21_memchr.o: s21_memchr.c
	$(CC) -c mem/s21_memchr.c -o mem/s21_memchr.o

strncpy/s21_strncpy.o: strncpy/s21_strncpy.c
	$(CC) -c strncpy/s21_strncpy.c -o strncpy/s21_strncpy.o


# test:

style:
	clang-format -i *.c *.h

clean:
	rm -f $(TARGET)

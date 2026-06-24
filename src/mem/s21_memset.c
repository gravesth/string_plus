#include "../s21_string.h"
// заполнение блока памяти заданным значением
// str - указатель на блок памяти
// c - значение для заполнения (
// n - количество байт для заполнения
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char val = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = val;
  }
  return str;
}

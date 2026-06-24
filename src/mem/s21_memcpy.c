#include "../s21_string.h"
// функция для копирования блоков памяти 
// dest - указатель на буфер назначения(куда копируем)
// src - указатель на исходный буфер
// n - количество байт для копирования
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}
#include <string.h>

#include "../../s21_string.h"
#include "../test_runner.h"

//tc_basic 

START_TEST(start_symbol_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "a"), strpbrk("abcd", "a"));
}END_TEST

START_TEST(end_symbol_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "d"), strpbrk("abcd", "d"));
}END_TEST

START_TEST(center_symbol_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "b"), strpbrk("abcd", "b"));
}END_TEST

START_TEST(some_symbol_test1)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "bfgh"), strpbrk("abcd", "bfgh"));
}END_TEST

START_TEST(some_symbol_test2)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "bdfg"), strpbrk("abcd", "bdfg"));
}END_TEST

//tc_empty
START_TEST(empty_str1_test)
{
    ck_assert_ptr_eq(s21_strpbrk("", "bdfg"), strpbrk("", "bdfg"));
}END_TEST

START_TEST(empty_str2_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abc", ""), strpbrk("abc", ""));
}END_TEST

START_TEST(empty_str_test)
{
    ck_assert_ptr_eq(s21_strpbrk("", ""), strpbrk("", ""));
}END_TEST

//tc_specific

START_TEST(register_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "ABCD"), strpbrk("abcd", "ABCD"));
}END_TEST

START_TEST(null_test)
{
    ck_assert_ptr_eq(s21_strpbrk("abcd", "AB\0CD"), strpbrk("abcd", "AB\0CD"));
}END_TEST

START_TEST(special_symbol_test)
{
    ck_assert_ptr_eq(s21_strpbrk("ab\tcd", "AB\tCD"), strpbrk("ab\tcd", "AB\tCD"));
}END_TEST

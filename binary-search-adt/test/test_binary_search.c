#include "vendor/unity.h"
#include "../src/binary_search.h"
#include <stdlib.h>

void setUp(void)
{
}

void tearDown(void)
{
}

int8_t compare (const void* key, const void* value)
{
	if (*(int*)key == *(int*)value) { return 0; }
	if (*(int*)key < *(int*)value) { return -1; }
	if (*(int*)key > *(int*)value) { return 1; }
	exit(11);
}

void test_single_element(void)
{
   int arr[] = { 6 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[0], (int*) binary_search(&arr[0], arr, length, sizeof(arr[0]), compare));
}

void test_value_in_middle(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[3], (int*) binary_search(&arr[3], arr, length, sizeof(arr[0]), compare));
}

void test_value_at_beginning(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[0], binary_search(&arr[0], arr, length, sizeof(arr[0]), compare));
}

void test_value_at_end(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11, 12 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[7], binary_search(&arr[7], arr, length, sizeof(arr[0]), compare));
}

void test_find_value_with_odd_length(void)
{
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[9], binary_search(&arr[9], arr, length, sizeof(arr[0]), compare));
}

void test_find_value_with_even_length(void)
{
   int arr[] = { 1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(&arr[5], binary_search(&arr[5], arr, length, sizeof(arr[0]), compare));
}

void test_identify_missing_value(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(NULL, binary_search(&arr[7], arr, length, sizeof(arr[0]), compare));
}

void test_value_smaller_than_everything(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   int key[] = { 0 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(NULL, binary_search(key, arr, length, sizeof(arr[0]), compare));
}

void test_value_larger_than_everything(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
   int key[] = { 12 };
   size_t length = sizeof(arr) / sizeof(arr[0]);
   TEST_ASSERT_EQUAL_PTR(NULL, binary_search(key, arr, length, sizeof(arr[0]), compare));
}

void test_empty_array(void)
{
   int *arr = NULL;
   int key[] = { 12 };
   size_t length = 0;
   TEST_ASSERT_EQUAL_PTR(NULL, binary_search(key, arr, length, sizeof(arr[0]), compare));
}

void test_zero_length_array(void)
{
   int arr[] = { 1 };
   size_t length = 0;
   TEST_ASSERT_EQUAL_PTR(NULL, binary_search(&arr[0], arr, length, sizeof(arr[0]), compare));
}

int main(void)
{
   UnityBegin("test/test_binary_search.c");

   RUN_TEST(test_single_element);
   RUN_TEST(test_value_in_middle);
   RUN_TEST(test_value_at_beginning);
   RUN_TEST(test_value_at_end);
   RUN_TEST(test_find_value_with_odd_length);
   RUN_TEST(test_find_value_with_even_length);
   RUN_TEST(test_identify_missing_value);
   RUN_TEST(test_value_smaller_than_everything);
   RUN_TEST(test_value_larger_than_everything);
   RUN_TEST(test_empty_array);
   RUN_TEST(test_zero_length_array);

   UnityEnd();
   return 0;
}

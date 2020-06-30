// 16 lab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>

int main()
{
	int array_of_ints[] = { 1,2,3,4,5,6,7,8,9,0 };
	int size = sizeof(array_of_ints);

	/* 1 */
	HANDLE h = HeapCreate(HEAP_NO_SERIALIZE, size, size);
	if (!h)
	{
		puts("Heap doesn't create");
		return -1;
	}
	int* arr = NULL;
	arr = (int*)HeapAlloc(h, NULL, size); //распределяем память кучи под массив
	for (int i = 0; i < size / sizeof(int); ++i)
	{
		arr[i] = array_of_ints[i];
		printf("%d ", arr[i]);
	}
	/* 2 */
	arr = (int*)HeapReAlloc(h, NULL, arr, size += 2); //адрес перераспределяемой памяти
	arr[size / sizeof(int)] = 11;
	printf("\narr[size] = %d\n", arr[size / sizeof(int)]);
	for (int i = 0; i <= size / sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	/* 3 */
	arr[size / sizeof(int)] = 0;
	arr = (int*)HeapReAlloc(h, NULL, arr, size -= 2);
	printf("\narr[size] = %d\n", arr[(size / sizeof(int)) - 1]);
	for (int i = 0; i < size / sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	/* 4 */
	int index = 3;
	int value = 10;
	arr = (int*)HeapReAlloc(h, NULL, arr, size + 2);
	for (int i = size / sizeof(int); i >= index; --i)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = value;
	for (int i = 0; i < (size / sizeof(int)) + 1; ++i)
		printf("%d ", arr[i]);

	printf("\n");
	/* 5 */
	int idx = 3;
	arr = (int*)HeapReAlloc(h, NULL, arr, size);
	for (int i = idx; i < size / sizeof(int); ++i)
	{
		arr[i] = arr[i + 1];
	}
	for (int i = 0; i < (size / sizeof(int)); ++i)
		printf("%d ", arr[i]);
	printf("\n");
	system("pause");
    return 0;
}


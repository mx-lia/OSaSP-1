
// 1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;


typedef struct books
{
	char* title;
} my_books, * p_mybooks;

int main()
{
	int i, n, m;

	setlocale(LC_ALL, "RUS");

	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	p_mybooks* p_massiv = new p_mybooks[n];
	int* size_array = new int[n];

	if (!p_massiv)                              //проверка факта выделения памяти
	{
		return 0;
	}
	cout << "Введите размер массива структур\n";
	cin >> m;//ввод размера массива
	for (i = 0; i < n; i++)
	{
		p_mybooks p_mystruct = new my_books[m];
		size_array[i] = m;
		cout << "Введите массив из строк\n";
		string buf;
		for (int k = 0; k < m; k++)
		{
			cin >> buf;       //ввод массива
			p_mystruct[k].title = (char*)malloc((sizeof(buf) + 1) * sizeof(char));
			buf.push_back('\0');
			buf.copy(p_mystruct[k].title, buf.size());
		}

		p_massiv[i] = p_mystruct;
	}


	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
	{
		cout << " Array number " << i << endl;
		for (int k = 0; k < size_array[i]; k++)
		{
			cout << " Struct number " << k << endl;
			cout << ' ' << p_massiv[i][k].title << endl << endl;       //вывод массива
		}
		cout << "------------------------" << endl;
	}

	free(p_massiv);
	_getch();
	return 0;
}

// 1_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
	int i, n;
	char** massiv;
	setlocale(LC_ALL, "RUS");
	cout << "Введите размер массива\n";
	cin >> n;//ввод размера массива

	massiv = (char**)malloc(n * sizeof(char*));      

	if (!massiv)                              
		return 0;

	cout << "Введите массив \n";

	string buf;
	for (i = 0; i < n; i++)
	{
		cin >> buf;       //ввод массива
		massiv[i] = (char*)malloc((sizeof(buf) + 1) * sizeof(char));
		buf.push_back('\0');
		buf.copy(massiv[i], buf.size());
	}

	cout << "\n massiv\n";
	for (i = 0; i < n; i++)
		cout << ' ' << massiv[i];       //вывод массива

	free(massiv);
	_getch();
	return 0;
}

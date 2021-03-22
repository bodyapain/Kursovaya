#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>

using namespace std;


void matinkonsol(int** arr, int size) //заполнение матрицы через консоль

{
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			cin >> arr[i][j];

}

void matoutkonsol(int** arr, int size) //вывод матрицы через консоль
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
}

void matinfile(int** arrA, int** arrB, int** arrC, int size)//вводматрицсфайла

{
	int i, j;	
	ifstream fin;
	fin.open("data.txt");
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			fin >> arrA[i][j];
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			fin >> arrB[i][j];
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			fin >> arrC[i][j];
	fin.close();
}

void matoutfile(int** arrA, int** arrB, int** arrC, int size)//выводматрицвфайл
{
	setlocale(LC_ALL, "Russian");
	int i, j;
	ofstream fout;
	fout.open("results.txt");
	fout << "Матрица А\n";
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			fout << arrA[i][j] << " ";
		fout << "\n";
	}
	fout << "Матрица В\n";
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			fout << arrB[i][j] << " ";
		fout << "\n";
	}
	fout << "Матрица С\n";
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			fout << arrC[i][j] << " ";
		fout << "\n";
	}
	fout.close();
}

void clear(int** arrA, int** arrB, int** arrC, int size) //освобождение памяти
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		delete[] arrA[i];
		delete[] arrB[i];
		delete[] arrC[i];
	}
	delete[] arrA, arrB, arrC;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int size, k, i, j, x, ** arrA, ** arrB, ** arrC;
	begin:
	cout << "Выберите способ ввода данных о матрице:\n" //выбор способа ввода данных
		<< "1)C клавиатуры\n" << "2)Файлом\n";
	cin >> k;
	cout << "Введите размер квадратных матриц:";//создание динамических структур данных
	cin >> size;
	arrA = new int* [size];
	arrB = new int* [size];
	arrC = new int* [size];
	for (i = 0; i < size; i++)
	{
		arrA[i] = new int[size];
		arrB[i] = new int[size];
		arrC[i] = new int[size];
	}
	switch (k) //ввод данных
	{
	case 1: //ввод с клавиатуры
		cout << "Построчно введите значения элементов матрицы A: "; //матрица A
		matinkonsol(arrA, size);
		cout << "Построчно введите значения элементов матрицы B: "; //матрица В
		matinkonsol(arrB, size);
		cout << "Построчно введите значения элементов матрицы C: "; //матрица C
		matinkonsol(arrC, size);
		break;
	case 2:
		matinfile(arrA, arrB, arrC, size); //ввод матриц через файл
		break;
	default:
		cout << "!Введите верный номер пункта меню!\n";
		goto begin;
		break;
	}
menu:
	cout << "1)Редактировать элементы матрицы\n" << "2)Ввести данные заново\n" //функциональное меню
		<< "3)Нормировать элементы всех матриц значением максимального элемента матрицы\n"
		<< "4)Заменить в матрице С нулями те элементы, которые равны максимуму какого-либо столбца в матрице А или какой-либо строки в матрице В\n"
		<< "5)Вывод матриц\n"
		<< "6)Закончить выполнение программы\n";
	cin >> k;
	switch (k) //реализация элементов меню
	{
	case 1: //редактирование матриц
		cout << "Выберите матрицу, в которой желаете заменить элемент:\n1)А\n2)В\n3)С\n";
		cin >> k;
	r_1:
		cout << "Введите строку редактируемого элемента: ";
		cin >> i;
		if (i > size)
		{
			cout << "!Такой строки не существует!\n";
			goto r_1;
		}
		i--;
	r_2:
		cout << "Введите столбец редактируемого элемента: ";
		cin >> j;
		if (j > size)
		{
			cout << "!Такого столбца не существует!\n";
			goto r_2;
		}
		j--;
		cout << "Введите значение, которое нужно присвоить этому элементу: ";
		cin >> x;
		switch (k)
		{
		case 1:
			arrA[i][j] = x;
			break;
		case 2:
			arrB[i][j] = x;
			break;
		case 3:
			arrC[i][j] = x;
			break;
		default:
			break;
		}
		goto menu;
		break;
	case 2:
		clear(arrA, arrB, arrC, size); //ввод данных заново
		goto begin;
		break;
	case 3: //1 индивидуальное задание: Нормировать элементы всех матриц значением максимального элемента матрицы
	{
		int max = arrA[0][0];
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (arrA[i][j] > max) {
					max = arrA[i][j];
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				arrA[i][j] = max;
			}
		}
		max = arrB[0][0];
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (arrB[i][j] > max) {
					max = arrB[i][j];
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				arrB[i][j] = max;
			}
		}
		max = arrC[0][0];
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (arrC[i][j] > max) {
					max = arrC[i][j];
				}
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				arrC[i][j] = max;
			}
		}
		goto menu;
		
	}
	break;
	case 4: //2 индивидуальное задание: Заменить в матрице С нулями те элементы, которые равны максимуму какого-либо столбца в матрице А или какой-либо строки в матрице В
	{
		
		for (i = 0; i < size; i++)
		{
			int maxA = arrA[i][0];
			for (j = 0; j < size; j++)
			{
				if (arrA[i][j] > maxA) {
					maxA = arrA[i][j];
				}				
			}
			for (int h = 0; h < size; h++)
			{
				for (int t = 0; t < size; t++)
				{
					if (arrC[h][t] == maxA)
					{
						arrC[h][t] = 0;
					}
				}
			}			
		}
		for (j = 0; j < size; j++)
		{
			int maxA = arrA[0][j];
			for (i = 0; i < size; i++)
			{
				if (arrA[i][j] > maxA) {
					maxA = arrA[i][j];
				}
			}
			for (int h = 0; h < size; h++)
			{
				for (int t = 0; t < size; t++)
				{
					if (arrC[h][t] == maxA)
					{
						arrC[h][t] = 0;
					}
				}
			}
			
		}
		
		for (i = 0; i < size; i++)
		{
			int maxB = arrB[i][0];
			for (j = 0; j < size; j++)
			{
				if (arrB[i][j] > maxB) {
					maxB = arrB[i][j];
				}				
			}
			for (int h = 0; h < size; h++)
			{
				for (int t = 0; t < size; t++)
				{
					if (arrC[h][t] == maxB)
					{
						arrC[h][t] = 0;
					}
				}
			}
			
		}	
		for (j = 0; j < size; j++)
		{
			int maxB = arrB[0][j];
			for (i = 0; i < size; i++)
			{
				if (arrB[i][j] > maxB) {
					maxB = arrB[i][j];
				}
			}
			for (int h = 0; h < size; h++)
			{
				for (int t = 0; t < size; t++)
				{
					if (arrC[h][t] == maxB)
					{
						arrC[h][t] = 0;
					}
				}
			}			
		}
		goto menu;
	}
		break;
	case 5:
		cout << "Выберите способ вывода матрицы:\n1)В консоль\n2)В файл\n"; //вывод матриц
		cin >> k;
		switch (k)
		{
		case 1: //вывод в консоль
			cout << "Выберите матрицу, которую желаете вывести:\n1)А\n2)В\n3)С\n";
			cin >> k;
			switch (k)
			{
			case 1:
				matoutkonsol(arrA, size);
				break;
			case 2:
				matoutkonsol(arrB, size);
				break;
			case 3:
				matoutkonsol(arrC, size);
				break;
			default:
				break;
			}
			break;
		case 2: //вывод в файл
			matoutfile(arrA, arrB, arrC, size);
			cout << "Результат успешно сохранён в файле results.txt\n";
			break;
		default:
			break;
		}
		goto menu;
		break;
	case 6: //завершение программы
		goto end;
		break;
	default:
		cout << "!Введите верный номер меню!\n";
		goto menu;
		break;
	}
end:
	clear(arrA, arrB, arrC, size);
	return 0;
}
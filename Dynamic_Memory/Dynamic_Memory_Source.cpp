﻿#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimeter "\n------------------------------------\n"

int** Allocate(const int rows, const int cols); 
void Clear(int** arr, const int rows);



void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);

int** push_row_back(int** arr,  int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);


int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, const int cols);

void** pop_col_front(int** arr, const int rows, int& cols);
void** pop_col_back(int** arr, const int rows, int& cols);

int* erase(int* arr, int& n, int index);
int** erase_row(int** arr, int& rows, int const cols,int index);
void erase_col(int** arr, const int rows, int& cols, int index);


int* insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& rows, const int cols, int index);
void insert_col(int** arr, const int rows, int& cols, int index);






//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#if defined DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;

	int index;
	int value;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);


	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Введите индекс добавляемого значения: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого значения: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);


#endif 

	int rows, cols, index;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimeter << endl;

	//cout << "Введите индекс строки, которую нужно удалить: "; cin >> index;
	//erase_row(arr, rows, cols, index);
	//Print(arr, rows, cols);
	//cout << delimeter << endl;

	//cout << "Введите индекс столбца, который нужно удалить: "; cin >> index;
	//rase_col(arr, rows, cols, index);
	//Print(arr, rows, cols);
	//cout << delimeter << endl;


	//cout << "Введите индекс для добавления пустой строки: "; cin >> index;
	//insert_row(arr, rows, cols, index);
	//Print(arr, rows, cols);
	//cout << delimeter << endl;
	
	//cout << "Удаление первого столбца: " << endl;
	//pop_col_front(arr, rows, cols);
	//Print(arr, rows, cols);
	//cout << delimeter << endl;
	
	//cout << "Введите индекс для добавления  пустой колонки: "; cin >> index;
	//insert_col(arr, rows, cols, index);
	//Print(arr, rows, cols);

	Clear(arr, rows);
	
}

void FillRand(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)

		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)

		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}


int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	buffer = nullptr;
	arr[n] = value;
	n++;
	return arr;
}
int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1] {};
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int* pop_back(int* arr, int& n)
{
	/*int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
	return arr;*/
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++) buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int* erase(int* arr, int& n, int index)
{
	if (index > n) return arr;
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** erase_row(int** arr, int& rows, int const cols, int index)
{
	int** buffer = new int*[rows - 1] {};
	for (int i = 0; i < index; i++) buffer[i] = arr[i];
	for (int i = index; i < rows - 1; i++) buffer[i] = arr[i+1];
	delete[] arr;
	rows--;
	return arr;
}

void erase_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}


int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) удаляем массив указателей:
	delete[] arr;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) создаем буферный массив указателей: 
	int** buffer = new int* [rows + 1];
	// 2) копируем адреса строк из исходного массива: 
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	// 3)удаляем исходный массив указателей:
	delete[] arr;
	// 4) подменяем адрес массива указателей:
	arr = buffer;
	// 5) создаем новую строку
	arr[rows] = new int [cols] {};
	// 6) после добавления строки нужно увеличить количество строк массива
	rows++;
	// 7) возвращаем новый массив
	return arr;

}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
	// 1) создаем буферную строку: 
	int* buffer = new int[cols + 1] {};
	// 2) копируем все содержимое из исходной строки в буферную:
	for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
	// 3) удаляем исходную строку:
	delete[] arr[i];
	// 4) записываем адрес новой строки в массив укакзателей 
	arr[i] = buffer;
}
	cols++;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0 ; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[0] = new int [cols] {};
	rows++;
	return arr;
}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;
	return buffer;

}

void push_col_front(int** arr, const int rows, int& cols)
{
for (int i = 0; i < rows; i++)
	{
	int* buffer = new int[cols + 1] {};
	for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
	delete[] arr[i];
	arr[i] = buffer;
}
	cols++;
}
int** insert_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)	buffer[i] = arr[i];

	buffer[index] = new int[cols] {};
	
		for (int i = index; i < rows; i++)
		{
			buffer[i + index] = arr[i];
		}
		delete[] arr;
		rows++;
	return buffer;
}

void insert_col(int** arr, const int rows, int& cols, int index)
{
	for (int i = 0; i < rows; i++)
	{

		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		{
			for (int j = index; j < cols; j++)buffer[j] = arr[i][j];

			delete[] arr[i];
			arr[i] = buffer;
		}
		cols++;
	}
}

void** pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; cols++)
		{

			buffer[j] = arr[i][j + 1];

		}
		delete[] arr[i];
		arr[i] = buffer;
				
	}
		cols--;
		return 0;
}

void** pop_col_back(int** arr, const int rows, int& cols)
{
	return 0;
}
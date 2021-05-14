#include<iostream>
#include <Windows.h>
using namespace std;

// Проверка корректности ввода значения переменной типа double
double NumInDouble() {
	double variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

// Проверка корректности ввода значения переменной типа int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

// Установление отличного цвета для переставленных столбцов матрицы
void SetColour() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));
}

// Установление стандартного цвета отображения в консоли
void SetStandartColour() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 7));
}

// Основной алгоритм перестановки столбцов матрицы
void MatrixWork(int n, double *matrix, int k, int l) {
	int i = 0;
	double temp;
	while (i < (n*n)) {
		temp = matrix[i + k - 1];
		matrix[i + k - 1] = matrix[i + l - 1];
		matrix[i + l - 1] = temp;
		i = i + n;
	}
}
#pragma once
int NumInInt(); // Проверка корректности ввода значения переменной типа int
double NumInDouble(); // Проверка корректности ввода значения переменной типа double
void SetColour(); // Установление отличного цвета для переставленных столбцов матрицы
void SetStandartColour(); // Установление стандартного цвета отображения в консоли
void MatrixWork(int n, double *matrix, int k, int l); // Основной алгоритм перестановки столбцов матрицы
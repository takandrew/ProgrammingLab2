#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;

bool FileExist(string path); // Проверка существования файла
void FileWriteData(int n, double *matrix);  // Запись исходных данных в файл
int FileReadMatrixSize(string path); // Чтение длины строки матрицы из файла
double* FileReadMatrix(int n, double *matrix, string path); // Чтение значений элементов матрицы из файла
bool ReadOnlyChecking(string path); //Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool FileCorrectChecking(string path); //Функция, проверяющая корректность файла
bool FileReadCorrectChecking(string path); //Функция, проверяющая корректность файла, из которого считывают данные
bool FileOpenChecking(string path); // Функция, проверяющая открытие файла
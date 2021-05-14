#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;

bool FileExist(string path); // �������� ������������� �����
void FileWriteData(int n, double *matrix);  // ������ �������� ������ � ����
int FileReadMatrixSize(string path); // ������ ����� ������ ������� �� �����
double* FileReadMatrix(int n, double *matrix, string path); // ������ �������� ��������� ������� �� �����
bool ReadOnlyChecking(string path); //�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool FileCorrectChecking(string path); //�������, ����������� ������������ �����
bool FileReadCorrectChecking(string path); //�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileOpenChecking(string path); // �������, ����������� �������� �����
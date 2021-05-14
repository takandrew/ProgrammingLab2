#include<iostream>
#include <Windows.h>
using namespace std;

// �������� ������������ ����� �������� ���������� ���� double
double NumInDouble() {
	double variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����������� ��������� ������. ����������, ������� �����: " << endl;
	}
	return variable;
}

// �������� ������������ ����� �������� ���������� ���� int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "����������� ��������� ������. ����������, ������� �����: " << endl;
	}
	return variable;
}

// ������������ ��������� ����� ��� �������������� �������� �������
void SetColour() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 2));
}

// ������������ ������������ ����� ����������� � �������
void SetStandartColour() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((0 << 4) | 7));
}

// �������� �������� ������������ �������� �������
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
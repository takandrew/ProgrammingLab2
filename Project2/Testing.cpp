#include<iostream>
#include <iomanip>
#include"Computing.h"

using namespace std;

// ������������ ��������� ���������
bool Testing(int n, int k, int l) {
	int i, j, z, col, countJ, count;
	int one = 1; 
	if ((k > n) || (l > n))
		return false;
	double *matrix = new double[n*n];
	j = 0; col = n - one; z = 0;
	for (i = 0; i < (n*n); i++) {
		if (i > col) {
			j++;
			col = col + n;
			z = z + n;
		}
		matrix[i] = i-z;
	}
	MatrixWork(n, matrix, k, l);
	countJ = 0; j = 0; i = 0; count = 0;
	while (i < (n*n)) {
		if (i == j + k - one)
			if (matrix[i] == l - one) {
				count++;
				countJ++;
			}
		if (i == j + l - one)
			if (matrix[i] == k - one) {
				count++;
				countJ++;
			}
		if ((i != j + k - one) && (i != j + l - one))
			count++;
		if (countJ == 2) {
			countJ = 0;
			j = j + n;
		}
		i++;
	}
	delete[] matrix;
	if (count == n*n)
		return true;
	else
		return false;
}

// ����� �������� � ������ ������� �����
void TestNotWorking(int n, int k, int l) {
	cout << "�������� ������:" << endl;
	cout << "����� ������: " << n << endl;
	cout << "�������, ������� ����� �������� �������: " << k << " � " << l << endl;
	cout << "���������� ���������: ������������ �������� ������� ���������." << endl;
	cout << "��������� ���������: ������������ �������� ������� ������� ���������." << endl;
}

// ������������ �������
void TestWorking() {
	int one = 1, two = 2, three = 3, four = 4, five = 5;
	if ((Testing(three, one, three) && Testing(four, two, four) 
		&& Testing(two, one, two) && !Testing(four, five, four) 
		&& Testing(five, two, three)) == true) {
		cout << endl << "������������ ��������� �������." << endl << endl;
	}
	else {
		cout << endl << "������������ ���������." << endl << endl;
		if (!Testing(three, one, three)) {
			TestNotWorking(three, one, three);
		}
		if (!Testing(four, two, four)) {
			TestNotWorking(four, two, four);
		}
		if (!Testing(two, one, two)) {
			TestNotWorking(two, one, two);
		}
		if (Testing(four, five, four)) {
			TestNotWorking(four, five, four);
		}
		if (!Testing(five, two, three)) {
			TestNotWorking(five, two, three);
		}
	}
}


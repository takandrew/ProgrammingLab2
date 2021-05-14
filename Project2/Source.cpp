#include <iostream>
#include <iomanip>
#include "Computing.h"
#include "Menu.h"
#include "Testing.h"
#include "Files.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // ����� ����������� 
	TestWorking(); // ���������� ��������� ������
	while (true) {
		int i, j, countJ;
		int n = 1;
		double *matrix = nullptr;
		delete[] matrix;
		int column = 0;
		int importYes = 1;
		int importNo = 2;
		int importDataAnswer = MenuImportData(); // ����� ������������� �������� ������
		if (importDataAnswer == importYes) { // ������ �������� ������ �� �����
			ifstream fin;
			cout << "������� ���� � �����:" << endl;
			string path;
			int fileReadCorrectCheck = 0;
			SetConsoleCP(1251);
			cin >> path; 
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			fin.open(path);
			n = FileReadMatrixSize(path); // ������ ����� ������ �� �����
			fin.close();
			while (!(n > 0)) { // �������� ������������ ����������� �������� ����� ������
				cout << "������������ �������� ����� ������ ������� � ������ �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadMatrixSize(path);
				fin.close();
			}
			SetConsoleCP(866);
			fin.open(path);
			int countData = 0;
			double tempData = 0;
			while (fin) { // �������� �� ���������� ������ � �����
				fin >> tempData;
				if (fin.fail()) {
					break;
				}
				if (countData == ((n*n)+1))
					break;
				countData++;
			}
			fin.close();
			while (countData != ((n*n) + 1)) { // ���� �������� �������� ������ �� ������� ��������� ����������
				cout << "� ����� ������������ ������. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadMatrixSize(path); // ������ ����� ������ �� �����
				while (!(n > 0)) { // �������� ������������ ����������� �������� ����� ������
					cout << "������������ �������� ����� ������ ������� � ������ �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						fileReadCorrectCheck = FileReadCorrectChecking(path);
					}
					fin.open(path);
					n = FileReadMatrixSize(path);
					fin.close();
				}
				tempData = 0;
				countData = 0;
				while (fin) {
					fin >> tempData;
					if (fin.fail()) {
						break;
					}
					if (countData == ((n*n) + 1))
						break;
					countData++;
				}
				fin.close();
			}
			// �������� �������
			matrix = new double[n*n];
			FileReadMatrix(n, matrix, path); // ������ ��������� ������� �� �����
			cout << endl << "�������� �������:" << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				cout << matrix[i] << "\t";
				++column;
				if (column > n) {
						cout << endl;
						column = 1;
				}
			}
		} 
		else if (importDataAnswer == importNo) { // ���� �������� ������ � ����������
			cout << "������� ����� ������ �������: " << endl;
			n = NumInInt();
			while (!(n > 0)) { // �������� �� ������������ ����� ����� ������
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				n = NumInInt();
			}
			// �������� �������
			matrix = new double[n*n];
			cout << "������� �������� �������:" << endl;
			for (i = 0; i < (n*n); i++) {
				matrix[i] = NumInDouble();
			}
			cout << endl << "�������� �������:" << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				cout << matrix[i] << "\t";
				++column;
				if (column > n) {
					cout << endl;
					column = 1;
				}
			}
			if (MenuExportData() == true) { // ����������� ���������� �������� ������ � ����
				FileWriteData(n, matrix);
			}
		}
		else { // ���������� ������� ���������� �������
			cout << "������� ����� ������ �������: " << endl;
			n = NumInInt();
			while (!(n > 0)) { // �������� �� ������������ ����� ����� ������
				cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
				n = NumInInt();
			}
			// �������� �������
			matrix = new double[n*n];
			srand((unsigned)time(NULL));
			for (i = 0; i < (n*n); i++) {
				matrix[i] = 1 + rand() % 1000;
			}
			cout << endl << "��������������� �������" << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				cout << matrix[i] << "\t";
				++column;
				if (column > n) {
					cout << endl;
					column = 1;
				}
			}
			if (MenuExportData() == true) { // ����������� ���������� �������� ������ � ����
				FileWriteData(n, matrix);
			}
		}
		int k, l;
		cout << "������� ������ ��������, ������� ���������� �������� �������: " << endl;
		k = NumInInt();
		l = NumInInt();
		while ((k > n) || (l > n) || (k == 0) || (l == 0)) { 
			cout << "����������� ��������� ������. ����������, ���������� ��� ���: " << endl;
			k = NumInInt();
			l = NumInInt();
		}
		MatrixWork(n, matrix, k, l); // �������� �������� ���������, �������� ��������� ������� ������� �������
		cout << "��������������� �������: " << endl;
		column = 1; countJ = 0; j = 0;
		for (i = 0; i < (n*n); i++) {
			if ((i == j + k - 1) || (i == j + l - 1)) {
				SetColour();
				cout << matrix[i] << "\t";
				SetStandartColour();
				column++;
				countJ++;
				if (countJ == 2) {
					countJ = 0;
					j = j + n;
				}
			} 
			else {
				cout << matrix[i] << "\t";
				column++;
			}
			if (column > n) {
				cout << endl;
				column = 1;
			}
		}
		if (MenuResult() == true) { // ����������� ���������� ���������� � ����
			FileWriteData(n, matrix);
		}
		delete[] matrix; // �������� ������� 
		if (Menu() == false) // ����� ��������� ���� ����� ������ ��������� 
			return false;
	}
	return 0;
}
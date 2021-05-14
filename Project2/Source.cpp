#include <iostream>
#include <iomanip>
#include "Computing.h"
#include "Menu.h"
#include "Testing.h"
#include "Files.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // Вывод приветствия 
	TestWorking(); // Проведение модульных тестов
	while (true) {
		int i, j, countJ;
		int n = 1;
		double *matrix = nullptr;
		delete[] matrix;
		int column = 0;
		int importYes = 1;
		int importNo = 2;
		int importDataAnswer = MenuImportData(); // Выбор происхождения исходных данных
		if (importDataAnswer == importYes) { // Чтение исходных данных из файла
			ifstream fin;
			cout << "Введите путь к файлу:" << endl;
			string path;
			int fileReadCorrectCheck = 0;
			SetConsoleCP(1251);
			cin >> path; 
			SetConsoleCP(866);
			fileReadCorrectCheck = FileReadCorrectChecking(path);
			while (fileReadCorrectCheck == false) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
			}
			fin.open(path);
			n = FileReadMatrixSize(path); // Чтение длины строки из файла
			fin.close();
			while (!(n > 0)) { // Проверка корректности полученного значения длины строки
				cout << "Некорректное значение длины строки матрицы в данном файле. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
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
			while (fin) { // Проверка на количество данных в файле
				fin >> tempData;
				if (fin.fail()) {
					break;
				}
				if (countData == ((n*n)+1))
					break;
				countData++;
			}
			fin.close();
			while (countData != ((n*n) + 1)) { // Цикл проверки исходных данных до момента успешного извлечения
				cout << "В файле недостаточно данных. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				n = FileReadMatrixSize(path); // Чтение длины строки из файла
				while (!(n > 0)) { // Проверка корректности полученного значения длины строки
					cout << "Некорректное значение длины строки матрицы в данном файле. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
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
			// Создание матрицы
			matrix = new double[n*n];
			FileReadMatrix(n, matrix, path); // Чтение элементов матрицы из файла
			cout << endl << "Исходная матрица:" << endl;
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
		else if (importDataAnswer == importNo) { // Ввод исходных данных с клавиатуры
			cout << "Введите длину строки матрицы: " << endl;
			n = NumInInt();
			while (!(n > 0)) { // Проверка на корректность ввода длины строки
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				n = NumInInt();
			}
			// Создание матрицы
			matrix = new double[n*n];
			cout << "Введите значения матрицы:" << endl;
			for (i = 0; i < (n*n); i++) {
				matrix[i] = NumInDouble();
			}
			cout << endl << "Исходная матрица:" << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				cout << matrix[i] << "\t";
				++column;
				if (column > n) {
					cout << endl;
					column = 1;
				}
			}
			if (MenuExportData() == true) { // Возможность сохранение исходных данных в файл
				FileWriteData(n, matrix);
			}
		}
		else { // Заполнение матрицы случайными числами
			cout << "Введите длину строки матрицы: " << endl;
			n = NumInInt();
			while (!(n > 0)) { // Проверка на корректность ввода длины строки
				cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
				n = NumInInt();
			}
			// Создание матрицы
			matrix = new double[n*n];
			srand((unsigned)time(NULL));
			for (i = 0; i < (n*n); i++) {
				matrix[i] = 1 + rand() % 1000;
			}
			cout << endl << "Сгенерированная матрица" << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				cout << matrix[i] << "\t";
				++column;
				if (column > n) {
					cout << endl;
					column = 1;
				}
			}
			if (MenuExportData() == true) { // Возможность сохранение исходных данных в файл
				FileWriteData(n, matrix);
			}
		}
		int k, l;
		cout << "Введите номера столбцов, которые необходимо поменять местами: " << endl;
		k = NumInInt();
		l = NumInInt();
		while ((k > n) || (l > n) || (k == 0) || (l == 0)) { 
			cout << "Некорректно введенные данные. Пожалуйста, попробуйте еще раз: " << endl;
			k = NumInInt();
			l = NumInInt();
		}
		MatrixWork(n, matrix, k, l); // Основной алгоритм программы, меняющий указанные столбцы матрицы местами
		cout << "Преобразованная матрица: " << endl;
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
		if (MenuResult() == true) { // Возможность сохранение результата в файл
			FileWriteData(n, matrix);
		}
		delete[] matrix; // Удаление матрицы 
		if (Menu() == false) // Вызов основного меню после работы программы 
			return false;
	}
	return 0;
}
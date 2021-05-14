#include"Menu.h"
#include"Files.h"
#include<stdlib.h>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

// Проверка существования файла
bool FileExist(string path) {
	WIN32_FIND_DATA wfd;
	LPCSTR pathLPC = path.c_str();
	HANDLE hfind = ::FindFirstFile(pathLPC, &wfd);
	if (INVALID_HANDLE_VALUE != hfind) {
		::FindClose(hfind);
		return true;
	}
	return false;
}

//Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool ReadOnlyChecking(string path) {
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cout << endl << "В данный файл невозможно записать данные. Доступен только для чтения." << endl;
		return false;
	}
	else {
		return true;
	}
}

//Функция, проверяющая корректность файла
bool FileCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "Некорректное имя файла." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "Некорректное имя файла. Требуется ввести расширение файла после названия" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "Некорректный формат файла. Необходим файл формата .txt" << endl;
		return false;
	}
	if (!FileExist(path)) {
		return true;
	}
	if (!is_regular_file(path)) {
		cout << endl << "Файл не является обычным." << endl;
		return false;
	}
	return true;
}

//Функция, проверяющая корректность файла, из которого считывают данные
bool FileReadCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "Некорректное имя файла." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "Некорректное имя файла. Требуется ввести расширение файла после названия" << endl;
		return false;
	}
	if (!FileExist(path)) {
		cout << endl << "Файла по указанному пути не существует" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "Некорректный формат файла. Необходим файл формата .txt" << endl;
		return false;
	}
	if (!is_regular_file(path)) {
		cout << endl << "Файл не является обычным." << endl;
		return false;
	}
	return true;
}

// Функция, проверяющая открытие файла
bool FileOpenChecking(string path) {
	if (!FileExist(path)) {
		ofstream fout;
		fout.open(path);
		if (!fout.is_open()) {
			if (!is_regular_file(path)) {
				return false;
			}
			else {
				remove(path);
				return false;
			}
		}
		fout.close();
		remove(path);
		return true;
	}
	else
		return true;
}

// Чтение длины строки матрицы из файла
int FileReadMatrixSize(string path) {
	int n;
	ifstream fin;
	fin.open(path);
	string matrix_size;
	fin >> matrix_size;
	n = atoi(matrix_size.c_str());
	fin.close();
	return n;
}

// Чтение значений элементов матрицы из файла
double* FileReadMatrix(int n, double *matrix, string path) {
	int i;
	ifstream fin;
	fin.open(path);
	string matrix_size;
	fin >> matrix_size;
	for (i = 0; i < (n*n); i++) {
		fin >> matrix[i];
	}
	fin.close();
	return matrix;
}

// Запись исходных данных в файл
void FileWriteData(int n, double *matrix) {
	int i, column;
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "Введите путь к файлу:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
		cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
		cout << "Введите путь к файлу:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // Проверка существования файла
		if (MenuReWrite() == true) { // Возможность выбора перезаписи в файл
			fout.open(path);
			// Вывод исходных данных в файл
			fout << n << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				fout << matrix[i] << "\t";
				++column;
				if (column > n) {
					fout << endl;
					column = 1;
				}
			}
		}
		else { // Отказ от перезаписи и выбор другого пути к файлу
			cout << "Введите путь к файлу:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
				cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
				cout << "Введите путь к файлу:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // Цикл проверки существования, перезаписи или выбора другого пути к файлу
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// Вывод исходных данных в файл
			fout << n << endl;
			column = 1;
			for (i = 0; i < (n*n); i++) {
				fout << matrix[i] << "\t";
				++column;
				if (column > n) {
					fout << endl;
					column = 1;
				}
			}
		}
	}
	else { // Если файла не существует 
		fout.open(path);
		// Вывод исходных данных в файл
		fout << n << endl;
		column = 1;
		for (i = 0; i < (n*n); i++) {
			fout << matrix[i] << "\t";
			++column;
			if (column > n) {
				fout << endl;
				column = 1;
			}
		}
	}
	cout << endl << "Файл успешно сохранён." << endl;
	fout.close();
}

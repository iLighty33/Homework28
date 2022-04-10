#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void fillArray(int arr[], int length, int min, int max);
template <typename T> void showArr(T arr[], int length);
template <typename T> T* resizeArr(T arr[], unsigned int& length, int newLength);

int main() {
	setlocale(LC_ALL, "Russian");
	
	// Задача 1

	unsigned int m;
	int n;
	cout << "Задача 1.\nВведите длину 1-го массива: ";
	cin >> n;
	cout << "Введите длину 2-го массива: ";
	cin >> m;

	int* dynamicArray1 = new int[n];
	int* dynamicArray2 = new int[m];

	fillArray(dynamicArray1, n, 5, 21);
	fillArray(dynamicArray2, m, 50, 81);

	cout << "Динамический массив 1:\n";
	showArr(dynamicArray1, n);
	cout << "Динамический массив 2:\n";
	showArr(dynamicArray2, m);

	int* dynamicArray3 = new int[n + m];

	for (int i = 0; i < n; i++)
		dynamicArray3[i] = dynamicArray1[i];

	for (int i = n; i < n + m; i++)
		dynamicArray3[i] = dynamicArray2[i - n];

	cout << "Динамический массив 3:\n";
	showArr(dynamicArray3, m + n);

	// Задача 2

	cout << "Введите новую длинну массива 2: ";

	cin >> n;

	dynamicArray2 = resizeArr(dynamicArray2, m, n);

	showArr(dynamicArray2, n);

	delete[] dynamicArray1;
	delete[] dynamicArray2;
	delete[] dynamicArray3;
	dynamicArray1 = nullptr;
	dynamicArray2 = nullptr;
	dynamicArray3 = nullptr;

	return 0;
}

// Задача 2

template <typename T> T* resizeArr(T arr[], unsigned int& length, int newLength) {
	if (newLength <= 0)
		return arr;
	if (newLength < length) {
		if (newLength % 2 == 0) {
			length = newLength;
			T* tmp = new T[length];
			for (int i = 0; i < length; i++)
				tmp[i] = arr[i];
			delete[] arr;
			arr = new T[length+1];
			for (int i = 0; i < length; i++)
				arr[i] = tmp[i];
			delete[] tmp;
			return arr;
		}
		else
		{
			length -= newLength;
			T* tmp = new T[length+1];
			for (int i = 0; i <= length; i++)
				tmp[i] = arr[i];
			delete[] arr;
			arr = new T[length+1];
			for (int i = 0; i <= length; i++)
				arr[i] = tmp[i];
			delete[] tmp;
			return arr;
		}

	}
	else
	{
			T* tmp = new T[length];
			for (int i = 0; i < length; i++)
				tmp[i] = arr[i];
			delete[] arr;
			arr = new T[newLength];
			for (int i = 0; i < newLength; i++)
				arr[i] = tmp[i];
			for (int i = length; i < newLength; i++)
				arr[i] = rand() % (101 - 50) + 50;
			delete[] tmp;
			return arr;

	}
}

// Задача 1

void fillArray(int arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
	cout << "\b\b]\n";
	
}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void fillArr(T arr[], int length, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + max;
}
template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Задача 1. 
template <typename T> void addEl(T *&arr, int length, int n) {
	if (n <= 0)
		return;
	T *tmp = new T [length + n];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete [] arr;
	arr = tmp;
}

//Задача 2.
template <typename T> void delEl(T*& arr, int length, int n) {
	if (n <= 0 || n >= length)
		return;
	T* tmp = new T[length - n];
	for (int i = 0; i < length - n; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Динамические переменные
	/*int* pn = new int;
	*pn = 10;
	cout << *pn << endl;
	cout << pn << "\n\n";

	delete pn;
	pn = nullptr;

	pn = new int;

	if (pn != nullptr) {
		*pn = 15;
		cout << *pn << endl;
		cout << pn << "\n\n";
	}
	else cout << "Указатьель не инициалезирован\n";*/

	// Динамические массивы
	/*int size;
	cout << "Введите размер массива: ";
	cin >> size;
	int* dArr = new int[size];
	fillArr(dArr, size, 10, 31);
	cout << "Итговый массив: ";
	showArr(dArr, size);
	delete [] dArr;*/

	// Задача 1
	/*cout << "Задача 1.\nВведите длину массива: ";
	int size1;
	cin >> size1;
	int* z1 = new int[size1];
	fillArr(z1, size1, 10, 31);
	cout << "Изначальный массив: ";
	showArr(z1, size1);
	int newS1;
	cout << "Введите кол-во фячеек которое необходимо добавить: ";
	cin >> newS1;
	addEl(z1, size1, newS1);
	size1 += newS1;
	cout << "Итоговый массив:\n";
	showArr(z1, size1);*/

	// Задача 2
	cout << "Задача 2.\nВведите длину массива: ";
	int size2;
	cin >> size2;
	int* z2 = new int[size2];
	fillArr(z2, size2, 10, 31);
	cout << "Изначальный массив: ";
	showArr(z2, size2);
	int newS2;
	cout << "Введите кол-во фячеек которое необходимо удалить: ";
	cin >> newS2;
	delEl(z2, size2, newS2);
	size2 -= newS2;
	cout << "Итоговый массив:\n";
	showArr(z2, size2);

	delete [] z2;
	z2 = nullptr;

	return 0;
}
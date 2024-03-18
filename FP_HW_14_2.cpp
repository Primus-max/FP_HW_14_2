// Задание 1. Написать следующие функции для работы
// ■ Функция распределения динамической памяти.
// ■ Функция инициализации динамического массива.
// ■ Функция печати динамического массива.
// ■ Функция удаления динамического массива.
// ■ Функция добавления элемента в конец массива.
// ■ Функция вставки элемента по указанному индексу.
// ■ Функция удаления элемента по указанному индексу.

#include <iostream>
#include <random>
#include <windows.h>
using namespace std;

// Заполнение массив
template<typename T>
void FillArray(T* arr, int size);

// Печать массива
template<typename T>
void PrintArray(T* arr, int size);

// Динамическое выделение памяти для массива
template<typename T>
T* allocateMemory(T size);

// Очистка памяти
template<typename T>
void ClearMemory(T* arr);

// Удаление последнего элемента
template<typename T>
T* RemoveLastElement(T* arr, int& size);

// Добавление элемента в конец
template<typename T>
T* AddElementToEnd(T* arr, int& size, T newElement);

// Удаление элемента по индексу
template<typename T>
T* RemoveElementByIndex(T* arr, int& size, int index);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	cout << "Какой размер у массива ? ";
	cin >> size;
	int* Array = allocateMemory<int>(size);

	FillArray(Array, size);
	cout << "Заполненный массив " << endl;
	PrintArray(Array, size);

	cout << "Удаление последнего элемента в массиве " << endl;
	int* removedLastElement = RemoveLastElement<int>(Array, size);
	PrintArray(removedLastElement, size);


	cout << "Укажите целое число для вставки в массив в конец : " << endl;
	int newElement;
	cin >> newElement;
	int* addedElement = AddElementToEnd<int>(removedLastElement, size, newElement);
	cout << "Массив с новым элементом на борту : " << endl;
	PrintArray(addedElement, size);

	cout << "В массиве размером от 0 до " << size << " элементов, по какому индексу удалить элемент?" << endl;
	int indexRemoveElement;
	cin >> indexRemoveElement;
	int* removerElementBuIndex = RemoveElementByIndex(addedElement, size, indexRemoveElement);
	cout << "Массив с удалённым элементом по указанному индексу :" << endl;
	PrintArray(removerElementBuIndex, size);
}


template<typename T>
void FillArray(T* arr, int size) {
	random_device random;
	for (T* i = arr; i < arr + size; i++)
		*i = random() % (100 + 50) - 50;
}

template<typename T>
void PrintArray(T* arr, int size) {
	for (int* i = arr; i < arr + size; i++)
		cout << "[ " << *i << "] " << " ";

	cout << endl;
}

template<typename T>
T* allocateMemory(T size) {
	T* newArray = new int[size];
	return newArray;
}

template<typename T>
void ClearMemory(T* arr) { delete[] arr; };


template<typename T>
T* RemoveLastElement(T* arr, int& size) {

	if (arr == nullptr)
		return nullptr;

	T* newArr = allocateMemory<T>(--size);

	for (int* i = arr, *j = newArr; i < arr + size; ++i, ++j)
		*j = *i;

	ClearMemory(arr);
	return newArr;
}

template<typename T>
T* AddElementToEnd(T* arr, int& size, T newElement) {

	if (arr == nullptr)
		return nullptr;

	T* newArr = allocateMemory<T>(size + 1);

	if (newArr == nullptr)
		return nullptr;

	T* j = newArr;
	for (T* i = arr; i < arr + size; ++i, ++j)
		*j = *i;

	++size;
	*j = newElement;
	ClearMemory(arr);
	return newArr;
}

template<typename T>
T* RemoveElementByIndex(T* arr, int& size, int index) {
	if (arr == nullptr || index < 0 || index >= size)
		return nullptr;

	T* newArr = allocateMemory<T>(size - 1);
	if (newArr == nullptr)
		return nullptr;

	T* j = newArr;
	for (T* i = arr; i < arr + size; ++i) {
		if (i - arr == index) continue;
		*j++ = *i;
	}

	--size;
	ClearMemory(arr);
	return newArr;
}


#include <iostream>
#include <algorithm>

using namespace std;

void CreateMassive(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		*(arr + i) = rand() % 30 + 1;
}

void PrintMassive(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << ' ';
	}

	cout << endl;
}

double GetMin(int* arr, int size)
{
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (min > *(arr + i))
			min = *(arr + i);
	}
	cout << "Минимальное значение: " << endl;

	return min;
}

double GetMax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < *(arr + i))
			max = *(arr + i);
	}
	cout << "Максимальное значение: " << endl;

	return max;
}

double GetAverage(int* arr, int size)
{
	int sum{};
	for (int i = 0; i < size; i++)
	{
		sum += *(arr + i);
	}
	cout << "Среднее значение элементов массива = " << endl;

	return sum / size;
}

double Action(int* arr, int size, double(*func)(int* arr, int size))
{
	return func(arr, size);
}

int GetValue()
{
	int value;
	cin >> value;

	return value;
}

int main()
{
	srand(time(NULL));
	setlocale(0, "");

	cout << "Введите размер массива: ";
	int size = GetValue();

	int* arr = new int[size];

	CreateMassive(arr, size);
	PrintMassive(arr, size);

	cout << "Выберите, что бы узнать: " << endl;
	cout << "1 - максимальное значение в массиве" << endl;
	cout << "2 - минимальное значение в массиве" << endl;
	cout << "3 - Среднее значение элементов в массиве" << endl;

	int point = GetValue();

	switch (point)
	{
	case 1:
		cout << Action(arr, size, GetMax);
		break;
	case 2:
		cout << Action(arr, size, GetMin);
		break;
	case 3:
		cout << Action(arr, size, GetAverage);
		break;
	default:
		break;
	}
	return point;

	delete[] arr;

	return 0;
}
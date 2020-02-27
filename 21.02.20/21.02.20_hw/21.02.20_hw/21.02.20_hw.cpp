﻿#include <iostream>

using namespace std;

void N2938();
void N3644();
void N9775();
void N8001();
void N2903();
void N2904();
void n2906();
void task27_9702();

int main() {

	task27_9702();

	return 0;
}

// Дан целочисленный массив из 23-х элементов. Элементы массива могут принимать значения
// от 1500 до 2000 — количество знаков в статье. На сайт принимаются статьи размером
// не более 1800 знаков и не менее 1600. Гарантируется, что такие значения в базе данных есть.
// Опишите на русском языке или на одном из языков программирования алгоритм,
// который находит и выводит на экран размер самой большой статьи, которую можно разместить на сайте.

void N2938() {
	int const N = 7;
	int a[N];
	int i, j, k;
	for (i = 0; i < N; i++)
		cin >> a[i];
	k = INT_MIN;
	for (i = 0; i < N; ++i) {
		if ((a[i] <= 1800) && (a[i] >= 1600) && (a[i] > k)) {
			k = a[i];
		}
	}
	cout << "Max is " << k << endl;
}

// Опишите на русском языке или одном из языков программирования алгоритм вычисления
// разности максимального среди элементов, имеющих четные значения, и максимального среди элементов,
// имеющих нечетные значения, в заданном целочисленном массиве из 30 положительных элементов

void N3644() {
	int const n = 6;
	int a[n];
	int i, k, b, s;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	k = INT_MIN;
	b = INT_MIN;
	for (i = 0; i < n; ++i) {
		if ((a[i] > k) && ((a[i] % 2) == 1)) {
			k = a[i];
		}
		if ((a[i] > b) && ((a[i] % 2) == 0)) {
			b = a[i];
		}
	}
	s = b - k;
	cout << "Difference is " << s << endl;
}

// Дан массив, содержащий 2015 неотрицательных целых чисел. Пиком называется не крайний элемент массива,
// который больше обоих своих соседей. Необходимо найти в массиве самый высокий пик, то есть пик,
// значение которого максимально. Если в массиве нет ни одного пика, ответ считается равным 0.

void N9775() {
	int const N = 6;
	int a[N];
	int i, j, k;
	for (i = 0; i < N; i++)
		cin >> a[i];
	k = 0;
	for (i = 1; i < N - 1; ++i) {
		if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]) && (a[i] > k)) {
			k = a[i];
		}
	}
	cout << "Peak is " << k << endl;
}

// Дан массив, содержащий неотрицательные целые числа, не превышающие 10 000. В массиве присутствуют чётные и нечётные числа. Необходимо вывести:
// — минимальный чётный элемент, если количество чётных элементов не больше, чем нечётных;
// — минимальный нечётный элемент, если количество нечётных элементов меньше, чем чётных.

void N8001() {
	int const N = 6;
	int a[N];
	int i, j, k, m;
	for (i = 0; i < N; i++)
		cin >> a[i];
	k = INT_MAX;
	m = 0;
	j = INT_MAX;
	for (i = 0; i < N; ++i) {
		if ((a[i] % 2) == 0) {
			m++;
			if (a[i] < k) {
				k = a[i];
			}
		}
		else if (a[i] < j) {
			j = a[i];
		}
	}
	if (m <= N - m) {
		cout << "Min even is " << k << endl;
	}
	if (N - m < m) {
		cout << "Min odd is " << j << endl;
	}
}

// Опишите на языке программирования алгоритм подсчета максимального количества подряд идущих элементов,
// каждый из которых больше предыдущего, в целочисленном массиве длины 30.

void N2903() {
	int const n = 7;
	int a[n];
	int i, b, m;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	b = 1;
	m = 0;
	for (i = 0; i < n; ++i) {
		if (a[i] < a[i + 1]) {
			b++;
		}
		else {
			if (b > m) {
				m = b;
				b = 1;
			}
		}
	}

	if (b > m) {
		m = b;
		b = 1;
	}

	cout << "Qty " << m << endl;
}

// Опишите на русском языке или на одном из языков программирования алгоритм
// получения из заданного целочисленного массива размером 30 элементов другого массива,
// который будет содержать модули значений элементов первого массива.

void N2904() {
	int const n = 7;
	int i;
	int a[n];
	int b[n];
	for (i = 0; i < n; ++i)
		cin >> a[i];
	for (i = 0; i < n; ++i) {
		b[i] = abs(a[i]);
	}
}

// Опишите на русском языке или одном из языков программирования алгоритм подсчета
// максимального количества подряд идущих четных элементов в целочисленном массиве длины 30.

void n2906() {
	int const n = 7;
	int a[n];
	int i, max, num;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	max = 0;
	num = 0;
	for (i = 0; i < n - 1; ++i) {
		if ((a[i] % 2) == 0) {
			num++;
		}
		else {
			if (num >= max) {
				max = num;
				num = 0;
			}
		}
		if (num >= max) {
			max = num;
		}
	}

	cout << "Qty even is " << max;
}

// Последовательность натуральных чисел характеризуется числом Х — наибольшим числом, кратным 14 и являющимся произведением двух элементов последовательности 
// с различными номерами.
void task27_9702() {
	int n14, max, n2, n7, pr, size, number;
	cin >> size;

	n14 = 0;
	n2 = 0;
	n7 = 0; 
	max = 0;
	pr = 1;

	for (int i = 0; i < size; ++i) {
		cin >> number;

		if (number % 2 == 0 && number % 14 != 0 && number > n2) {
			n2 = number;
		}
		else if (number % 7 == 0 && number % 14 != 0 && number > n7) {
			n7 = number;
		}
		else if (number % 14 == 0 && number > n14) {
			n14 = number;
		}
		else if (number > max) {
			max = number;
		}
	}
	pr = n2 * n7;
	if (n14 * max > pr) {
		pr = n14 * max;
	}
	if (n14 * n7 > pr) {
		pr = n14 * n7;
	}
	if (n2 * n14 > pr) {
		pr = n2 * n14;
	}
	cout << pr << endl;


}
﻿#include<iostream>

using namespace std;

void task_5375();
void task_5471();
void task_11256();
void task_11283();
void task_13557();
void task_1();
void task_2();

int main() {

	setlocale(LC_ALL, "Russian");
	task_2();

	return 0;
}

/* № 5375
На ускорителе для большого числа частиц производятся замеры скорости каждой из них.
Скорость частицы — это целое число (положительное, отрицательное или 0).
Частиц, скорость которых измерена, может быть очень много, но не может быть меньше трёх.
Скорости всех частиц различны. При обработке результатов в каждой серии эксперимента
отбирается основное множество скоростей. Это такое непустое множество скоростей частиц
(в него могут войти как скорость одной частицы, так и скорости всех частиц серии),
для которого произведение скоростей является максимальным среди всех возможных множеств.
При нахождении произведения знак числа учитывается. Если есть несколько таких множеств,
то основным считается то, которое содержит наибольшее количество элементов.
*/

void task_5375() {
	int size, number;
	long long int maxNeg = -1000000001; // long int = int = long; long long int −9 223 372 036 854 775 808 до +9 223 372 036 854 775 807
	int kolNeg = 0;
	int numMaxNeg = 0;
	int numZero = 0;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		cin >> number;
		if (number == 0)
			numZero = i;
		if (number < 0) {
			kolNeg++;
			if (number > maxNeg) {
				maxNeg = number;
				numMaxNeg = i;
			}
		}
	}
	for (int i = 1; i <= size; i++) {
		if (i != numZero && (kolNeg % 2 == 0 || i != numMaxNeg))
			cout << i << " ";
	}
}

/*№ 5471
На ускорителе для большого числа частиц производятся замеры скорости каждой из них.
Скорость частицы — это целое неотрицательное число. Частиц, скорость которых измерена,
может быть очень много, но не может быть меньше трёх. Скорости всех частиц различны.
Скорость, по крайней мере, одной частицы нечётна.
При обработке результатов в каждой серии эксперимента отбирается множество скоростей.
Это непустое подмножество скоростей частиц (в него могу войти как скорость одной частицы, так и скорости всех частиц серии),
такое, что сумма всех значений скоростей у него нечётна и максимальна среди всех возможных непустых подмножеств с нечётной суммой.
Если таких подмножеств несколько, то из них выбирается то подмножество, которое содержит наименьшее количество элементов.
*/

void task_5471() {
	int size, number;
	long  min = 0;
	int kolNechet = 0;
	int numMinNechet = 0;
	int numZero = 0;
	cin >> size;
	for (int i = 1; i <= size; i++) {
		cin >> number;
		if (number == 0)
			numZero = i;
		if (number % 2 != 0) {
			kolNechet++;
			if (min == 0 || number < min) {
				min = number;
				numMinNechet = i;
			}
		}
	}
	for (int i = 1; i <= size; i++) {
		if (i != numZero && (kolNechet % 2 != 0 || i != numMinNechet))
			cout << i << " ";
	}
}
 /*№ 11256
На плоскости задано множество точек с целочисленными координатами,
никакие две из которых не совпадают и никакие три не лежат на одной прямой.
Необходимо найти количество треугольников, обладающих следующими свойствами:

1) все вершины треугольника принадлежат заданному множеству;
2) ни одна вершина не лежит на осях координат;
3) треугольник не пересекается с осью Ox, но пересекается с осью Oy.
 */

void task_11256() {
	int size, x, y;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cin >> x >> y;
		if (x > 0 && y > 0)
			n1++;
		if (x < 0 && y > 0)
			n2++;
		if (x < 0 && y < 0)
			n3++;
		if (x > 0 && y < 0)
			n4++;
	}
	kol = (n1 * n2 * (n1 + n2 - 2) + (n3 * n4 * (n3 + n4 - 2))) / 2;
	cout << kol << endl;
}

/*№ 11283
На плоскости задано множество точек с целочисленными координатами,
никакие две из которых не совпадают и никакие три не лежат на одной прямой.
Необходимо найти количество треугольников, обладающих следующими свойствами:

1) все вершины треугольника принадлежат заданному множеству;
2) ни одна вершина не лежит на осях координат;
3) треугольник не пересекается с осью Oy, но пересекается с осью Ox.
*/

void task_11283() {
	int size, x, y;
	int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cin >> x >> y;
		if (x > 0 && y > 0)
			n1++;
		if (x < 0 && y > 0)
			n2++;
		if (x < 0 && y < 0)
			n3++;
		if (x > 0 && y < 0)
			n4++;
	}
	kol = (n1 * n4 * (n1 + n4 -2) + (n2 * n3 * (n2 + n3 - 2))) / 2;
	cout << kol << endl;
}

/* № 13557 
Дан набор из N целых положительных чисел. 
Необходимо выбрать из набора произвольное количество чисел так,
чтобы их сумма была как можно больше и при этом не делилась на 6.
В ответе нужно указать количество выбранных чисел и их сумму, сами числа выводить не надо.
Если получить нужную сумму невозможно, считается, что выбрано 0 чисел и их сумма равна 0.
*/
void task_13557() {
	int number, size;
	int kol = 0, sum = 0;
	int max = 10000;
	int min = 1;
	cin >> size;
	min += max;
	for (int i = 0; i < size; ++i) {
		cin >> number;
		sum += number;
		if ((number % 6) != 0 &&  min > number)
			min = number;
	}
	if (sum % 6 != 0)
		kol = size;
	else if (min <= max) {
		sum -= min;
		kol = size - 1;
	}
	else {
		sum = 0;
		kol = 0;
	}
	cout << kol << " " << sum << endl;
}

void task_1() {
	int size, t;
	int aSum = 0;
	int a, b;
	int min = INT_MAX;
	cin >> size;
	cin >> t;
	cin >> a >> b;
	if (b + t < a + t)
		min = b + t;
	else
		min = a + t;
	aSum += a;
	for (int i = 1; i < size; ++i) {
		cin >> a >> b;
		aSum += a;
		if (min + b < aSum + t)
			min += b;
		else
			min = aSum + t;
	}
	cout << min << endl;
}

void task_2() {
	int number;
	int maxH = 0;
	int pr = 0;
	int h = 0;
	int kol = 0;
	cin >> number;
	pr = number;
	while (number  != 0) {
		if (number > pr) {
			h += number - pr;
		}
		else {
			if (h > maxH)
				maxH = h;
			h = 0;
		}
		kol++;
		pr = number;
		cin >> number;
	}
	if (h > maxH)
		maxH = h;
	cout << "Получено чисел " << kol << endl;
	cout << "Наибольшая высота подъема " << maxH << endl;
}
﻿#include <iostream>

using namespace std;

void task_27_14788();
void task_27_15122();
void task_27_15149();
void task18806();
void task2();

int main() {

	task2();

	return 0;
}

/*
 № 14788
Дан набор из N целых положительных чисел. Из этих чисел формируются все возможные пары
(парой считаются два элемента, которые находятся на разных местах в наборе, порядок чисел в паре не учитывается),
в каждой паре вычисляется сумма элементов. Необходимо определить количество пар, для которых
полученная сумма делится на 9
*/

void task_27_14788() {
	int number, size;
	int n0 = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	int n8 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 9 == 0)
			n0++;
		else if (number % 9 == 1)
			n1++;
		else if (number % 9 == 2)
			n2++;
		else if (number % 9 == 3)
			n3++;
		else if (number % 9 == 4)
			n4++;
		else if (number % 9 == 5)
			n5++;
		else if (number % 9 == 6)
			n6++;
		else if (number % 9 == 7)
			n7++;
		else if (number % 9 == 8)
			n8++;
	}
	kol = n1 * n8 + n2 * n7 + n6 * n3 + n4 * n5 + n0 * (n0 - 1);
	cout << kol << endl;
}

/*
№ 15122
Дан набор из N целых положительных чисел. Из этих чисел формируются все возможные пары
(парой считаются два элемента, которые находятся на разных местах в наборе, порядок чисел в паре не учитывается),
в каждой паре вычисляется сумма элементов. Необходимо определить количество пар, для которых
полученная сумма делится на 8.
*/

void task_27_15122() {
	int number, size;
	int kol = 0;
	int n0 = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 8 == 0)
			n0++;
		else if (number % 8 == 1)
			n1++;
		else if (number % 8 == 2)
			n2++;
		else if (number % 8 == 3)
			n3++;
		else if (number % 8 == 4)
			n4++;
		else if (number % 8 == 5)
			n5++;
		else if (number % 8 == 6)
			n6++;
		else if (number % 8 == 7)
			n7++;
	}
	kol = n1 * n7 + n2 * n6 + n3 * n5 + (n4 * (n4 - 1) + n0 * (n0 - 1)) / 2;
	cout << kol << endl;
}

/*
 № 15149
Дан набор из N целых положительных чисел. 
Из этих чисел формируются все возможные пары (парой считаются два элемента, которые находятся
на разных местах в наборе, порядок чисел в паре не учитывается), в каждой паре вычисляется сумма элементов.
Необходимо определить количество пар, для которых полученная сумма делится на 10.
*/

void task_27_15149() {
	int number, size;
	int kol = 0;
	int n0 = 0;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	int n8 = 0;
	int n9 = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 10 == 0)
			n0++;
		else if (number % 10 == 1)
			n1++;
		else if (number % 10 == 2)
			n2++;
		else if (number % 10 == 3)
			n3++;
		else if (number % 10 == 4)
			n4++;
		else if (number % 10 == 5)
			n5++;
		else if (number % 10 == 6)
			n6++;
		else if (number % 10 == 7)
			n7++;
		else if (number % 10 == 8)
			n8++;
		else if (number % 10 == 9)
			n9++;
	}
	kol = n1 * n9 + n2 * n8 + n3 * n7 + n4 * n6 + (n5 * (n5 - 1) + n0 * (n0 - 1)) / 2;
	cout << kol << endl;
}

/* 
№ 18806
На вход программы поступает последовательность из N целых положительных чисел.
Рассматриваются все пары различных элементов последовательности (элементы пары не обязаны
стоять в последовательности рядом), такие что ai > aj при i < j ≤ N. Среди пар, удовлетворяющих этому условию,
необходимо найти и вывести пару с максимальной суммой элементов, которая делится на 120.
Если среди найденных пар максимальную сумму имеют несколько, то можно напечатать любую из них.
*/

void task18806() {
	int number, size;
	int maxSum = -1;
	int el1 = -1;
	int el2 = -1;
	cin >> size;
	int a[120] = {};
	for (int i = 0; i < size; i++) {
		cin >> number;

		if (number % 120 == 0 && a[0] != 0 && number < a[0] && number + a[0] > maxSum) {
			maxSum = number + a[0];
			el1 = number;
			el2 = a[0];
		}
		else if (a[120 - number % 120] != 0 && number < a[120 - number % 120] && number + a[120 - number % 120] > maxSum) {
			maxSum = number + a[120 - number % 120];
			el1 = number;
			el2 = a[120 - number % 120];
		}

		if (number > a[number % 120]) {
			a[number % 120] = number;
		}
	}
	cout << el1 << " " << el2 << endl;
}

void task2() {
	int x, y, size;
	int yMax = INT_MIN;
	int yMin = INT_MAX;
	int xMax = INT_MIN;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (x == 0 && y > yMax)
			yMax = y;
		if (x == 0 && y < yMin)
			yMin = y;

		if (y != 0 && abs(x) > xMax)
			xMax = abs(x);
	}
	S = float((yMax - yMin) * xMax) / float(2);
	if (S > 0)
		cout << S << endl;
	else
		cout << "NO" << endl;
}
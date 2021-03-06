﻿#include <iostream>

using namespace std;

void task_6436(); // не работает
void task_13530();
void task_13423();
void task_13476();
void task_13638();
void task_13611();
void task_14242();
void task_14286();
void task_7772();
void task_7773();

int main() {

	task_7773();

	return 0;
}

/* № 6436
В телевизионном танцевальном марафоне с определением победителя с помощью телезрителей
после каждого тура объявляется sms-голосование, в котором зрители указывают наиболее понравившуюся им пару
из максимум 16 пар, которые участвуют в проекте. Вам предлагается написать программу, которая будет обрабатывать
результаты sms-голосования по данному вопросу. Результаты голосования получены в виде номеров пар
(каждый элемент списка соответствует одному sms-сообщению).
*/

void task_6436() {
	int number, size;
	int bal[16] = { 0 };
	int par[16];
	cin >> size;
	for (int i = 0; i < 16; i++)
		par[i] = i + 1;
	for (int j = 0; j < size; j++) {
		cin >> number;
		bal[number - 1]++;
	}
	
	for (int i = 0; i < 16; i++) {
		for (int j = i; j < 16; j++) {
			if (bal[j] < bal[j + 1]) {
				int temp1 = bal[j];
				bal[j] = bal[j + 1];
				bal[j + 1] = temp1;

				int temp2 = par[j];
				par[j] = par[j + 1];
				par[j + 1] = temp2;
			}
		}
	}

	for (int i = 0; i < 16; i++) {
		if (bal[i] > 0)
			cout << par[i] << " " << bal[i] << endl;
	}
}

/*№ 13530
Дан набор из N целых положительных чисел. 
Необходимо определить, какая цифра чаще всего встречается в десятичной записи чисел
этого набора. Если таких цифр несколько, необходимо вывести наибольшую из них.
*/

void task_13530() {
	int size, number;
	int a[10] = { 0 };
	cin >> size;
	int maxNum = 0;
	int num = 0;
	for (int i = 0; i < size; i++) {
		cin >> number;
		while (number > 0) {
			num = number % 10;
			a[num]++;
			number = number / 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (a[i] >= a[maxNum])
			maxNum = i;
	}
	cout << maxNum << endl;
}

/*№ 13423
Дан набор из N неотрицательных целых чисел, меньших 1000.
Для каждого числа вычисляется сумма цифр его десятичной записи. 
Необходимо определить, какая сумма цифр чаще всего встречается у чисел этого набора. 
Если таких сумм несколько, нужно вывести наименьшую из них
*/

void task_13423() {
	int size, number;
	int a[28] = { 0 };
	cin >> size;
	int num = 0;
	int sum = 0;
	int maxSum = 0;
	for (int i = 0; i < size; i++) {
		cin >> number;
		while (number > 0) {
			num = number % 10;
			sum += num;
			number = number / 10;
		}
		a[sum]++;
		sum = 0;
	}
	for (int i = 0; i < 28; i++) {
		if (a[i] > a[maxSum])
			maxSum = i;
	}
	cout << maxSum << endl;
}

/*№ 13476
Дан набор из N неотрицательных целых чисел, меньших 1000.
Для каждого числа вычисляется сумма цифр его десятичной записи.
Необходимо определить, какая сумма цифр реже всего встречается у чисел этого набора.
Если таких сумм несколько, нужно вывести наибольшую из них.
*/

void task_13476() {
	int size, number;
	int a[28] = {0};
	int num = 0;
	int sum = 0;
	int minS = 0;
	int kol = INT_MAX;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		while (number > 0) {
			num = number % 10;
			sum += num;
			number = number / 10;
		}
		a[sum]++;
		sum = 0;
	}
	for (int i = 1; i < 28; i++) {
		if (a[i] > 0 && a[i] <= kol) {
			kol = a[i];
			minS = i;
		}
	}
	cout << minS << endl;
}

/*№ 13638
Назовём длиной числа количество цифр в его десятичной записи. 
Например, длина числа 2017 равна 4, а длина числа 7 равна 1.
Дан набор из N целых положительных чисел, каждое из которых меньше 10^8.
Необходимо определить, числа какой длины реже всего (но не менее одного раза)
встречаются в данном наборе и сколько в нём чисел этой длины. Если числа разной длины встречаются одинаково часто
(и реже, чем числа любой другой длины), нужно выбрать меньшую длину. 
*/

void task_13638() {
	int size, number;
	int dl = 0;
	int kol = INT_MAX;
	int a[9] = { 0 };
	int maxDl = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		while (number > 0) {
			dl++;
			number = number / 10;
		}
		a[dl]++;
		dl = 0;
	}
	for (int i = 0; i < 9; i++) {
		if (a[i] > 0 && a[i] < kol) {
			kol = a[i];
			maxDl = i;
		}
	}
	cout << maxDl << " " << kol << endl;
}

/* № 13611
Назовём длиной числа количество цифр в его десятичной записи.
Например, длина числа 2017 равна 4, а длина числа 7 равна 1.
Дан набор из N целых положительных чисел, каждое из которых меньше 10^8.
Необходимо определить, числа какой длины чаще всего встречаются в данном наборе и сколько в нём чисел этой длины.
Если числа разной длины встречаются одинаково часто (и чаще чем числа любой другой длины), нужно выбрать большую длину.
*/

void task_13611() {
	int size, number;
	int dl = 0;
	int kol = 0;
	int a[9] = { 0 };
	int maxDl = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		while (number > 0) {
			dl++;
			number = number / 10;
		}
		a[dl]++;
		dl = 0;
	}
	for (int i = 0; i < 9; i++) {
		if (a[i] > 0 && a[i] >= kol) {
			kol = a[i];
			maxDl = i;
		}
	}
	cout << maxDl << " " << kol << endl;
}

/* № 14242
Дан набор из N целых положительных чисел.
Для каждого числа вычисляется сумма двух последних цифр в его десятичной записи
(для однозначных чисел предпоследняя цифра считается равной нулю). Необходимо определить,
какая сумма при этом получается чаще всего. Если таких сумм несколько, необходимо вывести наибольшую из них.
*/

void task_14242() {
	int size, number;
	int a[19] = { 0 };
	int sum = 0;
	int kol = 0;
	int maxSum = 0;
	int num = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		for (int i = 0; i < 2; i++) {
			if (number > 0) {
				num = number % 10;
				sum += num;
				number = number / 10;
			}
		}
		a[sum]++;
		sum = 0;
	}
	for (int i = 0; i < 19; i++) {
		if (a[i] > 0 && a[i] >= kol) {
			kol = a[i];
			maxSum = i;
		}
	}
	cout << maxSum << endl;
}

/*№ 14286
Дан набор из N целых положительных чисел.
Для каждого числа вычисляется сумма двух последних цифр в его десятичной записи
(для однозначных чисел предпоследняя цифра считается равной нулю).
Необходимо определить, какая сумма при этом получается реже всего
(но не менее одного раза). Если таких сумм несколько, необходимо вывести наименьшую из них.
*/

void task_14286() {
	int size, number;
	int a[19] = { 0 };
	int sum = 0;
	int kol = INT_MAX;
	int maxSum = 0;
	int num = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		for (int i = 0; i < 2; i++) {
			if (number > 0) {
				num = number % 10;
				sum += num;
				number = number / 10;
			}
		}
		a[sum]++;
		sum = 0;
	}
	for (int i = 0; i < 19; i++) {
		if (a[i] > 0 && a[i] < kol) {
			kol = a[i];
			maxSum = i;
		}
	}
	cout << maxSum << endl;
}

void task_7772() {
	int size;
	int maxPr = 0;
	int el1 = 0;
	int el9 = 0;
	int maxK = 0;
	int a[7] = { 0 };
	cin >> size;

	cin >> el1;
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	cin >> el9;

	maxK = el1;
	maxPr = maxK * el9;

	for (int i = 10; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 6; j++) {
			a[j] = a[j + 1];
		}
		a[6] = el9;
		cin >> el9;
		if (el1 > maxK)
			maxK = el1;
		if (maxK * el9 > maxPr)
			maxPr = maxK * el9;
	}
	
	cout << maxPr << endl;
	// 10	100		45		55		245		35		25		10		10		10		26

}


void task_7773() {
	int size;
	int minPr = -1;
	int el1 = 0;
	int el7 = 0;
	int minK = 0;
	int minChK = -1;
	int a[5] = { 0 };
	cin >> size;

	cin >> el1;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	cin >> el7;
	minK = el1;
	if (el1 % 2 == 0) {
		minChK = el1;	
	}

	if (el1 % 2 == 0 || el7 % 2 == 0) {
		minPr = el1 * el7;
	}

	for (int i = 8; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 4; j++) {
			a[j] = a[j + 1];
		}
		a[4] = el7;
		cin >> el7;
		if (el1 < minK)
			minK = el1;
		if (el1 % 2 == 0 && el1 < minChK)
			minChK = el1;
		if (el7 % 2 == 0 && minK * el7 < minPr)
			minPr = minK * el7;
		if (minChK * el7 < minPr && minChK > -1)
			minPr = minChK * el7;
	}
	
	cout << minPr << endl;
}
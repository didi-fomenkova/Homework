﻿#include<iostream>

using namespace std;

void task_7799();
void task_8675();
void task_9179();
void task_7472(); // не работает
void task_16054();
void task_10490();
void task_15995();
void task_16402();
void task_16830();
void task_16903();
void task_17345();
void task_17391();
void task_18508();
void task_18575();
void task_18603();

int main() {

	setlocale(LC_ALL, "Russia");

	task_18603();

	return 0;
}

/* № 7799
Для заданной последовательности неотрицательных целых чисел необходимо
найти минимальную сумму двух её элементов, номера которых различаются не менее чем на 4.
Значение каждого элемента последовательности не превышает 1000.
Количество элементов последовательности не превышает 10000.
*/

void task_7799() {
	int size;
	int el1, el5;
	int minSum= INT_MAX;
	int minK = INT_MAX;
	int a[3] = { 0 };
	cin >> size;
	cin >> el1;
	minK = el1;
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	cin >> el5;
	minSum = minK + el5;
	for (int i = 6; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 2; j++) {
			a[j] = a[j + 1];
		}
		a[2] = el5;
		cin >> el5;
		if (el1 < minK)
			minK = el1;
		if (minK + el5 < minSum)
			minSum = minK + el5;
	}
	cout << minSum << endl;
}

/* № 8675
Для заданной последовательности целых чисел необходимо найти
максимальную сумму квадратов двух её элементов, номера которых различаются
не менее чем на 10. Значение каждого элемента последовательности не превышает 100.
Количество элементов последовательности не превышает 10000.
*/

void task_8675() {
	int size;
	int el1 = 0;
	int el11 = 0;
	int a[9] = { 0 };
	int maxSum = 0;
	int maxK = 0;
	cin >> el1;
	cin >> size;
	maxK = el1 * el1;
	for (int i = 0; i < 9; i++)
		cin >> a[i];
	cin >> el11;
	maxSum = maxK + el11 * el11;
	for (int i = 12; i < size + 1; i++) {
		el1  = a[0];
		for (int j = 0; j < 8; j++) {
			a[j] = a[j + 1];
		}
		a[8] = el11;
		cin >> el11;
		if (el1 * el1 > maxK)
			maxK = el1 * el1;
		if (maxK + el11 * el11 > maxSum)
			maxSum = maxK + el11 * el11;
	}
	cout << maxSum << endl;
}

/* № 9179
Для заданной последовательности вещественных чисел необходимо найти
минимальное среднее арифметическое двух её элементов, номера которых
различаются не менее чем на 9. Значение каждого элемента последовательности не превышает 1000.
Количество элементов последовательности не превышает 10000.
*/

void task_9179() {
	int size;
	float el1 = 0;
	float el10 = 0;
	float srAr = 0;
	float a[8] = { 0 };
	float minK = 0;
	cin >> size;
	cin >> el1;
	minK = el1;
	for (int i = 0; i < 8; i++)
		cin >> a[i];
	cin >> el10;
	srAr = (el1 + el10) / 2;
	for (int i = 11; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 7; j++)
			a[j] = a[j + 1];
		a[7] = el10;
		cin >> el10;
		if (el1 < minK)
			minK = el1;
		if ((minK + el10) / 2 < srAr)
			srAr = (minK + el10) / 2;
	}
	cout << srAr << endl;
}

/*№ 7472 ?? не работает с дробными числами ??
На спутнике «Фотон» установлен прибор, предназначенный для измерения энергии космических лучей.
Каждую минуту прибор передаёт по каналу связи неотрицательное вещественное число — количество энергии,
полученной за последнюю минуту, измеренное в условных единицах. Временем, в течение которого происходит передача, можно пренебречь.
Необходимо найти в заданной серии показаний прибора минимальное произведение двух показаний,
между моментами передачи которых прошло не менее 6 минут.
Количество энергии, получаемое прибором за минуту, не превышает 1000 условных единиц.
Общее количество показаний прибора в серии не превышает 10 000. 
*/

void task_7472() {
	double size;
	float el1 = 0;
	double el7 = 0;
	double minPr = INT_MAX;
	double a[5] = { 0 };
	double minEl = INT_MAX;
	cin >> size;
	cin >> el1;
	minEl = el1;
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	cin >> el7;
	minPr = minEl * el7;
	for (int i = 8; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 4; j++)
			a[j] = a[j + 1];
		a[4] = el7;
		cin >> el7;
		if (el1 < minEl)
			minEl = el1;
		if (minEl * el7 < minPr)
			minPr = minEl * el7;
	}
	cout << minPr << endl;
}

/*№ 16054
На вход программы поступает последовательность из N целых положительных чисел,
все числа в последовательности различны. Рассматриваются все пары различных элементов последовательности,
находящихся на расстоянии не меньше чем 4 (разница в индексах элементов пары должна быть 4 или более,
порядок элементов в паре неважен). Необходимо определить количество таких пар, для которых произведение элементов делится на 29.
*/

void task_16054() {
	int size;
	int a[4] = { 0 };
	int n29 = 0;
	int kol = 0;
	int el5 = 0;
	cin >> size;
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	for (int i = 5; i < size + 1; i++) {
		if (a[0] % 29 == 0)
			n29++;
		cin >> el5;
		if (el5 % 29 == 0) {
			kol += i - 4;
		}
		else
			kol += n29;
		for (int j = 0; j < 3; j++)
			a[j] = a[j + 1];
		a[3] = el5;
	}
	cout << kol << endl;
}
/*№ 10490
Датчик передаёт каждую секунду по каналу связи неотрицательное целое число,
не превосходящее 1000 — текущий результат измерений. Временем, в течение которого происходит передача, можно пренебречь.
Необходимо найти в заданной серии показаний датчика минимальное чётное произведение двух показаний,
между моментами передачи которых прошло не менее 15 секунд. Если получить такое произведение не удаётся, ответ считается равным -1.
*/

void task_10490() {
	int size;
	int el1 = 0;
	int el16 = 0;
	int minPr = 1000001;
	int a[14] = { 0 };
	cin >> size;
	cin >> el1;
	for (int i = 0; i < 14; i++)
		cin >> a[i];
	cin >> el16;
	if ((el1 % 2 == 0 || el16 % 2 == 0) && el1 * el16 < minPr)
		minPr = el1 * el16;
	for (int i = 17; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 13; j++)
			a[j] = a[j + 1];
		a[13] = el16;
		cin >> el16;
		if ((el1 % 2 == 0 || el16 % 2 == 0) && el1 * el16 < minPr)
			minPr = el1 * el16;
	}
	if (minPr == 1000001)
		minPr = -1;
	cout << minPr << endl;
}

/* № 15995
Дан набор из N ≤ 1000 натуральных чисел, каждое из которых не превышает 10000.
Из них необходимо определить, сколько имеется пар чисел, разница между индексами которых не меньше 5,
а произведение элементов в которых кратно 13. Напишите эффективную по времени и по памяти программу для решения этой задачи.
*/

void task_15995() {
	int size;
	int n13 = 0;
	int kol = 0;
	int a[5] = { 0 };
	int el6 = 0;
	cin >> size;
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	for (int i = 6; i < size + 1; i++) {
		if (a[0] % 13 == 0)
			n13++;
		cin >> el6;
		if (el6 % 13 == 0)
			kol += i - 5;
		else
			n13++;
		for (int j = 0; j < 4; j++)
			a[j] = a[j + 1];
		a[4] = el6;
	}
	cout << kol << endl;
}

/* № 16402
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности, находящихся на расстоянии не меньше 6 друг от друга
(разница в индексах элементов должна быть 6 или более).
Необходимо определить максимальную сумму такой пары.
*/

void task_16402() {
	int size;
	int el1 = 0;
	int el7 = 0;
	int a[5] = { 0 };
	int maxSum = 0;
	int maxK = 0;
	cin >> size;
	cin >> el1;
	maxK = el1;
	for (int i = 0; i < 5; i++)
		cin >> a[i];
	cin >> el7;
	maxSum = maxK + el7;
	for (int i = 8; i < size + 1; i++) {
		el1 = a[0];
		for (int j = 0; j < 4; j++)
			a[j] = a[j + 1];
		a[4] = el7;
		cin >> el7;
		if (el1 > maxK)
			maxK = el1;
		if (maxK + el7 > maxSum)
			maxSum = maxK + el7;
	}
	cout << maxSum << endl;
}

/*№ 16830
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности,
находящихся на расстоянии не меньше 6 (разница в индексах элементов должна быть 6 или более).
Необходимо определить количество пар, произведение чисел в которых кратно 6.
*/

void task_16830() {
	int size;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n6 = 0;
	int kol = 0;
	int el7 = 0;
	int a[6] = { 0 };
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		if (a[0] % 6 == 0)
			n6++;
		else if (a[0] % 2 == 0)
			n2++;
		else if (a[0] % 3 == 0)
			n3++;
		else n1++;
		cin >> el7;
		if (el7 % 6 == 0)
			kol += n1;
		else if (el7 % 3 == 0)
			kol += n2;
		else if (el7 % 2 == 0)
			kol += n3;
		else kol += n6;
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << kol << endl;
}

/* № 16903
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности, находящихся на расстоянии не меньше 10
(разница в индексах элементов должна быть 10 или более).
Необходимо определить количество пар, произведение чисел в которых кратно 10.
*/

void task_16903() {
	int size;
	int n1 = 0;
	int n2 = 0;
	int n5 = 0;
	int n10 = 0;
	int el11 = 0;
	int a[10] = { 0 };
	int kol = 0;
	cin >> size;
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	for (int i = 11; i < size + 1; i++) {
		if (a[0] % 10 == 0)
			n10++;
		else if (a[0] % 5 == 0)
			n5++;
		else if (a[0] % 2 == 0)
			n2++;
		else n1++;
		cin >> el11;
		if (el11 % 10 == 0)
			kol += n1;
		else if (el11 % 2 == 0)
			kol += n5;
		else if (el11 % 5 == 0)
			kol += n2;
		else kol += n10;
		for (int j = 0; j < 9; j++)
			a[j] = a[j + 1];
		a[9] = el11;
	}
	cout << kol << endl;
}
/*№ 17345
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности,
находящихся на расстоянии не меньше 6 (разница в индексах элементов должна быть 6 или более).
Необходимо определить количество пар, сумма чисел в которых нечётна.
*/

void task_17345() {
	int size;
	int nChet = 0;
	int nNechet = 0;
	int kol = 0;
	int el7 = 0;
	int a[6] = { 0 };
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		if (a[0] % 2 == 0)
			nChet++;
		else nNechet++;
		cin >> el7;
		if (el7 % 2 == 0)
			kol += nNechet;
		else kol += nChet;
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << kol << endl;
}
/*№ 17391
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности, находящихся на расстоянии не меньше 6 
(разница в индексах элементов должна быть 6 или более). Необходимо определить количество пар, 
сумма чисел в которых чётна.
*/
void task_17391() {
	int size;
	int nChet = 0;
	int nNechet = 0;
	int kol = 0;
	int el7 = 0;
	int a[6] = { 0 };
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		if (a[0] % 2 == 0)
			nChet++;
		else nNechet++;
		cin >> el7;
		if (el7 % 2 == 0)
			kol += nChet;
		else kol += nNechet;
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << kol << endl;
}
/*№ 18508
Дана последовательность N целых положительных чисел. Рассматриваются все пары элементов последовательности,
находящихся на расстоянии не меньше 6 (разница в индексах элементов должна быть 6 или более).
Необходимо определить максимальную нечётную сумму такой пары. Если пар с нечётной суммой нет, ответ считается равным 0.
*/

void task_18508() {
	int size;
	int nChet = 0;
	int nNechet = 0;
	int sum = 0;
	int maxSum = 0;
	int el7 = 0;
	int a[6] = { 0 };
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		if (a[0] % 2 == 0 && a[0] > nChet)
			nChet = a[0];
		else if (a[0] % 2 == 1 && a[0] > nNechet)
			nNechet = a[0];
		cin >> el7;
		if (el7 % 2 == 0)
			sum = el7 + nNechet;
		else sum = el7 + nChet;
		if (sum > maxSum)
			maxSum = sum;
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << maxSum << endl;
}

/* № 18575
Дана последовательность N целых положительных чисел. 
Рассматриваются все пары элементов последовательности, находящихся на расстоянии не меньше 6 
(разница в индексах элементов должна быть 6 или более).
Необходимо определить количество пар, сумма чисел в которых кратна 3.
*/

void task_18575() {
	int size;
	int n3 = 0;
	int b[3] = { 0 };
	int a[6] = { 0 };
	int el7 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		cin >> el7;
		b[a[0] % 3]++;
		kol = b[(3 - el7 % 3) % 3];
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << kol << endl;
}

/*№ 18603
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности,
находящихся на расстоянии не меньше 6 (разница в индексах элементов должна быть 6 или более).
Необходимо определить количество пар, разность чисел в которых кратна 3.
*/

void task_18603() {
	int size;
	int el7 = 0;
	int a[6] = { 0 };
	int kol1 = 0;
	int kol2 = 0;
	int kol0 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < 6; i++)
		cin >> a[i];
	for (int i = 7; i < size + 1; i++) {
		cin >> el7;
		if (a[0] % 3 == 0)
			kol0++;
		if (a[0] % 3 == 1)
			kol1++;
		if (a[0] % 3 == 2)
			kol2++;
		if (el7 % 3 == 0)
			kol += kol0;
		if (el7 % 3 == 1)
			kol += kol1;
		if (el7 % 3 == 2)
			kol += kol2;
		for (int j = 0; j < 5; j++)
			a[j] = a[j + 1];
		a[5] = el7;
	}
	cout << kol << endl;
}
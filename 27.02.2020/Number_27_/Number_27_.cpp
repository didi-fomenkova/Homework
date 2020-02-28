#include<iostream>

using namespace std;

void task_27_5503();
void task_27_6202();
void task_27_6971();

int main() {

	task_27_6971();

	return 0;
}


// По каналу связи передаётся последовательность положительных целых чисел, все числа не превышают 1000.
// Количество чисел известно, но может быть очень велико. Затем передаётся контрольное значение последовательности
// — наибольшее число R, удовлетворяющее следующим условиям:
// 1) R — произведение двух различных переданных элементов последовательности(«различные» означает,
// что не рассматриваются квадраты переданных чисел, произведения различных элементов последовательности, равных по величине, допускаются);
// 2) R делится на 14.
// Если такого числа R нет, то контрольное значение полагается равным 0. В результате помех при передаче как сами числа,
// так и контрольное значение могут быть искажены.
// Напишите программу, которая будет проверять правильность контрольного значения.Программа должна напечатать отчёт по следующей форме :
// Вычисленное контрольное значение : ...
// Контроль пройден(или — Контроль не пройден)
// Перед текстом программы кратко опишите используемый Вами алгоритм решения.

void task_27_5503() {
	int size, n2, n7, n14, pr, number, i, max, R;
	n2 = 0;
	n7 = 0;
	n14 = 0;
	pr = 1;
	max = 0;
	cin >> size;
	for (i = 0; i < size; ++i) {
		cin >> number;
		if (number % 2 == 0 && number % 14 != 0 && number > n2) {
			n2 = number;
		}
		else if (number % 7 == 0 && number % 14 != 0 && number > n7) {
			n7 = number;
		}
		else if (number % 14 && number > n14) {
			n14 = number;
		}
		else if (number > max) {
			max = number;
		}
	}
	if (n2 * n7 > pr) {
		R = n2 * n7;
	}
    if (n2 * n14 > pr) {
	 pr = n2 * n14;
	}
	if (n7 * n14 > pr) {
		pr = n7 * n14;
	}
	if (n14 * max > pr) {
		pr = n14 * max;
	}
	cin >> R;
	cout << "The calculated control value:" << pr << endl;
	if (pr != R) {
		cout << "Control failed" << endl;
	}
	else {
		cout << "Control passed" << endl;
	}
}

 // ?? Как подсчитать кол-во чисел??

void task_27_6202() {
	int size, number, n7, max, pr, i, control;
	n7 = 0;
	max = 0;
	pr = 1;
	cin >> size;
	for (i = 0; i < size; ++i) {
		cin >> number;
		if (number % 7 == 0 && number % 49 != 0 && number > n7&& number > 0) {
			n7 = number;
		}
		else  if (number > max&& number > 0 && number % 49 != 0) {
			max = number;
		}
	}
	if (n7 * max > pr) {
		pr = n7 * max;
	}
	cin >> control;
	cout << "Entered numbers: " << size - 1 << endl;
	cout << "Control value: " << control << endl;
	cout << "The calculated value: " << pr << endl;
	if (pr == control) {
		cout << "Values__​​match" << endl;
	}
	else {
		cout << "Values__didn't__match" << endl;
	}
}

void task_27_6971() {
	int n5, n2, max1, max2, pr, i, size, control, number;
	n5 = 0;
	n2 = 0;
	max1 = 0;
	max2 = 0;
	pr = 1;
	cin >> size;
	for (i = 0; i < size; ++i) {
		cin >> number;
		if (number > n5 && number % 10 != 0 && number % 5 == 0) {
			n5 = number;
		}
		else if (number > n2 && number % 10 != 0 && number % 2 == 0) {
			n2 = number;
		}
		else if (number > max1 && number % 10 != 0) {
			max1 = number;
		}
		else if (number > max2&& number < max1 && number % 10 != 0) {
			max2 = number;
		}
	}
	if (n2 * max1 > pr) {
		pr = max1 * n2;
	}
	if (n5 * max1 > pr) {
		pr = n5 * max1;
	}
	if (max1 * max2 > pr) {
		pr = max1 * max2;
	}
	cin >> control;
	cout << "Entered numbers: " << size << endl;
	cout << "Control value: " << control << endl;
	cout << "The calculated value: " << pr << endl;
	if (pr == control) {
		cout << "Values ​​match" << endl;
	}
	else {
		cout << "Values ​​ didn't match" << endl;
	}
}
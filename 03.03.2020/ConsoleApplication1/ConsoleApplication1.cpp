﻿#include<iostream>

using namespace std;

void task27_9708();
void task27_13373();
void task27_13754();


int main() {
	setlocale(LC_ALL, "Russian");
	
	task27_13754();

	return 0;

}

// Number 27:
/*
Последовательность натуральных чисел характеризуется числом Х — наибольшим числом,
кратным 14 и являющимся произведением двух элементов последовательности с различными номерами.
На вход программе в первой строке подаётся количество чисел N. В каждой из последующих N строк
записано одно натуральное число, не превышающее 1000.
*/

void task27_9708() {
	int number, n14, n7, n2, max, size, pr;
	cin >> size;
	n14 = 0;
	n7 = 0;
	n2 = 0;
	max = 0;
	pr = 1;
	for (int i = 0; i < size; ++i) {
		cin >> number;
		if (number % 7 == 0 && number % 14 != 0 && number > n7) {
			n7 = number;
		}
		else if (number % 2 == 0 && number % 14 != 0 && number > n2) {
			n2 = number;
		}
		else if (number % 14 == 0 && number > n14) {
			n14 = number;
		}
		else if (number > max && number % 14 != 0) {
			max = number;
		}
	}
	if (n2 * n7 > pr) {
		pr = n2 * n7;
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
	if (pr == 1) {
		cout << "Число X не найдено" << endl;
	}
	else {
		cout << pr << endl;
	}
}

/*На спутнике «Восход» установлен прибор, предназначенный для измерения солнечной активности. 
В течение времени эксперимента (это время известно заранее) прибор каждую минуту передаёт в обсерваторию
по каналу связи положительное целое число, не превышающее 1000, — количество энергии солнечного излучения,
полученной за последнюю минуту, измеренное в условных единицах.
После окончания эксперимента передаётся контрольное значение — наибольшее число R, удовлетворяющее следующим условиям:
1) R — произведение двух чисел, переданных в разные минуты;
2) R делится на 26.
Предполагается, что удовлетворяющее условиям контрольное значение существовало в момент передачи.
*/

void task27_13373() {
	int number, n26, n13, n2, max, size, pr;
	cin >> size;
	n26 = 0;
	n13 = 0;
	n2 = 0;
	max = 0;
	pr = 1;
	for (int i = 0; i < size; ++i) {
		cin >> number;
		if (number % 13 == 0 && number % 26 != 0 && number > n13) {
			n13 = number;
		}
		else if (number % 2 == 0 && number % 26 != 0 && number > n2) {
			n2 = number;
		}
		else if (number % 26 == 0 && number > n26) {
			n26 = number;
		}
		else if (number > max&& number % 26 != 0) {
			max = number;
		}
	}
	if (n2 * n13 > pr) {
		pr = n2 * n13;
	}
	if (n2 * n26 > pr) {
		pr = n2 * n26;
	}
	if (n13 * n26 > pr) {
		pr = n13 * n26;
	}
	if (n26 * max > pr) {
		pr = n26 * max;
	}
	if (pr == 1) {
		cout << "Конроль не пройден" << endl;
	}
	else {
		cout << "Вычисленное контрольное значение: " << pr << endl;
		cout << "Контроль пройден" << endl;
	}
}

/*
На вход программы поступает последовательность из N целых положительных чисел,
все числа в последовательности различны. Рассматриваются все пары различных элементов
последовательности (элементы пары не обязаны стоять в последовательности рядом, порядок
элементов в паре не важен). Необходимо определить количество пар, для которых произведение
элементов делится на 26.
Описание входных и выходных данных
В первой строке входных данных задаётся количество чисел N (1 ≤ N ≤ 1000).
В каждой из последующих N строк записано одно целое положительное число,
не превышающее 10 000. В качестве результата программа должна напечатать одно число:
количество пар, в которых произведение элементов кратно 26.
*/

void task27_13754() {
	int n26, n13, n2, size, kol, number;
	cin >> size;
	n26 = 0;
	n13 = 0;
	n2 = 0;
	kol = 0;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 13 == 0 && number % 26 != 0) {
			n13++;
		}
		else if (number % 2 == 0 && number % 26 != 0) {
			n2++;
		}
		else if (number % 26 == 0) {
			n26++;
		}
	}
	if (n2 * n13  > kol) {
		kol = (n2 * n13) ;
	}
	if (n13 * n26 > kol) {
		kol = n13 * n26 ;
	}
	if (n2 * n26  > kol) {
		kol = (n2 * n26) ;
	}
	if (n26 * (size - n26)  > kol) {
		kol = n26 * (size - n26) ;
	}
	cout << kol << endl;
}
﻿#include <iostream>

using namespace std;

void task_5291();
void task_7353();
void task_11332();
void task_11363();
void task_23925();

int main() {

	setlocale(LC_ALL, "Russian");

	task_23925();

	return  0;
}

/* № 5291
По каналу связи передаётся последовательность положительных целых чисел Х1, Х2, ... все числа не превышают 1000, их количество заранее неизвестно.
Каждое число передаётся в виде отдельной текстовой строки, содержащей десятичную запись числа.
Признаком конца передаваемой последовательности является число 0.
Участок последовательности от элемента ХT до элемента XT+N называется подъёмом, 
если на этом участке каждое следующее число больше или равно предыдущему, причем участок нельзя расширить, т.е.

1) Т = 1 или ХT-1 > ХT

2) XT+N — последний элемент последовательности или XT+N > XT+N+1.
Высотой подъёма называется разность XT+N − ХT. 
Подъём считается значительным, если высота подъёма больше величины минимального элемента этого подъема.

Напишите программу, которая вычисляет количество значительных подъемов в заданной последовательности.
Программа должна вывести результаты в следующей форме:

Получено чисел: ...

Найдено значительных подъемов: ...
 
*/

void task_5291() {
	int kol = 0;
	int number;
	int h = 0;
	int numPred = 0;
	int minEl = 10001;
	int kolH = 0;
	int el1 = -1;
	cin >> number;
	numPred = number;
	el1 = number;
	minEl = number;
	while (number != 0) {
		cin >> number;
		if (number >= numPred) {
			h += number - numPred;
			if (numPred < minEl)
				minEl = numPred;
		}
		else if (h > minEl) {
			minEl = 10001;
			h = 0;
			kolH++;
		}
		else {
			h = 0;
			minEl = 10001;
		}
		numPred = number;
		kol++;
	}
	if (el1 == 0) {
		cout << "Получено чисел: 0" << endl;
		cout << "Найдено значительных подъемов: 0" << endl;
	}
	else {
		cout << "Получено чисел: " << kol << endl;
		cout << "Найдено значительных подъемов : " << kolH << endl;
	}
}

/* № 7353
Автомобиль, участвующий в гонке, может быть оснащен двумя разными типами колес (A и B).
Вдоль трассы расположены станции, на которых можно выполнить замену колес A на B, эта операция занимает t секунд.
Замена колес B на A в ходе гонки технически невозможна. На старт можно выйти с любым комплектом.
Для каждого участка между станциями известно, за какое время можно пройти этот участок с каждым из комплектов колес.
Необходимо определить, за какое минимальное время можно пройти всю трассу.

Входные данные

В первой строке задается количество участков трассы N.
Во второй строке задается целое число t — время (в секундах) 
на замену колес A на B. В каждой из последующих N строк записано два целых числа ai и bi,
задающих время (в секундах) прохождения очередного участка с каждым из комплектов. 
В первой из этих строк указывается время прохождения участка от старта до первой станции,
во второй – от первой станции до второй и т. д.

*/

void task_7353() {
	int N, t, a, b;
	int minT = 0;
	int aSum = 0;
	cin >> N;
	cin >> t;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		aSum += a;
		if (aSum + t < minT + b)
			minT += aSum + t;
		else minT += b;
		
	}
	if (aSum < minT)
		minT = aSum;
	cout << minT << endl;
}

/*№ 11332
На вход даны пары чисел. Нужно выбрать из каждой пары по одному числу так,
чтобы сумма всех выбранных чисел была нечётна и при этом была максимально возможной.
Напишите программу, выводящую такую сумму на экран. Если же ее невозможно получить, выведите 0.
Каждый элемент в паре целый, неотрицательный.
*/

void task_11332() {
	int n, x, y;
	int sum = 0;
	int min_r = 100001;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y)
			sum += x;
		else sum += y;

		if ((abs(x - y) % 2 == 1) && (abs(x - y) < min_r)) 
			min_r  = abs(x - y);
	}

	if (sum % 2 == 1)
		cout << sum << endl;

	else if ((sum % 2 == 0) && (min_r != 100001))
		cout << sum - min_r << endl;

	else cout << "0" << endl;
}

/*№ 11363
 Имеется набор данных, состоящий из пар положительных целых чисел.
 Необходимо выбрать из каждой пары ровно одно число так, 
 чтобы сумма всех выбранных чисел не делилась на 3 и при этом была максимально возможной.
 Если получить требуемую сумму невозможно, в качестве ответа нужно выдать 0.
 */

void task_11363() {
	int n, x, y;
	int max = 0;
	int min = 100001;
	int  min_r = 100001;
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y) {
			max = x;
			min = y;
		}
		else {
			max = y;
			min = x;
		}
		if ((max - min) % 3 != 0 && (max - min) < min_r)
			min_r = max - min;
		sum += max;
	}
	if (sum % 3 == 0) {
		if (min_r == 100001)
			sum = 0;
		else
			sum -= min_r;
	}
	cout << sum << endl;
}

/*№ 23925
Дана последовательность N целых положительных чисел.
Рассматриваются все пары элементов последовательности, разность которых чётна,
и в этих парах, по крайней мере, одно из чисел пары делится на 17.
Порядок элементов в паре неважен. Среди всех таких пар нужно найти и вывести пару с максимальной суммой элементов.
Если одинаковую максимальную сумму имеет несколько пар, можно вывести любую из них.
Если подходящих пар в последовательности нет, нужно вывести два нуля.
*/

void task_23925() {
	int size, number;
	int el[2] = { 0 };
	int max[2] = { 0 }; // 17 17*17 34 68
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 17 == 0 && number % 2 == 0 && number >= el[0])
			el[0] = number;
		else if (number % 2 == 0 && number > max[0]) 
			max[0] = number;

		if (number % 17 == 0 && number % 2 != 0 && number >= el[1])
			el[1] = number;
		else if (number % 2 == 1 && number > max[1]) 
			max[1] = number;
	}
	if (el[0] + max[0] > el[1] + max[1])
		cout << el[0]  << " " << max[0];
	else
		cout << el[1] << " " << max[1];
}
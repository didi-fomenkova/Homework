// 01.03.2020.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

void task_15812();
void task_15837();

int main()
{
	task_15837();

	return 0;
}
void task_15812() {
	int n3chet, n3nechet, notn3chet, notn3nechet, c, number, size;
	n3chet = 0;
	n3nechet = 0;
	notn3chet = 0;
	notn3nechet = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cin >> number;
		if (number % 3 == 0 && number % 2 == 0) {
			n3chet++;
		}
		else if (number % 3 == 0) {
			n3nechet++;
		}
		if (number % 3 != 0 && number % 2 == 0) {
			notn3chet++;
		}
		else  if (number % 3 != 0) {
			notn3nechet++;
		}
	}
	c = n3chet * notn3nechet + n3nechet * notn3chet;
	cout << c << endl;

}

void task_15837() {
	int maxn3chet, maxn3nechet, maxnotn3chet, maxnotn3nechet, c, number, size;
	maxn3chet = -1;
	maxn3nechet = -1;
	maxnotn3chet = -1;
	maxnotn3nechet = -1;
	c = 0;
	cin >> size;
	for (int i = 0; i < size; ++i) {
		cin >> number;
		if (number % 3 == 0 && number % 2 == 0 && number > maxn3chet) {
			maxn3chet = number;
		}
		 if (number % 3 == 0 && number > maxnotn3chet && number % 2 != 0) {
			maxn3nechet = number;
		}
		if (number % 3 != 0 && number % 2 == 0 && number > maxnotn3chet) {
			maxnotn3chet = number;
		}
		 if (number % 3 != 0 && number % 2 != 0 && number > maxnotn3nechet) {
			maxnotn3nechet = number;
		}
	}
	if ((maxn3chet == -1 || maxnotn3nechet == -1) && (maxn3nechet == -1 || maxnotn3nechet == -1)) {
		cout << 0;
	}
	if (maxn3chet * maxnotn3nechet > c) {
		c = maxn3chet * maxnotn3nechet;
	}
	if (maxn3nechet * maxnotn3chet > c) {
		c = maxn3nechet * maxnotn3chet;
	}
	cout << c << endl;

}
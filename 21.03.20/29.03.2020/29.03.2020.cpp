#include <iostream>

using namespace std;

void task_18833();
void task_18729();
void task_9777();
void task_4868();

int main() {

	setlocale(LC_ALL, "Russian");

	task_4868();

	return 0;
}

/*№ 18833
На вход программы поступает последовательность из N целых положительных чисел. Рассматриваются все пары различных элементов последовательности
(элементы пары не обязаны стоять в последовательности рядом), такие что ai > aj при i < j ≤ N. Среди пар, удовлетворяющих этому условию,
необходимо найти и вывести пару с максимальной суммой элементов, которая делится на 126.
Если среди найденных пар максимальную сумму имеют несколько, то можно напечатать любую из них.
Если пар заданным условием нет, то программа должна вывести NO.
*/

void task_18833() {
	int number, size;
	int el1 = -1;
	int el2 = -1;
	int maxSum = -1;
	cin >> size;
	int a[126] = {};
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 126 == 0 && a[0] != 0 && number < a[0] && number + a[0] > maxSum) {
			maxSum = number + a[0];
			el1 = number;
			el2 = a[0];
		}
		else if (a[126 - number % 126] != 0 && number < a[126 - number % 126] && number + a[126 - number % 126] > maxSum) {
			maxSum = number + a[126 - number % 126];
			el1 = number;
			el2 = a[126 - number % 126];
		}
		if (number > a[number % 126])
			a[number % 126] = number;
	}
	if (maxSum != -1)
		cout << el2 << " " << el1 << endl;
	else
		cout << " NO " << endl;
}

/*№ 18729
На вход программы поступает последовательность из N целых положительных чисел.
Рассматриваются все пары различных элементов последовательности (элементы пары не обязаны стоять в последовательности рядом),
такие что ai > aj при i < j. Среди пар, удовлетворяющих этому условию, необходимо найти и вывести пару 
с максимальной суммой элементов, которая делится на 117. Если среди найденных пар максимальную сумму имеют несколько,
то можно напечатать любую из них.
Если пар заданным условием нет, то программа должна вывести NO.
*/

void task_18729() {
	int number, size;
	int el1 = -1;
	int el2 = -1;
	int maxSum = -1;
	int a[117] = {};
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number % 117 == 0 && a[0] != 0 && number < a[0] && number + a[0] > maxSum) {
			maxSum = number + a[0];
			el1 = number;
			el2 = a[0];
		}
		else if (a[117 - number % 117] != 0 && number < a[117 - number % 117] && number + a[117 - number % 117] > maxSum) {
			maxSum = number + a[117 - number % 117];
			el1 = number;
			el2 = a[117 - number % 117];
		}
		if (number > a[number % 117])
			a[number % 117] = number;
	}
	if (maxSum == -1)
		cout << " NO " << endl;
	else
		cout << el2 << " " << el1 << endl;
}

/*№ 9777
На плоскости задано множество точек с целочисленными координатами. 
Необходимо найти максимально возможную площадь невырожденного (то есть, имеющего ненулевую площадь) треугольника,
одна вершина которого расположена в начале координат, а две другие лежат на осях координат и при этом принадлежат заданному множеству.
Если такого треугольника не существует, необходимо вывести соответствующее сообщение.
*/

void task_9777() {
	int x, y, size;
	float S = 0;
	int xMax = 0;
	int yMax = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (x == 0 && abs(y) > yMax)
			yMax = abs(y);
		if (y == 0 && abs(x) > xMax)
			xMax = abs(x);
	}
	S = float (xMax * yMax) / float(2);
	if (S == 0)
		cout << "Треугольник не существует " << endl;
	else
		cout << S << endl;
}

/*№ 4868 ???
На плоскости дан набор точек с целочисленными координатами.
Необходимо найти такой треугольник наибольшей площади с вершинами в этих точках,
у которого нет общих точек с осью Оу, а одна из сторон лежит на оси Ох.
*/

void task_4868() {
	int x, y, size;
	int xMaxPos = INT_MIN;
	int xMinPos = INT_MAX;
	int xMaxNeg = INT_MIN;
	int xMinNeg = INT_MAX;
	int yMax = 0;
	int yKod = 0;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (y == 0 && x < xMinPos && x > 0)
			xMinPos = x;
		else if (y == 0 && x < xMinPos && x < 0)
			xMinNeg = x;
		if (y == 0 && x > xMaxPos&& x > 0)
			xMaxPos = x;
		else if (y == 0 && x > xMaxPos&& x < 0)
			xMaxNeg = x;
		if (x != 0 && abs(y) > yMax){
			yMax = abs(y);
			yKod = x;
		}
	}
	if (yKod > 0)
		S = float((xMaxPos - xMinPos) * yMax) / 2;
	else
		S = float((xMaxNeg - xMinNeg) * yMax) / 2;
	if (S == 0)
		cout << " NO " << endl;
	else
		cout << S << endl;
}

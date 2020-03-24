#include <iostream>

using namespace std;

void task_18833();
void task_18729();
void task_9777();
void task_4868();
void task_5258();
void task_6906();
void task_6938();
void task_10303();
void task_10330();
void task_10428();

int main() {

	setlocale(LC_ALL, "Russian");

	task_10428();

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

/* № 5258
Дан список точек плоскости с целочисленными координатами. Необходимо определить:

1) номер координатной четверти K, в которой находится больше всего точек;
2) количество точек в этой четверти M;
3) точку A в этой четверти, наименее удалённую от осей координат;
4) расстояние R от этой точки до ближайшей оси.
Если в нескольких четвертях расположено одинаковое количество точек, следует выбрать ту четверть,
в которой величина R меньше. При равенстве и количества точек, и величины R необходимо выбрать четверть с меньшим номером K.
Если в выбранной четверти несколько точек находятся на одинаковом минимальном расстоянии от осей координат
, нужно выбрать первую по списку. Точки, хотя бы одна из координат которых равна нулю,
считаются не принадлежащими ни одной четверти и не рассматриваются.
*/

void task_5258() {
	int x, y, size;
	int K = 0;
	int M1 = 0;
	int M2 = 0;
	int M3 = 0;
	int M4 = 0;
	int fixX1 = INT_MAX;
	int fixY1= INT_MAX;
	int fixX2 = INT_MAX;
	int fixY2 = INT_MAX;
	int fixX3 = INT_MAX;
	int fixY3 = INT_MAX;
	int fixX4 = INT_MAX;
	int fixY4 = INT_MAX;
	int R1 = INT_MAX;
	int R2 = INT_MAX;
	int R3 = INT_MAX;
	int R4 = INT_MAX;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (x > 0 && y > 0) {
			M1++;
			if (x < fixX1 && y < fixY1) {
				fixX1 = x;
				fixY1 = y;
			}
			if (abs(x) < R1)
				R1 = abs(y);
			if (abs(y) < R1)
				R1 = abs(y);
		}
		if (x < 0 && y > 0) {
			M2++;
			if (x < fixX2 && y < fixY2) {
				fixX2 = x;
				fixY2 = y;
			}
			if (abs(x) < R2)
				R2 = abs(y);
			if (abs(y) < R2)
				R2 = abs(y);
		}
		if (x < 0 && y < 0) {
			M3++;
			if (x < fixX3 && y < fixY3) {
				fixX3 = x;
				fixY3 = y;
			}
			if (abs(x) < R3)
				R3 = abs(y);
			if (abs(y) < R3)
				R3 = abs(y);
		}
		if (x > 0 && y < 0) {
			M4++;
			if (x < fixX4 && y < fixY4) {
				fixX4 = x;
				fixY4 = y;
			}
			if (abs(x) < R4)
				R4 = abs(y);
			if (abs(y) < R4)
				R4 = abs(y);
		}
	}
	if (M1 > M2 && M1 > M3 && M1 > M4) {
		K = 1;
		cout << "K = " << K << endl;
		cout << "M = " << M1 << endl;
		cout << "A = (" << fixX1 << "," << fixY1 << ")" << endl;
		cout << "R =  " << R1 << endl;
	}
	 else if (M2 > M1 && M2 > M3 && M2 > M4) {
		K = 2;
		cout << "K = " << K << endl;
		cout << "M = " << M2 << endl;
		cout << "A = (" << fixX2 << "," << fixY2 << ")" << endl;
		cout << "R =  " << R2 << endl;
	}
	 else if (M3 > M2 && M3 > M1 && M3 > M4) {
		K = 3;
		cout << "K = " << K << endl;
		cout << "M = " << M3 << endl;
		cout << "A = (" << fixX3 << "," << fixY3 << ")" << endl;
		cout << "R =  " << R3 << endl;
	}
	else if (M4 > M2 && M4 > M3 && M4 > M1) {
		K = 4;
		cout << "K = " << K << endl;
		cout << "M = " << M4 << endl;
		cout << "A = (" << fixX4 << "," << fixY4 << ")" << endl;
		cout << "R =  " << R4 << endl;
	}
	else if (M1 == M2) {
		if (R1 < R2 || R1 == R2) {
			K = 1;
			cout << "K = " << K << endl;
			cout << "M = " << M1 << endl;
			cout << "A = (" << fixX1 << "," << fixY1 << ")" << endl;
			cout << "R =  " << R1 << endl;
		}
		else if (R2 < R1) {
			K = 2;
			cout << "K = " << K << endl;
			cout << "M = " << M2 << endl;
			cout << "A = (" << fixX2 << "," << fixY2 << ")" << endl;
			cout << "R =  " << R2 << endl;
		}
	}
	else if (M1 == M3) {
		if (R1 < R3 || R1 == R3) {
			K = 1;
			cout << "K = " << K << endl;
			cout << "M = " << M1 << endl;
			cout << "A = (" << fixX1 << "," << fixY1 << ")" << endl;
			cout << "R =  " << R1 << endl;
		}
		else if (R3 < R1) {
			K = 3;
			cout << "K = " << K << endl;
			cout << "M = " << M3 << endl;
			cout << "A = (" << fixX3 << "," << fixY3 << ")" << endl;
			cout << "R =  " << R3 << endl;
		}
	}
	else if (M1 == M4) {
		if (R1 < R4 || R1 == R4) {
			K = 1;
			cout << "K = " << K << endl;
			cout << "M = " << M1 << endl;
			cout << "A = (" << fixX1 << "," << fixY1 << ")" << endl;
			cout << "R =  " << R1 << endl;
		}
		else if (R4 < R1) {
			K = 4;
			cout << "K = " << K << endl;
			cout << "M = " << M4 << endl;
			cout << "A = (" << fixX4 << "," << fixY4 << ")" << endl;
			cout << "R =  " << R4 << endl;
		}
	}
	else if (M2 == M3) {
		if (R2 < R3 || R3 == R2) {
			K = 2;
			cout << "K = " << K << endl;
			cout << "M = " << M2 << endl;
			cout << "A = (" << fixX2 << "," << fixY2 << ")" << endl;
			cout << "R =  " << R2 << endl;
		}
		else if (R3 < R2) {
			K = 3;
			cout << "K = " << K << endl;
			cout << "M = " << M3 << endl;
			cout << "A = (" << fixX3 << "," << fixY3 << ")" << endl;
			cout << "R =  " << R3 << endl;
		}
	}
	else if (M2 == M4) {
		if (R2 < R4 || R4 == R2) {
			K = 2;
			cout << "K = " << K << endl;
			cout << "M = " << M2 << endl;
			cout << "A = (" << fixX2 << "," << fixY2 << ")" << endl;
			cout << "R =  " << R2 << endl;
		}
		else if (R4 < R2) {
			K = 4;
			cout << "K = " << K << endl;
			cout << "M = " << M4 << endl;
			cout << "A = (" << fixX4 << "," << fixY4 << ")" << endl;
			cout << "R =  " << R4 << endl;
		}
	}
	else if (M3 == M4) {
	if (R3 < R4 || R3 == R4) {
		K = 3;
		cout << "K = " << K << endl;
		cout << "M = " << M3 << endl;
		cout << "A = (" << fixX3 << "," << fixY3 << ")" << endl;
		cout << "R =  " << R3 << endl;
	}
	else if (R4 < R3) {
		K = 4;
		cout << "K = " << K << endl;
		cout << "M = " << M4 << endl;
		cout << "A = (" << fixX4 << "," << fixY4 << ")" << endl;
		cout << "R =  " << R4 << endl;
	}
	}
}

/*№ 6906
На плоскости дан набор точек с целочисленными координатами.
Необходимо найти четырёхугольник наибольшей площади с вершинами в этих точках,
две вершины которого лежат на оси Ox, а две оставшиеся – по разные стороны от оси Ox.
*/
void task_6906() {
	int x, y, size;
	int maxX = INT_MIN;
	int minX = INT_MAX;
	int maxY = 0;
	int minY = 0;
	float S1 = 0;
	float S2 = 0;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (y == 0 && x > maxX)
			maxX = x;
		if (y == 0 && x < minX)
			minX = x;
		if (y > 0 && abs(y) > maxY)
			maxY = abs(y);
		if (y < 0 && abs(y) > minY)
			minY = abs(y);
	}
	S1 = float((maxX - minX) * maxY) / 2;
	S2 = float((maxX - minX) * minY) / 2;
	if (S1 != 0 && S2 != 0)
		S = S1 + S2;
	cout << S << endl;
}
/* № 6938
На плоскости дан набор точек с целочисленными координатами.
Необходимо найти четырёхугольник наибольшей площади с вершинами в этих точках,
две вершины которого лежат на оси Oy, а две оставшиеся — по разные стороны от оси Oy.
*/
void task_6938() {
	int x, y, size;
	int maxY = INT_MIN;
	int minY = INT_MAX;
	int maxX = 0;
	int minX = 0;
	float S1 = 0;
	float S2 = 0;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (x == 0 && y > maxY)
			maxY = y;
		if (x == 0 && y < minY)
			minY = y;
		if (x > 0 && abs(x) > maxX)
			maxX = abs(x);
		if (y < 0 && abs(x) > minX)
			minX = abs(x);
	}
	S1 = float((maxY - minY) * maxX) / 2;
	S2 = float((maxY - minY) * minX) / 2;
	if (S1 != 0 && S2 != 0)
		S = S1 + S2;
	cout << S << endl;
}

/*№ 10303
На плоскости задано множество точек с целочисленными координатами.
Необходимо найти максимально возможную площадь невырожденного (то есть имеющего ненулевую площадь) треугольника,
одна вершина которого расположена в начале координат, а две другие лежат на биссектрисах углов, образованных осями координат,
и при этом принадлежат заданному множеству. Если такого треугольника не существует, необходимо вывести соответствующее сообщение.
*/

void task_10303() {
	int x, y, size;
	int maxA = 0;
	int maxB = 0;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (y == x && abs(x) > maxA)
			maxA = abs(x);
		if (y == -x && abs(x) > maxB)
			maxB = abs(x);
	}
	S = maxA * maxB;
	if (S == 0)
		cout << "Треугольник не существует" << endl;
	else
		cout << S << endl;
}
/*№ 10330
На плоскости задано множество точек с целочисленными координатами.
Необходимо найти минимально возможную площадь невырожденного (то есть имеющего ненулевую площадь)
треугольника, одна вершина которого расположена в начале координат, а две другие лежат на биссектрисах углов,
образованных осями координат, и при этом ринадлежат заданному множеству. Если такого треугольника не существует,
необходимо вывести соответствующее сообщение.
*/

void task_10330() {
	int x, y, size;
	int minA = 0;
	int minB = 0;
	float S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (y == x && ((abs(x) < minA) ||( minA == 0)))
			minA = abs(x);
		if (y == -x && ((abs(x) < minB) || (minB == 0)))
			minB = abs(x);
	}
	S = minA * minB;
	if (S == 0)
		cout << "Треугольник не существует" << endl;
	else
		cout << S << endl;
}

/*№ 10428
На плоскости задано множество точек с целочисленными координатами. Необходимо найти количество отрезков, обладающих следующими свойствами:
1) оба конца отрезка принадлежат заданному множеству;
2) ни один конец отрезка не лежит на осях координат;
3) отрезок пересекается с обеими осями координат.
*/

void task_10428() {
	int x, y, size;
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	int k4 = 0;
	int kol = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> x >> y;
		if (x > 0 && y > 0)
			k1++;
		if (x < 0 && y > 0)
			k2++;
		if (x < 0 && y < 0)
			k3++;
		if (x > 0 && y < 0)
			k4++;
	}
	kol = k1 * k3 + k2 * k4;
	cout << kol << endl;
}
#include <iostream>

using namespace std;

void task3614();

int main()
{
    task3614();

    return 0;
}

// Дан целочисленный массив из 40 элементов. Элементы массива могут принимать произвольные значения.
// Опишите на русском языке или на одном из языков программирования алгоритм, который находит и выводит
// значение второго максимума (элемента, который в отсортированном по невозрастанию массиве стоял бы вторым).

void task3614() {
    int const N = 7;
    int a[N];
    int i, k, max, max2;
    for (i = 0; i < N; i++)
        cin >> a[i];
    max = INT_MIN;
    max2 = INT_MIN;
    for (i = 0; i < N; i++) {
        if (a[i] > max2) {
            if (a[i] > max) {
                max = a[i];
            }
            else {
                max2 = a[i];
            }
        }
    }
    cout << "Second max is " << max2 << endl;
}
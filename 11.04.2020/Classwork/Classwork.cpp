#include <iostream>

using namespace std;

void task_1();

int main() {

	task_1();

	return 0;
}

void task_1() {
	int size;
	double number;
	double MaxPr = 0;
	double MaxPrGr1 = -1;
	double MaxPrNegGr1 = 0;
	double MinNegGr1 = 10000000000;
	double MaxPos01 = 0;
	double MaxNeg01F = 0;
	double MaxNeg01S = 0;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> number;
		if (number >= 1) {
			if (MaxPrGr1 == -1) {
				MaxPrGr1 = number;
			}
			else {
				MaxPrGr1 *= number;
			}
			
		}
		if (number > 0 && number < 1 && number > MaxPos01)
			MaxPos01 = number;
		if (number < 0 && abs(number) > 0 && abs(number) < 1 && abs(number) >= MaxNeg01F) {
			MaxNeg01S = MaxNeg01F;
			MaxNeg01F = abs(number);
		}
		else if (number < 0 && abs(number) > 0 && abs(number) < 1 && abs(number) > MaxNeg01S) {
			MaxNeg01S = abs(number);
		}
		if (number < 0 && abs(number) >= 1) {
			if (abs(number) < MinNegGr1)
				MinNegGr1 = number;
			MaxPrNegGr1 *= number;
		}	
	}
	if (MaxPrGr1 > -1)
		MaxPr = MaxPrGr1;
	else if (MaxPos01 > 0)
		MaxPr = MaxPos01;
	else if (MaxNeg01F != 0 && MaxNeg01S != 0 && MaxNeg01F * MaxNeg01S > MaxPr)
		MaxPr = MaxNeg01F * MaxNeg01S;
	else if (MaxPrNegGr1 != 0 && MaxPrNegGr1 / MinNegGr1 > MaxPr)
		MaxPr = MaxPrNegGr1 / MinNegGr1;
	cout << MaxPr << endl;
}
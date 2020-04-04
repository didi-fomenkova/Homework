#include <iostream>

using namespace std;

void task_6436();

int main() {

	task_6436();

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
		par[i] = i; //???
	for (int j = 0; j < size; j++) {
		cin >> number;
		bal[number]++;
	}
	for (int i = 16; i > 0; i--) {
		for (int j = 1; j < 16; j++) {
			if (bal[j - 1] < bal[j]) {
				number = bal[j - 1];
				bal[j] = bal[j - 1];
				bal[j - 1] = number;
				number = par[j - 1];
				par[j] = par[j - 1];
				par[j - 1] = number;
			}
		}
	}
	for (int i = 0; i < 16; i++) {
		if (par[i] > 0)
			cout << par[i] << " " << bal[i] << endl;
	}
}
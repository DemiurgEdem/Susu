#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	/*const int n = 3;
	int a[3][3];

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			cout << a[i][j];
		}
	}


	int magicSum = 0;
	for (int i = 0; i < n; i++) {
		magicSum += a[0][i];
	}*/


	/* Дана строка. Сколько слов имеют длину, равную N символам? */
	
	srand(time(0));
	string s{ "Не очень-то вежливо уходить из гостей сразу, как только ты наелся" };
	string sub;
	int b = 2, e = rand() % s.length();
	sub = s.substr(b, e);
	cout << s << endl;
	cout << sub << endl;
	s = sub;
	cout << s << endl;
}

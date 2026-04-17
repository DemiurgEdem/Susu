#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	/*const int n = 3;
	int a[3][3];

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			cin >> a[i][j];
		}
	}

	cout << "введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; i < n; j++) {
			cout << a[i][j];
		}
	}*/


	/*int magicSum = 0;
	for (int i = 0; i < n; i++) {
		magicSum += a[0][i];
	}*/


	/* Дана строка. Сколько слов имеют длину, равную N символам? */

	int count = 0;
	string word{ "" };

	string s{ "" };
	cout << "Введите строку: \n";
	cin >> s;

	int N;
	cout << "Введите требуемое количество символов в слове: \n";
	cin >> N;

	for (int i = 0; i < s.length(); i++){
		if (s[i] == ' ') {
			if (word.length() == N) count += 1;
			word.clear();
		}
		else {
			word += s[i];
		}
	}
	word.clear();

	cout << word << "\n" << count << "\n";


	system("pause");
}

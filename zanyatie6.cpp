#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*const int n = 3;
	int a[3][3];

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

    // эталонное магическое число
	int magicSum = 0;
	for (int i = 0; i < n; i++) {
		magicSum += a[0][i];
	}

	bool isMagic = true;

    // Проверка строк и столбцов
    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        int columnSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += a[i][j];
            columnSum += a[j][i];
        }
        if (rowSum != magicSum || columnSum != magicSum) {
            isMagic = false;
        }
    }

    // Проверка диагоналей
    int firstDiag = 0;
    int secondDiag = 0;
    for (int i = 0; i < n; i++) {
        firstDiag += a[i][i];
        secondDiag += a[i][n - 1 - i];
    }
    if (firstDiag != magicSum || secondDiag != magicSum) {
        isMagic = false;
    }

    // Вывод результата
    if (isMagic) {
        cout << "\nМатрица является магическим квадратом!";
        cout << "\nМагическая сумма: " << magicSum << endl;
    }
    else {
        cout << "\nЭто не магический квадрат." << endl;
    }*/




	/* Дана строка. Сколько слов имеют длину, равную N символам? */
	
	int count = 0;
	int strCount = 0;
	string s;
	string s2;
	int N;
	

	cout << "Введите строку: \n";
	getline(cin, s);
	s += " ";

	cout << "Введите требуемое количество символов в слове: \n";
	cin >> N;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			if (strCount == N) count += 1;
			strCount = 0;
		}
		else strCount += 1;
	}

	cout << "Колличество слов: " << count << "\n";

	system("pause");
}

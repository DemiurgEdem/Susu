#include <iostream>
#include <cstring>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	string str = "Привет";
	int len = str.length();
	cout << str.substr(len - 3) << endl;

	if (str.substr(len - 3) == "вет") cout << "Прокатит";
	else "Облом";
}

https://your-durev.com/sub/XnrDoHxU6xXjqzG6MGYMqA

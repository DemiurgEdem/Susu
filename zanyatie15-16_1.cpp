#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> sortVector(vector<int> v) {
	sort(v.begin(), v.end());
	return v;
}

vector<int> reverseVector(vector<int> v) {
	reverse(v.begin(), v.end());
	return v;
}

int sum(vector<int> arr) {
	return accumulate(arr.begin(), arr.end(), 0);
}

int findFrequency(vector<int> arr, int x) {
	return count(arr.begin(), arr.end(), x);
}

void printer(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}
	cout << "----------------" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> v = { 3, 7, 5, 2, 8, 9, 2, 4 };
	vector<int> dopVector = {};

	dopVector = sortVector(v);
	printer(dopVector);

	dopVector = reverseVector(v);
	printer(dopVector);

	cout << "Сумма чисел в векторе: " << sum(v) << endl;
	int x = 2;
	cout << "Число " << x << " появляется " << findFrequency(v, x) << " раз(а)" << endl;
}

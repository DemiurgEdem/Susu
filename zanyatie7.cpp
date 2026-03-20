#include "stdafx.h"
#include <iostream>
using namespace std;

float max(float, float);
float max(float ar[], int k);
float min(float, float);
float min(float ar[], int k);


int main()
{
	setlocale(LC_ALL, "");
	const int ka = 5;
	const int kb = 6;
	float a[ka] = { 5.2, -0.2, 3.0, -11.4, 5.6 };
	float b[kb] = { 6.2, -1.2, 3.5, -14.4, 5.9, 9.2 };
	float MIN_a = min(a, ka);
	float MAX_a = max(a, ka);
	float MIN_b = min(b, kb);
	float MAX_b = max(b, kb);
	cout << MIN_a * MIN_b << "\n";
	cout << MAX_a * MAX_b << "\n";

	system("pause");
}

float max(float a, float b)
{
	return a > b ? a : b;
}

float max(float ar[], int k)
{
	float m = ar[0];
	for (int i = 1; i < k; i++) m = max(m, ar[i]);
	return m;
}

float min(float a, float b)
{
	return a < b ? a : b;
}

float min(float ar[], int k)
{
	float m = ar[0];
	for (int i = 1; i < k; i++) m = max(m, ar[i]);
	return m;
}

#include "stdafx.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	
	/*double summer = 0;
	for (double n = 1; n <= 25; n++){
		summer += pow(-1, n) * ((n*n + 1) / n);
	}
	printf("%lf\n", summer);*/

	/*double w = 0;
	for (int i = 0; i <= 25; i++){
		w = 4 * i*i*i * exp(-2 * sqrt(i));
		printf("%i. %lf\n", i, w);
	}*/

	double x = 2;
	double eps = 0.0000001;
	int i = 1;
	double a = -x * x / 4;
	double s = a;
	double abs_a = a;

	while (true){

		if (abs_a < 0) abs_a = -abs_a;

		if (abs_a <= eps) break;

		a = a * (-x * x * i) / 
	}

	system("pause");
}

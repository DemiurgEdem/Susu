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

	double a, x = 2, z = -1, s = 0;
	int i = 1;

	a = z * x * x / 4;

	printf("%lf, %lf, %lf", a, z, s);



	system("pause");
}

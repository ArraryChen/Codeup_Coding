#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	double sum = 0.0;

	double a1 = 2, a2 = 3;
	double b1 = 1, b2 = 2;

	for (int i = 0; i < 20; i++)
	{
		if ( i % 2 == 0 )
		{
			 sum += a1 / b1;
			 a1 = a1 + a2;
			 b1 = b1 + b2;
		}
		else
		{
			sum += a2/ b2;
			a2 = a1 + a2;
			b2 = b1 + b2;
		}
	}

	printf("%.6f\n", sum);

	system("pause");
	return 0;
}

#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

int main(){

	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	if ( pow(b, 2.0) - 4 * a * c < 0 )
	{
		printf("No real roots!");
	}
	else
	{
		double r1 = ( -b + sqrt( pow(b, 2.0) - 4 * a * c ) ) / 2 * a;
		double r2 = ( -b - sqrt( pow(b, 2.0) - 4 * a * c ) ) / 2 * a;
		printf("r1=%7.2f\n", r1);
		printf("r2=%7.2f\n", r2);
	}

	system("pause");
	return 0;
}

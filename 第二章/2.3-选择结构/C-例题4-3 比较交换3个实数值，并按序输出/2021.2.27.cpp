#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	if ( a <= b && a <= c ) // a最小
	{
		if ( b <= c ) // a <= b <= c
		{
			printf("%.2f %.2f %.2f\n", a, b, c);
		}
		else // a <= c < b
		{
			printf("%.2f %.2f %.2f\n", a, c, b);
		}
	}
	else if ( b <= a && b <= c ) // b最小
	{
		if ( a <= c ) // b <= a <= c
		{
			printf("%.2f %.2f %.2f\n", b, a, c);
		}
		else // b <= c < a
		{
			printf("%.2f %.2f %.2f\n", b, c, a);
		}
	}
	else // c最小
	{
		if ( a <= b ) // c <= a <= b
		{
			printf("%.2f %.2f %.2f\n", c, a, b);
		}
		else // c <= b < a
		{
			printf("%.2f %.2f %.2f\n", c, b, a);
		}
	}

	system("pause");
	return 0;
}

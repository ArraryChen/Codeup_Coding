#include<cstdio>
#include<iostream>

using namespace std;

void Max(int *a, int *b, int *c){
	
	if ( *a >= *b && *a >= *c )
	{
		if ( *b >= *c ) // a > b > c
		{
			printf("%d %d %d\n", *a, *b, *c);
		}
		else // a > c > b
		{
			printf("%d %d %d\n", *a, *c, *b);
		}
	}
	else if ( *b >= *a && *b >= *c )
	{
		if ( *a >= *c ) // b > a > c
		{
			printf("%d %d %d\n", *b, *a, *c);
		}
		else // b > c > a
		{
			printf("%d %d %d\n", *b, *c, *a);
		}
	}
	else if ( *c >= *a && *c >= *b )
	{
		if ( *a >= *b ) // c > a > b
		{
			printf("%d %d %d\n", *c, *a, *b);
		}
		else // c > b > a
		{
			printf("%d %d %d\n", *c, *b, *a);
		}
	}
}


int main(){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	Max(&a, &b, &c);

	system("pause");
	return 0;
}

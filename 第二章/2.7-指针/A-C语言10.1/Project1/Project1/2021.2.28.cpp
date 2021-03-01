#include<cstdio>
#include<iostream>

using namespace std;

void Max(int *a, int *b){

	if ( *a >= *b )
	{
		printf("%d %d\n", *a, *b);
	}
	else
	{
		printf("%d %d\n", *b, *a);
	}
}


int main(){

	int a, b;
	scanf("%d %d", &a, &b);

	Max(&a, &b);


	system("pause");
	return 0;
}

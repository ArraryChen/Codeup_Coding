#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int sum = 0;

	int i = 1;
	do
	{
		sum += i++;
		
	} while ( i <= 100 );

	printf("%d\n", sum);

	system("pause");
	return 0;
}

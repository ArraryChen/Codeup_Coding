#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int sum = 0;
	int i = 1;
	while ( i <= 100 )
	{
		sum += i++;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}

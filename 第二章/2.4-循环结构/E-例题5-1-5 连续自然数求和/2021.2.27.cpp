#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int i = 1;
	int sum = 0;

	while ( sum <= 1000 )
	{
		sum += i++;
	}

	printf("%d\n", i - 1);

	system("pause");
	return 0;
}

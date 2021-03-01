#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}

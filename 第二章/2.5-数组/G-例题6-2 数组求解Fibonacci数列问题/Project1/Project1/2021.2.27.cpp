#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 30;

int main(){

	int num[maxn];
	
	num[0] = 1, num[1] = 1;

	for (int i = 2; i < 20; i++)
	{
		num[i] = num[i-2] + num[i-1];
	}

	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", num[i]);
	}


	system("pause");
	return 0;
}

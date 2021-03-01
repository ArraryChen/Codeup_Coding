#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int num[10];
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}
	
	//最小值与第一个数对换
	int min_pos = 0;
	for (int i = 1; i < 10; i++)
	{
		if ( num[i] < num[min_pos] )
		{
			min_pos = i;
		}
	}
	int temp = num[0];
	num[0] = num[min_pos];
	num[min_pos] = temp;

	//最大值与最后一个数对换
	int max_pos = 0;
	for (int i = 1; i < 10; i++)
	{
		if ( num[i] > num[max_pos] )
		{
			max_pos = i;
		}
	}
	temp = num[9];
	num[9] = num[max_pos];
	num[max_pos] = temp;

	for (int i = 0; i < 10; i++)
	{
		printf("%d", num[i]);
		if ( i < 9 ) printf(" ");
		else printf("\n");
	}

	system("pause");
	return 0;
}

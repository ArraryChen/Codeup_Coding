#include<cstdio>
#include<iostream>

using namespace std;

int num[10];

void input(int num[]){

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}
}

void process(int num[]){

	int min_pos = 0;
	for (int i = 0; i < 10; i++)
	{
		if ( num[i] < num[min_pos] )
		{
			min_pos = i;
		}
	}
	swap( num[0], num[min_pos] );

	int max_pos = 0;
	for (int i = 0; i < 10; i++)
	{
		if ( num[i] > num[max_pos] )
		{
			max_pos = i;
		}
	}
	swap( num[9], num[max_pos] );

}

void output(int num[]){

	for (int i = 0; i < 10; i++)
	{
		printf("%d", num[i]);
		if ( i < 9 ) printf(" ");
		else printf("\n");
	}
}

int main(){

	input(num);

	process(num);

	output(num);

	system("pause");
	return 0;
}

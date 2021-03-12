#include<cstdio>
#include<iostream>

using namespace std;

int nums[10];

void input(int nums[]){

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &nums[i]);
	}

}

void process(int nums[]){

	int min = 0x3fffffff, pos = -1;

	for (int i = 0; i < 10; i++)
	{
		if ( nums[i] < min )
		{
			min = nums[i];
			pos = i;
		}
	}

	int temp = nums[0];
	nums[0] = min;
	nums[pos] = temp;

	int max = 0;

	pos = -1;

	for (int i = 0; i < 10; i++)
	{
		if ( nums[i] > max )
		{
			max = nums[i];
			pos = i;
		}
	}

	temp = nums[9];
	nums[9] = max;
	nums[pos] = temp;

}

void output(int nums[]){

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", nums[i]);
	}

}

int main(){

	input(nums);

	process(nums);

	output(nums);

	system("pause");
	return 0;
}

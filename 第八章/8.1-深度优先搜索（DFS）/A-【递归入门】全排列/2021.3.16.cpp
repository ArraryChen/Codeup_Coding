#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	int nums[20];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}

	do
	{
		for (int i = 0; i < n; i++)
		{
			printf("%d", nums[i]);
			if ( i < n - 1 ) printf(" ");
			else printf("\n");
		}
	} while ( next_permutation(nums, nums+n) );

	system("pause");
	return 0;
}

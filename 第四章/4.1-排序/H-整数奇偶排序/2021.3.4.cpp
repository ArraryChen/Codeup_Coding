#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

bool cmp1(int a, int b){

	return a < b;

}

bool cmp2(int a, int b){

	return a > b;

}

int main(){

	int num[10];

	while (cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6] >> num[7] >> num[8] >> num[9])
	{
		int odd[10], odd_count = 0, even[10], even_count = 0;

		//分别存放奇数和偶数
		for (int i = 0; i < 10; i++)
		{
			if ( num[i] % 2 == 0 )
			{
				even[even_count++] = num[i];
			}
			else
			{
				odd[odd_count++] = num[i];
			}
		}

		sort(odd, odd + odd_count, cmp2);
		sort(even, even + even_count, cmp1);

		for (int i = 0; i < odd_count; i++)
		{
			printf("%d ", odd[i]);
		}

		for (int i = 0; i < even_count; i++)
		{
			printf("%d", even[i]);
			if ( i < even_count - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

int num[maxn];

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		//A1部分
		int A1 = 0;
		for (int i = 0; i < n; i++)
		{
			if ( num[i] % 5 == 0 && num[i] % 2 == 0 )
			{
				A1 += num[i];
			}
		}
		if ( A1 == 0 ) printf("N ");
		else printf("%d ", A1);
		//A2部分
		int A2 = 0;
		int count1 = 0;
		for (int i = 0; i < n; i++)
		{
			if ( num[i] % 5 == 1 )
			{
				if ( count1 % 2 == 0 ) A2 += num[i];
				else A2 -= num[i];

				count1++;
			}
		}
		if ( count1 == 0 ) printf("N ");
		else printf("%d ", A2);
		//A3部分
		int A3 = 0;
		for (int i = 0; i < n; i++)
		{
			if ( num[i] % 5 == 2 )
			{
				A3++;
			}
		}
		if ( A3 == 0 ) printf("N ");
		else printf("%d ", A3);
		//A4部分
		double A4 = 0;
		int count2 = 0;
		for (int i = 0; i < n; i++)
		{
			if ( num[i] % 5 == 3 )
			{
				A4 += num[i];
				count2++;
			}
		}
		A4 /= count2;
		if ( count2 == 0 ) printf("N ");
		else printf("%.1f ", A4);
		//A5部分
		bool result = false;
		int A5 = 0;
		for (int i = 0; i < n; i++)
		{
			if ( num[i] % 5 == 4 )
			{
				if ( result == false )
				{
					A5 = num[i];
					result = true;
				}
				else if ( result == true && num[i] > A5 )
				{
					A5 = num[i];
				}
			}
		}
		if ( result == false ) printf("N\n");
		else printf("%d\n", A5);
	}

	system("pause");
	return 0;
}

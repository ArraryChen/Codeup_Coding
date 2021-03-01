#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 20;

int main(){

	char A[maxn], Pa, B[maxn], Pb;
	while ( scanf("%s %c %s %c", A, &Pa, B, &Pb) != EOF )
	{
		int sum1 = 0, sum2 = 0;
		int i = 0, j = 0;
		while ( A[i] != '\0' )
		{
			if ( A[i] == Pa ) sum1 = sum1 * 10 + (Pa - '0');
			i++;
		}

		while ( B[j] != '\0' )
		{
			if ( B[j] == Pb ) sum2 = sum2 * 10 + (Pb - '0');
			j++;
		}
		printf("%d\n", sum1 + sum2 );
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

int num[210];

int findNum(int x, int left, int right){

	while ( left <= right )
	{
		int mid = (left + right) / 2;

		if ( x == num[mid] ) return mid;
		else if ( x > num[mid] ) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n < 1 || n > 200 ) break;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		int x;
		scanf("%d", &x);

		printf("%d\n", findNum(x, 0, n-1));
	}

	system("pause");
	return 0;
}

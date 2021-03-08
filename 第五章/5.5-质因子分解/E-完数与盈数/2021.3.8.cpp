#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	vector<int> a, b;

	for (int i = 2; i <= 60; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
		{
			if ( i % j == 0 )
			{
				sum += j;
			}
		}
		if ( sum == i ) a.push_back(i);
		else if ( sum > i ) b.push_back(i);
	}

	printf("E: ");
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d", a[i]);
		if ( i < a.size() - 1 ) printf(" ");
		else printf("\n");
	}

	printf("G: ");
	for (int i = 0; i < b.size(); i++)
	{
		printf("%d", b[i]);
		if ( i < b.size() - 1 ) printf(" ");
		else printf("\n");
	}

	system("pause");
	return 0;
}

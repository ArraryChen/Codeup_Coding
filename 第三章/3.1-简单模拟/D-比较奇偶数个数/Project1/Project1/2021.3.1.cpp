#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		int count1 = 0;
		int count2 = 0;

		int temp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			if ( temp % 2 == 0 ) count1++;
			else count2++;
		}
		if ( count1 > count2 ) printf("NO\n");
		else printf("YES\n");
	}

	system("pause");
	return 0;
}

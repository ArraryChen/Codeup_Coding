#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	long long num;
	while ( scanf("%lld", &num) != EOF )
	{
		//num < 0
		if ( num < 0 ) break;

		//num = 0
		else if ( num == 0 )
		{
			printf("0\n");
			continue;
		}

		//num > 0
		vector<int> ans;
		while ( num )
		{
			ans.push_back( num % 8 );
			num /= 8;
		}

		for (int i = ans.size() -1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

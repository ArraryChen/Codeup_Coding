#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int func(int n){

	if ( n == 0 ) return 0;
	else if ( n == 1 ) return 1;
	else return func( n - 1 ) + func( n - 2 );

}

int main(){

	int m;
	scanf("%d", &m);

	while ( m-- )
	{
		int n;
		scanf("%d", &n);

		//��һ��:���㱾����Ҫ��������쳲����������е���
		vector<int> ans;
		for (int i = 0; i < 2 * n - 1; i++)
		{
			ans.push_back( func(i) );
		}
		
		//�ڶ���:���ͼ��(�ȿո�,������)
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 2 * (n - i); j++)
			{
				printf(" ");
			}
			for (int j = 0; j < 2 * i - 1; j++)
			{
				printf("%d", ans[j]);
				if ( j < 2 * i - 2 ) printf(" ");
				else printf("\n");
			}
		}
	}

	system("pause");
	return 0;
}

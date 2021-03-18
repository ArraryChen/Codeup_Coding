#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int m, n;
	while ( scanf("%d %d", &m, &n) != EOF && m && n )
	{
		int left, right, cnt;

		cnt = 0;
		left = right = m;

		while ( left <= n )
		{
			cnt += right - left + 1;

			left = left * 2;			//left: 左子树的第一个儿子
			right = right * 2 + 1;		//right: 右子树的最后一个儿子
			if ( right > n ) right = n;
		}
		
		printf("%d\n", cnt);
	}

	system("pause");
	return 0;
}

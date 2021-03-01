#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//num:保存输入的n个整数
		vector<int> num;

		//temp:临时变量,保存当前输入的整数
		int temp;
		
		//循环输入
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			num.push_back(temp);
		}

		//m:临时变量,保存待查询的整数有m个
		int m;
		scanf("%d", &m);

		//循环输入
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &temp);

			//find:判断num中是否有该整数temp(默认没有)
			bool find = false;
			for (int i = 0; i < num.size(); i++)
			{
				if ( num[i] == temp )
				{
					find = true;
					break;
				}
			}
			if ( find == true ) printf("YES\n");
			else printf("NO\n");
		}
 	}

	system("pause");
	return 0;
}

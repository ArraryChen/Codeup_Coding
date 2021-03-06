#include<cstdio>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 110;

int main(){

	//m:保存样例数
	int m;
	scanf("%d", &m);

	//循环测试 m 组样例
	while ( m-- )
	{
		//n:保存待输入的数字总数
		int n;
		scanf("%d", &n);

		//num:保存输入的整数
		//group:保存输入的整数对应的分组
		//visit:保存输入的组是否有效(默认所有组无效),仅当输入整数对应到某一组时,该组生效
		int num[maxn], group[maxn];
		bool visit[maxn] = { false };

		//s:可以理解为一个数组,数组的每个元素是一个map,这个map就代表的是一个group,保存了整数及其出现的次数
		map<int, int> s[maxn];

		//循环输入n个数
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		//循环输入n个数对应分组
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &group[i]);
			visit[group[i]] = true;	//使得该组生效
		}

		//初始化每一组
		for (int i = 0; i < n; i++)
		{
			//只访问生效的组
			if ( visit[group[i]] == true )
			{
				//初始化组内,保存输入的整数,初始化其出现次数为0
				for (int j = 0; j < n; j++)
				{
					s[group[i]][num[j]] = 0;
				}
			}
		}

		//统计
		for (int i = 0; i < n; i++)
		{
			//group[i]:某个整数所在的组号
			//s[ group[i] ]:表示编号为 group[i] 的组， s[ group[i] ].find( num[i] )表示能否在该组内找到整数 num[i]
			if ( s[ group[i] ].find( num[i] ) != s[ group[i] ].end() ) s[ group[i] ][ num[i] ]++;	//若能找到,次数加一
			else s[ group[i] ][ num[i] ] = 1;														//若找不到,初始化次数为一
		}

		//输出
		for (int i = 0; i <= n; i++)
		{
			//只访问生效的组
			if ( visit[i] == true )
			{
				printf("%d={", i);

				//统计次数
				int count2 = 0;

				//统计组内元素个数
				int size = s[i].size();

				//遍历该组内元素及其频数
				for (auto it = s[i].begin(); it != s[i].end(); it++)
				{
					printf("%d=%d", it->first, it->second);

					//计数器加一
					count2++;

					if ( count2 < size ) printf(",");		//未访问到一组的末尾元素
					else printf("}\n");						//访问到一组的末尾元素
				}
			}
		}
	}//while end

	system("pause");
	return 0;
}

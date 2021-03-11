#include<cstdio>
#include<set>
#include<iostream>

using namespace std;

set<int> sets[100];

int main(){

	//n:集合数
	int n;
	scanf("%d", &n);

	//num:该集合中有多少个数
	int num;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		
		//temp:临时变量,暂存数字
		int temp;
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &temp);
			sets[i].insert(temp);
		}
	}

	//s:待查询的集合数
	int s;
	scanf("%d", &s);

	//n1, n2:两个待查询的集合编号
	int n1, n2;

	//因为set是有序的,所以可以按序遍历两个set,同时比较
	for (int i = 0; i < s; i++)
	{
		scanf("%d %d", &n1, &n2);

		int same_count = 0, dis_count = 0;
		
		set<int>::iterator it1 = sets[n1].begin(), it2 = sets[n2].begin();

		for ( ;it1 != sets[n1].end() && it2 != sets[n2].end() ; )
		{
			if ( *it1 == *it2 )
			{
				same_count++;
				it1++;
				it2++;
			}
			else if ( *it1 < *it2 )
			{
				dis_count++;
				it1++;
			}
			else
			{
				dis_count++;
				it2++;
			}
		}
		while ( it1 != sets[n1].end() )
		{
			dis_count++;
			it1++;
		}
		while ( it2 != sets[n2].end() )
		{
			dis_count++;
			it2++;
		}
		double sim = 100.0 * same_count / (dis_count + same_count);
		printf("%.1f%%\n", sim);
	}
	system("pause");
	return 0;
}
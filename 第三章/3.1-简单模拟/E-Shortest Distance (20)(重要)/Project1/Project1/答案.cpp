#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 100010;

//dis数组:保存起点到各个结点的距离
int dis[maxn] = {0};

int main(){

	//n:结点数
	int n;
	scanf("%d", &n);

	//distance:临时变量,保存相邻两个结点间的距离
	//sum:保存从起点(结点1)到终点(结点n)的距离
	int distance = 0, sum = 0;

	//循环输入结点间的距离
	//利用sum统计从起点(结点1)到各个结点的距离,存入dis数组中
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &distance);
		sum += distance;

		dis[i] = sum;
	}

	//m:待检测的m对结点的最短距离
	int m;
	scanf("%d", &m);

	//left, right:左右端点
	int left, right;

	//循环输入
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &left, &right);
		if ( left > right ) swap( left, right );		//为了便于计算,将左端点令为两者最小值,右端点令为两者最大值

		int temp = dis[right - 1] - dis[left - 1];		//统计从端点 left->right 的正向距离
		printf("%d\n", min(temp, sum - temp));			//由于从端点 left->right 有正向距离和反向距离(该图是个环),两者最小值即为最短路径
	}

	system("pause");
	return 0;
}

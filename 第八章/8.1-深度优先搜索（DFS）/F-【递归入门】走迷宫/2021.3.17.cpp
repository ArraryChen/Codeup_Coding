#include<cstdio>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

typedef struct loc {
	int x;
	int y;
	
	loc(int x,int y) 
	{
		this->x = x;
		this->y = y;
	}
	
	loc() { }
};
const int maxn = 20;

//n, m: 迷宫的行, 列
//count1: 可行的方案数
int n, m, count1 = 0;

//a: 迷宫矩阵
int a[maxn][maxn] = {0};

//road: 选择路线
vector<pair<int, int>> road;

//Begin, End: 起点, 终点
loc Begin, End;

//四种行动方案
loc MOVE[4] = {loc(0,-1),loc(-1,0),loc(0,1),loc(1,0)};

void DFS(int x,int y)
{
	road.push_back(make_pair(x,y));

	if (x == End.x&&y == End.y)
	{
		for (int i = 0, S = road.size(); i<S; ++i)
		{
			printf("(%d,%d)", road[i].first,road[i].second);
			if (i != S - 1)
				printf("->");
		}
		++count1;
		printf("\n");
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		//如果这个方向可行, 走这个方向
		if (a[x + MOVE[i].x][y + MOVE[i].y] == 1)
		{
			//为了避免走回头路, 设置其为0
			a[x + MOVE[i].x][y + MOVE[i].y] = 0;

			//从该点开始,继续寻找可行路线
			DFS(x + MOVE[i].x, y + MOVE[i].y);
			
			//经过该点的路线已经遍历完, 弹出该点
			road.pop_back();
			
			//恢复其可行性
			a[x + MOVE[i].x][y + MOVE[i].y] = 1;
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		//初始化
		count1 = 0;
		road.clear();

		//输入迷宫矩阵
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		
		//输入起点, 终点
		scanf("%d %d", &Begin.x, &Begin.y);
		scanf("%d %d", &End.x, &End.y);

		//将起点设为0，就不能再退回来了
		a[Begin.x][Begin.y] = 0;

		//搜索可行的路线
		DFS(Begin.x, Begin.y);

		//特判
		if (count1 == 0)
			printf("-1\n");
	}
	return 0;
}

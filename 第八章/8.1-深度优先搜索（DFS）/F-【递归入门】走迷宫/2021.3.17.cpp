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

//n, m: �Թ�����, ��
//count1: ���еķ�����
int n, m, count1 = 0;

//a: �Թ�����
int a[maxn][maxn] = {0};

//road: ѡ��·��
vector<pair<int, int>> road;

//Begin, End: ���, �յ�
loc Begin, End;

//�����ж�����
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
		//�������������, ���������
		if (a[x + MOVE[i].x][y + MOVE[i].y] == 1)
		{
			//Ϊ�˱����߻�ͷ·, ������Ϊ0
			a[x + MOVE[i].x][y + MOVE[i].y] = 0;

			//�Ӹõ㿪ʼ,����Ѱ�ҿ���·��
			DFS(x + MOVE[i].x, y + MOVE[i].y);
			
			//�����õ��·���Ѿ�������, �����õ�
			road.pop_back();
			
			//�ָ��������
			a[x + MOVE[i].x][y + MOVE[i].y] = 1;
		}
	}
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		//��ʼ��
		count1 = 0;
		road.clear();

		//�����Թ�����
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		
		//�������, �յ�
		scanf("%d %d", &Begin.x, &Begin.y);
		scanf("%d %d", &End.x, &End.y);

		//�������Ϊ0���Ͳ������˻�����
		a[Begin.x][Begin.y] = 0;

		//�������е�·��
		DFS(Begin.x, Begin.y);

		//����
		if (count1 == 0)
			printf("-1\n");
	}
	return 0;
}

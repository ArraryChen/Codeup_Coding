////���Ǳ������
////���⣺����ж�ͼ���л�? ����һ:DFS ������:��������
//
////�˴�����DFS
//
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//#include<iostream>
//
//using namespace std;
//
//const int maxv = 55;
//const int INF = 1000000000;
//
//int n, G[maxv][maxv];
//bool vis[maxv];
//
//bool DFS(int u){
//
//	vis[u] = true;
//	for (int i = 0; i < n; i++)
//	{
//		if ( i == u )
//			continue;
//
//		if ( G[u][i] != 0 )
//		{
//			if ( vis[i] == true )
//				return true;
//			else
//				if(DFS(i))
//					return true;
//		}
//	}
//	return false;
//}
//
//bool DFSTrave(){
//
//	//flag:�ж�һ��ͼ�Ƿ��л�
//	bool flag = false;
//
//	for (int i = 0; i < n; i++)
//	{
//		//����ÿһ����ͨ����
//		if ( vis[i] == false )
//			flag = DFS(i);
//
//		//������ͨ��������
//		if ( flag )
//			break;
//	}
//	return flag;
//}
//
//int main(){
//
//	while ( scanf("%d", &n) != EOF && n )
//	{
//		memset(vis, false, sizeof(vis));
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				scanf("%d", &G[i][j]);
//			}
//		}
//
//		if(DFSTrave())
//			printf("ERROR\n");
//		else
//		{
//			printf("NO\n");
//		}
//	}
//
//
//	system("pause");
//	return 0;
//}

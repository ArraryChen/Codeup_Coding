#include<cstdio>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 110;

int main(){

	//m:����������
	int m;
	scanf("%d", &m);

	//ѭ������ m ������
	while ( m-- )
	{
		//n:������������������
		int n;
		scanf("%d", &n);

		//num:�������������
		//group:���������������Ӧ�ķ���
		//visit:������������Ƿ���Ч(Ĭ����������Ч),��������������Ӧ��ĳһ��ʱ,������Ч
		int num[maxn], group[maxn];
		bool visit[maxn] = { false };

		//s:�������Ϊһ������,�����ÿ��Ԫ����һ��map,���map�ʹ������һ��group,����������������ֵĴ���
		map<int, int> s[maxn];

		//ѭ������n����
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}

		//ѭ������n������Ӧ����
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &group[i]);
			visit[group[i]] = true;	//ʹ�ø�����Ч
		}

		//��ʼ��ÿһ��
		for (int i = 0; i < n; i++)
		{
			//ֻ������Ч����
			if ( visit[group[i]] == true )
			{
				//��ʼ������,�������������,��ʼ������ִ���Ϊ0
				for (int j = 0; j < n; j++)
				{
					s[group[i]][num[j]] = 0;
				}
			}
		}

		//ͳ��
		for (int i = 0; i < n; i++)
		{
			//group[i]:ĳ���������ڵ����
			//s[ group[i] ]:��ʾ���Ϊ group[i] ���飬 s[ group[i] ].find( num[i] )��ʾ�ܷ��ڸ������ҵ����� num[i]
			if ( s[ group[i] ].find( num[i] ) != s[ group[i] ].end() ) s[ group[i] ][ num[i] ]++;	//�����ҵ�,������һ
			else s[ group[i] ][ num[i] ] = 1;														//���Ҳ���,��ʼ������Ϊһ
		}

		//���
		for (int i = 0; i <= n; i++)
		{
			//ֻ������Ч����
			if ( visit[i] == true )
			{
				printf("%d={", i);

				//ͳ�ƴ���
				int count2 = 0;

				//ͳ������Ԫ�ظ���
				int size = s[i].size();

				//����������Ԫ�ؼ���Ƶ��
				for (auto it = s[i].begin(); it != s[i].end(); it++)
				{
					printf("%d=%d", it->first, it->second);

					//��������һ
					count2++;

					if ( count2 < size ) printf(",");		//δ���ʵ�һ���ĩβԪ��
					else printf("}\n");						//���ʵ�һ���ĩβԪ��
				}
			}
		}
	}//while end

	system("pause");
	return 0;
}

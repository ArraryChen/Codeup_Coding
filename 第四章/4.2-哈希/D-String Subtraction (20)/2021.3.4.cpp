#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

int main(){

	//str1, str2:�����ַ���,�����������ַ���
	char str1[maxn], str2[maxn];

	while ( cin.getline(str1,maxn) )
	{
		cin.getline(str2,maxn);

		//len1, len2:���߳���
		int len1 = strlen(str1), len2 = strlen(str2);

		//visit:����ĳ���ַ��Ƿ���Ա����(false:����, true:������)
		bool visit[maxn] = { false };

		//����str2��ÿһ���ַ�
		for (int i = 0; i < len2; i++)
		{
			//����str1��ÿһ���ַ�
			for (int j = 0; j < len1; j++)
			{
				//����ǰ��⵽str1�е��ַ���str2�е��ַ���ͬ
				if ( str1[j] == str2[i] )
				{
					visit[j] = true;		//�����Ϊ���������
				}
			}
		}

		//����str1�е��ַ�
		for (int i = 0; i < len1; i++)
		{
			if ( visit[i] == false ) printf("%c", str1[i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10010;

int main(){

	//str1, str2:输入字符串,待作减法的字符串
	char str1[maxn], str2[maxn];

	while ( cin.getline(str1,maxn) )
	{
		cin.getline(str2,maxn);

		//len1, len2:两者长度
		int len1 = strlen(str1), len2 = strlen(str2);

		//visit:保存某个字符是否可以被输出(false:可以, true:不可以)
		bool visit[maxn] = { false };

		//遍历str2的每一个字符
		for (int i = 0; i < len2; i++)
		{
			//遍历str1的每一个字符
			for (int j = 0; j < len1; j++)
			{
				//若当前检测到str1中的字符与str2中的字符相同
				if ( str1[j] == str2[i] )
				{
					visit[j] = true;		//标记其为不可以输出
				}
			}
		}

		//遍历str1中的字符
		for (int i = 0; i < len1; i++)
		{
			if ( visit[i] == false ) printf("%c", str1[i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

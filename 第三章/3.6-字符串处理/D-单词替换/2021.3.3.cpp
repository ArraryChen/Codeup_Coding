#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

const int maxn = 1000;

int main(){

	//str:字符串
	//a:待替换的单词
	//b:将被替换的单词
	char str[maxn], a[maxn], b[maxn];

	//输入字符串
	while ( cin.get(str, maxn) )
	{
		//读取回车符
		getchar();

		//输入a, b单词
		cin.getline(a, maxn);
		cin.getline(b, maxn);
		
		//words:保存输入字符串中的每个单词
		vector<char> words[100];

		//i, j:索引
		int i = 0, j = 0;

		//遍历字符串
		//抽取出每个单词存入words中
		while ( str[i] != '\0' )
		{
			//若遇到空格,或者遍历到字符串末尾,退出while
			while ( str[i] != ' ' && str[i] != '\0' )
			{
				words[j].push_back(str[i]);
				i++;
			}
			//当后面可能还有单词时,i++
			if (str[i] == ' ') i++;

			//j:统计单词的个数
			j++;
		}

		//遍历words
		for (int i = 0; i < j; i++)
		{
			//result:判断该单词是否与待替换的单词相同(默认相同)
			bool result = true;
			for (int k = 0; k < words[i].size(); k++)
			{
				if ( words[i][k] != a[k] )	//若该单词与代替换单词不同
				{
					result = false;			//result = false
					break;					//break
				}
			}
			//若该单词与代替换的单词相同
			if ( result == true )
			{
				words[i].clear();			//清空该单词
				for (int k = 0; b[k] != '\0'; k++)	//存入将被替换的单词
				{
					words[i].push_back(b[k]);
				}
			}
			//输出单词
			for (int k = 0; k < words[i].size(); k++)
			{
				printf("%c", words[i][k]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}

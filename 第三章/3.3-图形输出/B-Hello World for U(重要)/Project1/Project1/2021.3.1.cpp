//题目难点:在于行数的计算 & 中间字符(空格)的计算(要看懂题意给我式子)

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 100;

int main(){

	//str:待输入的字符串
	char str[maxn];
	scanf("%s", str);

	//输入字符串的长度
	int length = strlen(str);

	//side:两边的字符数
	int side = (length + 2) / 3;

	//中间的字符数
	int mid = length - side * 2;

	//i:当前遍历到的字符
	int i = 0;

	//由于前side - 1中间有空格的缘故,所以循环先循环输出前side-1行
	for (int j = 0; i < side - 1; i++, j++)
	{
		printf("%c", str[j]);
		for (int k = 0; k < mid; k++)
		{
			printf(" ");
		}
		printf("%c\n", str[length-j-1]);
	}
	
	//再单独输出最后一行
	while ( i <= length - side )
	{
		printf("%c", str[i++]);
	}

	system("pause");
	return 0;
}

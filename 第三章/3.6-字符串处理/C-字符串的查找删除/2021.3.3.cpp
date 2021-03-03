//这个方法比较繁琐

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 10000;

int main(){

	//str1:短字符串
	//str2:若干字符串
	char str1[maxn], str2[maxn];
	scanf("%s", str1);
	getchar();
	
	//str1_len:短字符串的长度
	int str1_len = strlen(str1);

	//循环输入若干字符串
	while ( cin.getline(str2, maxn) )
	{
		//i:保存输入字符串中,当前待检查的字符索引
		int i = 0;

		//当遍历到字符串的尾部时,退出while循环
		while ( str2[i] != '\0' )
		{
			//j:保存短字符串的位置
			int j = 0;

			//temp_pos:保存当前字符串的位置
			int temp_pos = i;
			
			//判断当前字符是否为空格
			if ( str2[i] == ' ' )
			{
				//若为空格,则以从后往前的方式向前覆盖
				while ( str2[i] != '\0' )
				{
					str2[i] = str2[i+1];
					i++;
				}
				//退回到空格的位置,当此时的空格已经被其后的字符所覆盖
				i = temp_pos;
			}

			//用当前待检测的字串和短字符串比较

			//可以继续进行比较的情况: 1.非字母字符但相同	2.字母字符,但大小写不同
			while ( str2[i] == str1[j] || str2[i] == str1[j] - 'a' + 'A' || str2[i] == str1[j] - 'A' + 'a' )
			{
				i++;
				j++;
				if ( j == str1_len ) break;
			}

			//当遍历到短字符的尾部时
			if( j == str1_len )
			{
				//从前往后覆盖到输入字符串中的短字符
				i = temp_pos;
				j = temp_pos + str1_len;

				//直至到短字符串的尾部
				while ( str2[j] != '\0' )
				{
					str2[i] = str2[j];
					i++;
					j++;
				}
				//增加上结束符
				str2[i] = '\0';
				i = temp_pos;
			}
			//若没有,则继续下一个字符的比较
			else 
			{
				i = temp_pos;
				i++;
			}
		}//while end

		//输出
		printf("%s\n", str2);
	}

	system("pause");
	return 0;
}

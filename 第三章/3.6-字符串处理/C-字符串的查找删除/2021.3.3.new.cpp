/**
    作者：谯胜平
    来源：胜平博客
    原文：https://www.qsp.net.cn/art/106.html
    思路：    基本思路是，使用gets或者scanf+getchar进行读取短字符串，因为scanf函数不会读取也不会去掉末尾的换行符，
		  因此用scanf时还需要getchar（目的是去读单个字符）。
		      每次输入的长字符串使用gets进行读取，然后遍历读取的长字符串，使用短字符串的第一个字符与其进行比对，
		  如果“相等”则将长字符串的相应位置置为空格（最后输出时跳过空格即可），如果匹配的话就继续往下比较，
		  直到匹配的字符个数等于短字符串长度，则跳出内层循环，进行下一轮匹配，直到遍历完整个长字符串。
			  我判断字符是否相等的方法是使用绝对值函数(abs(a - b) == 32 || a == b)，网上有人说将其转化成小写，我觉得完全没必要。
		  如果有的话，将那些字符赋值为’?’，然后对i从0遍历。最后输出非问号和空格的字符
**/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int Equal(char a, char b) {
	//通过a和b的绝对值判断两个字母是否“相等”
	if (abs(a - b) == 32 || a == b) return 1;
	else return 0;
}

int main()
{
	char c[1000], b[1000];
	gets(c);
	while (gets(b) != NULL) {
		int len = strlen(b);
		for (int i = 0; i < len; i++) {
			//如果b字符串中有字符和c[0]相等的字符就开始匹配
			if (Equal(b[i], c[0])) {
				int j = 1;
				i++; //b的下标加1
				while (j < strlen(c) && Equal(b[i], c[j])) {
					i++;
					j++;
				}
				//表示匹配成功，将b中匹配到的部分置为空格
				if (j == strlen(c)) {
					for (int k = i - j; k < i; k++) {
						b[k] = ' ';
					}
				}
				i--; //i此时为最后一个空格的位置
			}
		}
		//去除空格输出
		for (int i = 0; i < len; i++) {
			if (b[i] != ' ') {
				printf("%c", b[i]);
			}
		}
		printf("\n");
	}

	return 0;
}
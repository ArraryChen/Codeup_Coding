//由于double为64位,而题目要求,每行数据不超过100个字符 >= 64 , 用double不可行

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

//浮点数加法,小数部分相加,整数部分相加
struct bign{

	int d1[200];	//整数部分
	int d2[200];	//小数部分
	int len1;		//整数部分长度
	int len2;		//小数部分长度

	bign(){         //初始化操作
		memset(d1, 0, sizeof(d1));
		memset(d2, 0, sizeof(d2));
		len1 = len2 = 0;
	}
};

//以字符串形式输入浮点数, 将其转换成bign类型的浮点数
bign change(char str[]){

	bign a;
	int i = 0;
	
	//由于大整数加法时,先加低位再到高位,所以存储时,从低位到高位顺序存储
	//用while循环,找到整数部分最低位的索引
	while ( str[i] != '.' ) i++;		
	
	//整数部分
	for (int j = i - 1; j >= 0; j--)
	{
		a.d1[a.len1++] = str[j] - '0';
	}

	//用while循环,找到小数部分最低位的索引
	while ( str[i] != '\0' ) i++;

	//小数部分
	for (int j = i - 1; str[j] != '.'; j--)
	{
		a.d2[a.len2++] = str[j] - '0';
	}

	//返回转换后的浮点数
	return a;
}

//浮点数加法
bign add(bign a, bign b){

	//c:和数 ( a + b = c )
	bign c;

	//当我们在计算浮点数时,先计算小数部分,再计算整数部分
	//但由于小数部分的位数可能存在不一致问题,所以先计算两个加数,小数部分长度的差值
	int sub_len = (a.len2 >= b.len2) ? a.len2 - b.len2 : b.len2 - a.len2;

	//a1:小数部分索引
	//b1:小数部分索引
	int a1 = 0, b1 = 0;

	//先把多出的小数部分的位数,先加到和数上
	if ( a.len2 > b.len2 )
	{
		for (a1 = 0; a1 < sub_len; a1++)
		{
			c.d2[c.len2++] = a.d2[a1];
		}
	}
	else if ( b.len2 > a.len2 )
	{
		for (b1 = 0; b1 < sub_len; b1++)
		{
			c.d2[c.len2++] = b.d2[b1];
		}
	}

	//carry:进位
	int carry = 0;

	//小数部分(按照大整数加法)计算,先算低位,再算高位,注意进位
	for (; b1 < b.len2 || a1 < a.len2; a1++, b1++)
	{
		int temp = a.d2[a1] + b.d2[b1] + carry;
		c.d2[c.len2++] = temp % 10;
		carry = temp / 10;
	}

	//整数部分(按照大整数加法)计算,先算低位,再算高位,注意小数部分上来的进位
	for (int i = 0; i < a.len1 || i < b.len1; i++)
	{
		int temp = a.d1[i] + b.d1[i] + carry;
		c.d1[c.len1++] += temp % 10;
		carry = temp / 10;
	}
	
	//返回和数
	return c;
}

//打印浮点数
void print(bign a){

	//先输出整数部分
	for (int i = a.len1 - 1; i >= 0; i--)
	{
		printf("%d", a.d1[i]);
	}

	//由于整数和小数是分开存储的,输出完整数后,需要输出小数点
	printf(".");

	//由于小数部分是从低位到高位保存的,低位部分可能存在着无效的零
	//例如:3.56 + 2.34 = 5.90 后面这个零不必输出

	//j:小数部分最后一位有效位的索引(小数部分是从低位到高位存储的)
	int j = 0;
	while ( a.d2[j] == 0 ) j++;

	//再输出整数部分
	for (int i = a.len2 - 1; i >= 0; i--)
	{
		if ( i < j ) break;
		printf("%d", a.d2[i]);
	}
	printf("\n");
}

int main(){

	//n:样例数
	int n;
	scanf("%d", &n);
	while ( n-- )
	{
		//str1, str2:以字符串形式输入浮点数
		char str1[200], str2[200];
		scanf("%s", str1);
		scanf("%s", str2);

		bign a = change(str1);
		bign b = change(str2);
			
		print(add(a, b));
		
		//每组测试数据之间有一个空行
		getchar();
	}

	system("pause");
	return 0;
}

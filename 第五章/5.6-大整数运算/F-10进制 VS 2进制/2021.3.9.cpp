//出自:https://blog.csdn.net/qq_34432960/article/details/88620884

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct bign{

	int d[1010];
	int len;

	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

//将字符数组保存的数转换为bign
bign change(char str[]){

	bign a;
	a.len = strlen(str);

	for (int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}
	return a;
}

//除法操作

//a:bign类型的数
//m:bign的进制
//b:除数
//r:余数
bign divide(bign a, int m, int b, int &r){

	bign c;
	c.len = a.len;

	r = 0;

	for (int i = a.len - 1; i >= 0; i--)
	{
		r = r * m + a.d[i];

		if ( r >= b )
		{
			c.d[i] = r / b;
			r = r % b;
		}
		else
		{
			c.d[i] = 0;
		}
	}
	//如果除法结束后的数,高位有0,表明下次作除法时,从下一位开始即可
	//case:170 / 2 = 085
	//商的高位0,不必参与运算,故 c.len--
	while ( c.len >= 1 && c.d[c.len - 1] == 0 ) c.len--;

	return c;
}

int main(){
	
	bign x;

	//j:索引
	//r:保存余数
	int j = 0, r = 0;

	//注意输入的1000位十进制整数转换为二进制时,位数可能要多余1000位,所以要开大些
	//str:保存输入的十进制数
	//bin:保存转换后的二进制数
	//ans:保存最终十进制结果
	char str[1010], ans[2000], bin[3500];

	//输入待转换的十进制数
	while ( scanf("%s", str) != EOF )
	{
		//初始化 j, r
		j = r = 0;

		//将字符串输入转换为 bign
		x = change(str);

		//通过除基取余法,将十进制转换为二进制数(转换后的二进制是从低位到高位顺序排放的)
		while ( x.len >= 1 )
		{
			x = divide(x, 10, 2, r);
			bin[j++] = r + '0';
		}
		//记得末尾加上结束符
		bin[j] = '\0';

		//将二进制数转换为 bign (由于数组低位存的是余数的低位,数组的高位存的是余数的高位)
		//change()函数内是从数组高位到低位顺序转换的,完成了逆序转换的操作
		x = change(bin);
		
		//初始化 j
		j = 0;

		//通过除基取余法,将二进制转换为十进制数
		while ( x.len >= 1 )
		{
			x = divide(x, 2, 10, r);
			ans[j++] = r + '0';
		}
		//记得末尾加上结束符
		ans[j] = '\0';

		//由于低位存的是十进制的低位,高位存的是十进制的高位
		//逆序输出
		for (int i = j - 1; i >= 0; i--)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

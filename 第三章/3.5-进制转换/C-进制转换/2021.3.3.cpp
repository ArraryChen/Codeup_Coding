#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

using namespace std;

void conversion(char str[], vector<int> &ans){

	//length:以字符串形式存放待转换的十进制数
	int length = strlen(str);

	//k:保存对每一位取余时的余数(下一位在计算时使用到)
	//这里可以理解为做除法时,高位除剩的余数,低位需要在下一次除法时使用
	int k;

	//循环
	for (int i = 0; i < length; )
	{
		k = 0;

		//循环做一次除法(按位运算)
		for (int j = 0; j < length; j++)
		{
			int t = (k * 10 + str[j] - '0') % 2;		//t:按位做,取余计算,得到该位置的余数,留给低位计算使用
			str[j] = (k * 10 + str[j] - '0') / 2 + '0';	//str[j]:按位做,除法计算,更新该位置
			k = t;										//保存t至k
		}
		ans.push_back(k);								//此时的k为,最后一个数除剩下的余数,正好符合在对整数取余时得到的是最低位的余数(存进ans)
		while ( str[i] == '0' ) i++;					//若除法计算使得高位出现了0,则i++; 如:100 / 2 = 050 高位出现了0,故下一次从5开始,进行除法运算
	}
}
//下面是一个样例,读者不妨尝试过一遍,加深对算法的理解
//case:40
//i = 0, length = strlen(str) = 2

//4 % 2 = 0 -> t -> k
//4 / 2 = 2 -> str[0]
//0 % 0 = 0 -> t -> k -> ans[0] = 0
//0 / 0 = 0 -> str[1]

//2 % 2 = 0 -> t -> k
//2 / 2 = 1 -> str[0]
//0 % 0 = 0 -> t -> k -> ans[1] = 0
//0 / 0 = 0 -> str[1] 

//1 % 2 = 1 -> t -> k
//1 / 2 = 0 -> str[0]
//10 % 2 = 0 -> t -> k -> ans[2] = 0
//10 / 2 = 5 -> str[1]

//str[0] == '0' -> i++ -> i = 1

//5 % 2 = 1 -> t -> k -> ans[3] = 1
//5 / 2 = 2 -> str[1]

//2 % 2 = 0 -> t -> k -> ans[4] = 0
//2 / 2 = 1 -> str[1]

//1 % 2 = 1 -> t -> k -> ans[5] = 0
//1 / 2 = 0 -> str[1]

//str[1] == '0' -> i++ -> i = 2

//for end

int main(){

	//str:以字符串形式保存待转换的十进制数
	char str[40];
	while ( scanf("%s", str) != EOF )
	{
		//ans:存放转换后的二进制数(按逆序存放的)(除基取余法先得到的是最低位)
		vector<int> ans;

		//转换
		conversion(str, ans);

		//逆序输出ans,即为转换后的二进制数
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

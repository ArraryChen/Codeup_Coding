//八皇后问题

#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>

using namespace std;

//count1:八皇后可行的方案数
//n:棋盘的规模,由于题意为8,设置为8
int count1 = 0, n = 8;

//temp:保存当前待检查的序列
//ans:保存可行的序列(由于八皇后可行序列92,定义维度为100)
vector<int> temp, ans[100];

//hashTable:保存某一行是否已被选中(false:未选中)
bool hashTable[100] = { false };


void generateP(int index){
	//若此时已经递归n+1次了(也就是说temp中已经有n个数了,说明每一行已经有棋子放置)
	//需要检查该摆放方案是否可行
	if ( index == n + 1 )
	{
		//flag:标记,默认是可行的
		bool flag = true;
		
		//遍历每一个元素
		for (int i = 1; i <= n; i++)
		{
			//由于当遍历到元素i时,前面的棋子已经和元素i比较过,无需再次比较
			for (int j = i + 1; j <= n; j++)
			{
				//判断元素i和元素j是否在同一对角线上
				//第i行 - 第j行 的差的绝对值 = temp中的第i个元素 - temp中的第j个元素 的差的绝对值时--->表明i和j元素在一个对角线上
				if ( abs(i - j) == abs(temp[i] - temp[j]) )	//难点之处
				{
					flag = false;
					break;
				}
			}
			//当已经判断出该方案不可行,直接退出遍历,无需再次进行检查
			if ( flag == false ) break;
		}
		//若该方案可行,保存进ans,同时计数count1加一
		if (flag) ans[count1++] = temp;
		return;
	}

	//保存的序列还没有到n个,需要再次进行筛选
	for (int x = 1; x <= n; x++)
	{
		//hashTable[x] == false,判断x行是否被选中
		if (hashTable[x] == false)
		{                           //未选中
			temp.push_back(x);		//将该行的行号放进temp
			hashTable[x] = true;	//设置hashTable[x] =  true 表示该行已被选中
			generateP(index + 1);	//进行下一次递归
			hashTable[x] = false;	//递归完成,取消该行被选中,再选择下一行进行递归
			temp.pop_back();		//弹出temp
		}
	}
}

int main(){

	//由于行号从1开始,为了编程方便,令temp[1]开始存放序列,故先存放0进temp
	temp.push_back(0);

	//从1开始
	generateP(1);

	//m:保存测试数据的组数n
	int m;
	scanf("%d", &m);

	while ( m-- )
	{
		//check:待输出的第check个串
		int check;
		scanf("%d", &check);
		
		for (int i = 1; i < ans[check-1].size(); i++)
		{
			printf("%d", ans[check-1][i]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

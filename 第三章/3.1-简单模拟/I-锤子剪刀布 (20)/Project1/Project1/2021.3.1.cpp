#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	getchar();
	//分别保存甲乙胜,平,负的次数
	int a1 = 0, b1 = 0, c1 = 0;
	int a2 = 0, b2 = 0, c2 = 0;
	//分别保存甲乙胜时,各个手势出现的次数
	int J_count1 = 0, C_count1 = 0, B_count1 = 0;
	int J_count2 = 0, C_count2 = 0, B_count2 = 0;
	//a, b:临时变量,保存甲乙输入的手势
	char a, b;
	for (int i = 0; i < n; i++)
	{
		scanf("%c %c", &a, &b);
		getchar();
		//相同,平局
		if ( a == b )
		{
			b1++;
			b2++;
		}
		//甲剪刀,乙布
		else if ( a == 'J' && b == 'B' )
		{
			a1++;
			c2++;
			J_count1++;
		}
		//甲剪刀,乙锤子
		else if ( a == 'J' && b == 'C' )
		{
			c1++;
			a2++;
			C_count2++;
		}
		//甲石头,乙剪刀
		else if ( a == 'C' && b == 'J' )
		{
			a1++;
			c2++;
			C_count1++;
		}
		//甲石头,乙布
		else if ( a == 'C' && b == 'B' )
		{
			c1++;
			a2++;
			B_count2++;
		}
		//甲布,乙剪刀
		else if ( a == 'B' && b == 'J' )
		{
			c1++;
			a2++;
			J_count2++;
		}
		//甲布,乙锤子
		else if ( a == 'B' && b == 'C' )
		{
			a1++;
			c2++;
			B_count1++;
		}
	}//for输入结束
	printf("%d %d %d\n", a1, b1, c1);
	printf("%d %d %d\n", a2, b2, c2);

	if ( B_count1 >= C_count1 && B_count1 >= J_count1 ) printf("B ");
	else if ( C_count1 > B_count1 && C_count1 >= J_count1 ) printf("C ");
	else if ( J_count1 > B_count1 && J_count1 > C_count1 ) printf("J ");

	if ( B_count2 >= C_count2 && B_count2 >= J_count2 ) printf("B\n");
	else if ( C_count2 > B_count2 && C_count2 >= J_count2 ) printf("C\n");
	else if ( J_count2 > B_count2 && J_count2 > C_count2 ) printf("J\n");

	system("pause");
	return 0;
}

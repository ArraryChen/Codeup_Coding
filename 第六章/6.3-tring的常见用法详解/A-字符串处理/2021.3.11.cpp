//参考:https://blog.csdn.net/kayle1995/article/details/91632827

//备注:修正了参考站点里面代码的错误,原代码在codeup是答案错误的,修正以后可以pass

//体会:这题我真的肝了好久,心里只有淦,还是看不太懂5555orz

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(){

	//case: 34.56 + 2.45e2 = 2.7956e2

	//str1, str2:以字符串形式输入两个数
    char str1[50], str2[50];

	//s:和数
	//s1:加数1 
	//s2:加数2
    long long s, s1, s2, ans;
    
	//a:和数s的指数
	//a1:加数s1的指数
	//a2:加数s2的指数
	int a, a1, a2;
		
	//b:输入时的指数
	//c:临时变量
	int b, c;

	//flag:标记 
	//flag = 1负数
	//flag = 0正数
	int w, flag;
    
	//输入两个数
	while( scanf("%s %s",str1,str2) != EOF )
	{
        s1 = s2 = flag = b = c = a1 = 0;
		
		//处理输入的第一个数(若为浮点数将其转换为整数),用s1保存整数部分,a1保存指数部分
        for(int i = 0; str1[i] != '\0'; i++)
		{
            if(str1[i] == '-')							//若遇到负号
                flag = 1;								//flag = 1(负数) flag = 0(正数)

            else if(str1[i] == '.')						//若遇到小数点
                c = 1;									//c = 1

            else if(str1[i] == 'e' || str1[i] == 'E')	//若遇到 e|E ,表明数值部分处理完毕,直接处理指数
			{
                sscanf(str1 + i + 1,"%d",&b);			//将 e|E 后面的指数部分加上a1
                a1 += b;
                break;
            }
            else
			{
                s1 = s1 * 10 + str1[i] - '0';			//将数值部分保存到s1
                a1 -= c;								//在遇到小数点之前,指数a1是不变动的(c=0),在遇到小数点之后,指数开始减少(c=1)
            }											//指数减少的原因(将小数转换为整数,小数点右移,指数减一)
        }//for end

		//如果flag = 1(表示s1是负数)
        if(flag)
			s1 =- s1;									//s1设置为其相反数

        flag = b = c = a2 = 0;							//清零一些标识符

		//处理输入的第二个数(若为浮点数将其转换为整数),用s2保存整数部分,a2保存指数部分
        for(int i = 0; str2[i] != '\0'; i++)
		{
            if(str2[i] == '-')							//若遇到负号
                flag = 1;								//flag = 1(负数) flag = 0(正数)

            else if(str2[i] == '.')						//若遇到小数点
                c = 1;									//c = 1

            else if(str2[i] == 'e' || str2[i] == 'E')	//若遇到 e|E ,表明数值部分处理完毕,直接处理指数
			{
                sscanf(str2 + i + 1,"%d",&b);			//将 e|E 后面的指数部分加上a2
                a2 += b;
                break;
            }
            else
			{
                s2 = s2 * 10 + str2[i] - '0';			//将数值部分保存到s2
                a2 -= c;								//在遇到小数点之前,指数a2是不变动的(c=0),在遇到小数点之后,指数开始减少(c=1)
            }											//指数减少的原因(将小数转换为整数,小数点右移,指数减一)
        }//for end

		//如果flag = 1(表示s2是负数)
        if(flag)
			s2 =- s2;									//s2设置为其相反数
        
		//下面操作可以理解为对阶(大阶对小阶)
		if(a1 < a2)										//如果a1的阶数(指数)大于a2
            for( ; a1 < a2; a2--)
                s2 *= 10;								//s2右移,指数减一

        else if(a1 > a2)								//如果a1的阶数大于a2
            for(; a1 > a2; a1--)						
                s1 *= 10;								//s1右移,指数减一

		//注:对阶后,阶数是相等的
		//a:保存和数的阶数
		//s:保存和数
        a = a1;
		s = s1 + s2;

		//case1: 如果和数为0,直接输出
        if(!s){
            printf("0\n");
            continue;
        }

		//case2: 如果阶数小于0 && 和数是10的倍数, 和数左移一位, 直至阶数为0
        while(a < 0 && s % 10 == 0){
            s /= 10;
            a++;
        }

		//如果阶数大于等于0
        if(a >= 0){
            
			//输出整数部分
			printf("%lld",s);

			//再输出后置的0, 指数a, 代表了0的个数
            for(int i = 0; i < a; i++)
                printf("0");

            printf("\n");
            continue;
        }

		//flag = 0代表其为正数
        flag = 0;

		//若和数小于0
        if(s < 0){
            s =- s;			//将其转换为其相反数
            flag = 1;		//flag = 1代表其为负数
        }

        ans = 1;w = 0;
        while(ans <= s){
            ans *= 10;
            w++;
        }

        if(ans > 1){
            ans /= 10;
			w--;
        }

		//若其为负数,先输出符号
        if(flag)
            printf("-");

		//再输出整数部分
        printf("%lld",s / ans);

		//若ans>1,再输出小数部分
        if(ans > 1)
		{
			//先输出小数点
			printf(".");

			//再输出小数部分
			char str[100];
			sprintf(str, "%d", s);
            
			for (int i = 1; i < strlen(str); i++)
			{
				printf("%c", str[i]);
			}
		}

		//最后输出e 和 指数部分
        printf("e%d\n",a + w);
    }
    return 0;
}

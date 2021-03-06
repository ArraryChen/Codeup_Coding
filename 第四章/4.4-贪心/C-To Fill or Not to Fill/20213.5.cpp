#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;

//加油站
struct station{	
	double price;	//油价
	double dis;		//距离起点的距离
}st[maxn];

bool cmp(station a, station b){
	return a.dis < b.dis;
}

int main(){

	//n:加油站个数
	int n;
	//Cmax:油箱容量
	//D:起点到终点距离
	//Davg:每单元油能行驶的距离
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);

	//循环输入加油站的信息
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	}

	//设置最后一个站点为终点(编号为n)
	st[n].price = 0;
	st[n].dis = D;

	//将加油站按距离的远近来排序
	sort( st, st + n, cmp );

	//如果起点不设加油站,则汽车无法启动,因为起始油量为零
	if ( st[0].dis != 0 )
	{
		printf("The maximum travel distance = 0.00\n");
	}

	//若起始设定了加油站
	else
	{
		//now:表明当前所在的加油站编号
		int now = 0;

		//ans:从起点到终点所需花费的油价
		//nowTank:当前汽车油量
		//MAX:当汽车满油时,能行驶的距离
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;

		//汽车未到终点(编号为n)时,继续遍历
		while ( now < n )
		{
			//k:下一个候选的站点编号
			//这个编号要么是比当前油价最小的站点,或者是所能够选的站点中,油价最小的站点
			int k = -1;

			//priceMin:下一个候选加油站的油价
			double priceMin = INF;
			//遍历找到下一个加油站(这个加油站要在可行的范围内)
			for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				//找到最小加油站的油价
				if ( st[i].price < priceMin )
				{
					priceMin = st[i].price;
					k = i;

					//若找到加油站的油价比当前加油站的油价小,退出查找
					if ( priceMin < st[now].price )
					{
						break;
					}
				}
			}
			//若未找到下一个加油站
			if ( k == -1 ) break;

			//need:所需要的油价
			double need = (st[k].dis - st[now].dis) / Davg;
			
			//若下个站点的油价比当前油价小
			if ( priceMin < st[now].price )
			{
				if (nowTank < need)
				{
					ans += ( need - nowTank ) * st[now].price;
					nowTank = 0;
				}
				else
				{
					nowTank -= need;
				}
			}
			//若当前油价要小些
			else
			{
				ans += (Cmax - nowTank) * st[now].price;
				nowTank = Cmax - need;
			}
			now = k;
		}
		//能到达终点
		if ( now == n ) printf("%.2f\n", ans);
		//未能到达终点
		else printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
	}

	system("pause");
	return 0;
}


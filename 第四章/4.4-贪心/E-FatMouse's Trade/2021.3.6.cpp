#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 1010;

struct warehouse{
	
	double java_bean;	//JavaBean
	double cat_food;	//CatFood
	double weight;		//每一个单元的CatFood能换取多少JavaBean //可以理解为单价

}ware_houses[maxn];

//按照每一个单元的CatFood能换取多少的JavaBean递减次序排序
//(目的是为了使得每个单元的CatFood能换取更多的JavaBean)
bool cmp(warehouse a, warehouse b){

	return a.weight > b.weight;

}

int main(){

	//M: the number of CatFood
	//N: the number of JavaBean
	int M, N;
	while ( scanf("%d %d", &M, &N) != EOF )
	{
		if ( M == -1 || N == -1 ) break;

		//循环输入
		for (int i = 0; i < N; i++)
		{
			scanf("%lf %lf", &ware_houses[i].java_bean, &ware_houses[i].cat_food);

			ware_houses[i].weight = ware_houses[i].java_bean / ware_houses[i].cat_food;
		}

		//排序
		sort(ware_houses, ware_houses + N, cmp);

		//max: the maximum amount of JavaBeans FatMouse can obtain.
		double max = 0;

		//遍历每个wareHouse
		for (int i = 0; i < N; i++)
		{
			//如果当前的CatFood,足以满足the room里面所需的CatFood,那就拿出其所需的CatFood兑换
			if ( M >= ware_houses[i].cat_food )
			{
				M -= ware_houses[i].cat_food;
				max += ware_houses[i].java_bean;
			}

			//所有当前的CatFood不足以满足the room里面所需的CatFood,那就拿出其拥有的CatFood兑换
			else
			{
				max += M * ware_houses[i].weight;
				M = 0;
			}

			//兑换完毕后判断是否还有CatFood可用于下次兑换
			if ( M == 0 ) break;
		}

		//Output the result
		printf("%.3f\n", max);
	}

	system("pause");
	return 0;
}

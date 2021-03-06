#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 1010;

struct warehouse{
	
	double java_bean;	//JavaBean
	double cat_food;	//CatFood
	double weight;		//ÿһ����Ԫ��CatFood�ܻ�ȡ����JavaBean //�������Ϊ����

}ware_houses[maxn];

//����ÿһ����Ԫ��CatFood�ܻ�ȡ���ٵ�JavaBean�ݼ���������
//(Ŀ����Ϊ��ʹ��ÿ����Ԫ��CatFood�ܻ�ȡ�����JavaBean)
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

		//ѭ������
		for (int i = 0; i < N; i++)
		{
			scanf("%lf %lf", &ware_houses[i].java_bean, &ware_houses[i].cat_food);

			ware_houses[i].weight = ware_houses[i].java_bean / ware_houses[i].cat_food;
		}

		//����
		sort(ware_houses, ware_houses + N, cmp);

		//max: the maximum amount of JavaBeans FatMouse can obtain.
		double max = 0;

		//����ÿ��wareHouse
		for (int i = 0; i < N; i++)
		{
			//�����ǰ��CatFood,��������the room���������CatFood,�Ǿ��ó��������CatFood�һ�
			if ( M >= ware_houses[i].cat_food )
			{
				M -= ware_houses[i].cat_food;
				max += ware_houses[i].java_bean;
			}

			//���е�ǰ��CatFood����������the room���������CatFood,�Ǿ��ó���ӵ�е�CatFood�һ�
			else
			{
				max += M * ware_houses[i].weight;
				M = 0;
			}

			//�һ���Ϻ��ж��Ƿ���CatFood�������´ζһ�
			if ( M == 0 ) break;
		}

		//Output the result
		printf("%.3f\n", max);
	}

	system("pause");
	return 0;
}

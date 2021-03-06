#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;

//����վ
struct station{	
	double price;	//�ͼ�
	double dis;		//�������ľ���
}st[maxn];

bool cmp(station a, station b){
	return a.dis < b.dis;
}

int main(){

	//n:����վ����
	int n;
	//Cmax:��������
	//D:��㵽�յ����
	//Davg:ÿ��Ԫ������ʻ�ľ���
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);

	//ѭ���������վ����Ϣ
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	}

	//�������һ��վ��Ϊ�յ�(���Ϊn)
	st[n].price = 0;
	st[n].dis = D;

	//������վ�������Զ��������
	sort( st, st + n, cmp );

	//�����㲻�����վ,�������޷�����,��Ϊ��ʼ����Ϊ��
	if ( st[0].dis != 0 )
	{
		printf("The maximum travel distance = 0.00\n");
	}

	//����ʼ�趨�˼���վ
	else
	{
		//now:������ǰ���ڵļ���վ���
		int now = 0;

		//ans:����㵽�յ����軨�ѵ��ͼ�
		//nowTank:��ǰ��������
		//MAX:����������ʱ,����ʻ�ľ���
		double ans = 0, nowTank = 0, MAX = Cmax * Davg;

		//����δ���յ�(���Ϊn)ʱ,��������
		while ( now < n )
		{
			//k:��һ����ѡ��վ����
			//������Ҫô�Ǳȵ�ǰ�ͼ���С��վ��,���������ܹ�ѡ��վ����,�ͼ���С��վ��
			int k = -1;

			//priceMin:��һ����ѡ����վ���ͼ�
			double priceMin = INF;
			//�����ҵ���һ������վ(�������վҪ�ڿ��еķ�Χ��)
			for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= MAX; i++)
			{
				//�ҵ���С����վ���ͼ�
				if ( st[i].price < priceMin )
				{
					priceMin = st[i].price;
					k = i;

					//���ҵ�����վ���ͼ۱ȵ�ǰ����վ���ͼ�С,�˳�����
					if ( priceMin < st[now].price )
					{
						break;
					}
				}
			}
			//��δ�ҵ���һ������վ
			if ( k == -1 ) break;

			//need:����Ҫ���ͼ�
			double need = (st[k].dis - st[now].dis) / Davg;
			
			//���¸�վ����ͼ۱ȵ�ǰ�ͼ�С
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
			//����ǰ�ͼ�ҪСЩ
			else
			{
				ans += (Cmax - nowTank) * st[now].price;
				nowTank = Cmax - need;
			}
			now = k;
		}
		//�ܵ����յ�
		if ( now == n ) printf("%.2f\n", ans);
		//δ�ܵ����յ�
		else printf("The maximum travel distance = %.2f\n", st[now].dis + MAX);
	}

	system("pause");
	return 0;
}


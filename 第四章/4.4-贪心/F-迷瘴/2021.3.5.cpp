#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	//C:���Ե�����
	int C;
	while ( scanf("%d", &C) != EOF )
	{
		while ( C-- )
		{
			//n:����ҩˮ����
			//V:����ҩˮ���
			//W:����ҩˮŨ������
			int n, V, W;
			scanf("%d %d %d", &n, &V, &W);

			//drug_conc:����ҩˮŨ��
			vector<int> drug_conc;

			//conc:����ҩˮŨ��
			int conc;
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &conc);
				drug_conc.push_back(conc);
			}

			//����Ũ�ȵ�С����˳������
			sort(drug_conc.begin(), drug_conc.end());

			double now_conc = drug_conc[0];
			int now_vol = V;
			if ( drug_conc[0] > W )
			{
				now_conc = 0;
				now_vol = 0;
			}
			else
			{
				for (int i = 1; i < n; i++)
				{
					if ( (now_conc * now_vol + drug_conc[i] * V) / (now_vol + V) <= W )
					{
						now_conc = (now_conc * now_vol + drug_conc[i] * V) / (now_vol + V);
						now_vol = now_vol + V;
					}
					else break;
				}
			}
			printf("%d %.2lf\n", now_vol, now_conc / 100);
		}
	}
	system("pause");
	return 0;
}

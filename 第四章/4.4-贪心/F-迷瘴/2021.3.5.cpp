#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main(){

	//C:测试的组数
	int C;
	while ( scanf("%d", &C) != EOF )
	{
		while ( C-- )
		{
			//n:万能药水种类
			//V:万能药水体积
			//W:配置药水浓度上限
			int n, V, W;
			scanf("%d %d %d", &n, &V, &W);

			//drug_conc:万能药水浓度
			vector<int> drug_conc;

			//conc:万能药水浓度
			int conc;
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &conc);
				drug_conc.push_back(conc);
			}

			//根据浓度的小到大顺序排序
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

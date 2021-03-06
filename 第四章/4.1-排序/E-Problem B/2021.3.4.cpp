#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int nums[15][15];

bool cmp(int a, int b){
	
	return a > b;

}

int main(){

	int m;
	while ( scanf("%d", &m) != EOF )
	{
		vector<int> ans;
		for (int i = 0; i < m; i++)
		{
			int temp = 0;
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &nums[i][j]);
				temp += nums[i][j];
			}
			ans.push_back(temp);
		}

		//���ÿ�еĺ�
		for (int i = 0; i < m; i++)
		{
			int temp = 0;
			for (int j = 0; j < m; j++)
			{
				temp += nums[j][i];
			}
			ans.push_back(temp);
		}

		//������Խ��ߵĺ�
		int temp_num = 0;
		for (int i = 0; i < m; i++)
		{
			temp_num += nums[i][i];
		}
		ans.push_back(temp_num);

		//����ζԽ��ߵĺ�
		temp_num = 0;
		for (int i = 0; i < m; i++)
		{
			temp_num += nums[m-1-i][i];
		}
		ans.push_back(temp_num);

		sort(ans.begin(), ans.end(), cmp);

		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d", ans[i]);
			if ( i < ans.size() - 1 ) printf(" ");
			else printf("\n");
		}
	}

	system("pause");
	return 0;
}

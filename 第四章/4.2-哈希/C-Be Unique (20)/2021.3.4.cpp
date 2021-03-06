#include<cstdio>
#include<vector>
#include<map>
#include<iostream>

using namespace std;

int main(){

	//n:�����������������
	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//ans:�������������(��ĵı��)������ֵĴ���
		map<int, int> ans;

		//nums:�������������
		vector<int> nums;

		//bet_num:��ʱ����,�������������(��ĵı��)
		int bet_num = 0;

		//ѭ������
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &bet_num);
			nums.push_back(bet_num);

			//�ж�map���Ƿ����ҵ��ñ���,����,���ִ�����һ,�����ʼ������Ϊ1
			if ( ans.find(bet_num) != ans.end() ) ans[bet_num]++;
			else ans[bet_num] = 1;
		}

		//result:�����Ƿ���ʤ��
		bool result = false;

		//�����������ֵ�˳��������
		for (int i = 0; i < nums.size(); i++)
		{
			//�жϵ�ǰ������map�г��ֵĴ����Ƿ�Ϊһ,����,�����������(��ĵı��)
			if ( ans[nums[i]] == 1 )
			{
				printf("%d\n", nums[i]);
				result = true;
				break;
			}
		}
		//���жϲ���ʤ��,���None
		if ( result == false ) printf("None\n");
	}

	system("pause");
	return 0;
}

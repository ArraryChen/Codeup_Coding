#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//m:������
	int m;
	while ( scanf("%d", &m) != EOF )
	{
		while ( m-- )
		{
			//n:�������
			int n;
			scanf("%d", &n);

			//nums:����ϵ��
			vector<int> nums;

			//num:��ʱ����
			int num;

			//ѭ������ϵ��
			for (int i = 0; i <= n; i++)
			{
				scanf("%d", &num);
				nums.push_back(num);
			}

			int x;
			scanf("%d", &x);
		
			//sum:����ʽ��ֵ
			int sum = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				//�������������x
				if ( i == 0 ) 
				{
					sum = nums[0];
					continue;
				}
				//���㱾����Ҫ����x�ĸ���
				int count = 1;
				for (int j = 0; j < i; j++)
				{
					count *= x;
				}
				//���
				sum += nums[i] * count;
			}
			printf("%d\n", sum);
		}
	}

	system("pause");
	return 0;
}

//ע�������Ŀ�����λ�ĺ���

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//n:�����������
	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n < 2 || n >= 100 ) break;

		//num_square:�������������ƽ��
		int num_square = n * n;

		//nums:�����������������ÿһλ
		vector<int> nums;

		//����ȡ������������n��ÿһλ
		while ( num_square )
		{
			int pos = num_square % 10;	//ȡ�����λ
			nums.push_back(pos);		//�����λ����nums

			num_square /= 10;			//��ȥ���λ
		}

		//w:ÿһλ��Ȩֵ(��ʼ��λ,ȨֵΪ1)
		int w = 1;

		//����nums��ÿһλ(��ȥ���λ)
		bool result = false;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			num_square += nums[i] * w;

			w *= 10;

			//�����λ��ʼ�����Ĺ�����,������������ԭ�������������ͬʱ,�˳�ѭ��
			if ( num_square == n )
			{
				result = true;
				break;
			}
		}
		if ( result ) printf("Yes!\n");
		else printf("No!\n");
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	//m:����
	int m;
	while ( scanf("%d", &m) != EOF )
	{
		if ( m == 0 ) break;
		
		//ans:���m������
		vector<int> ans;

		//������������
		long long num1, num2, sum;
		scanf("%lld %lld", &num1, &num2);

		//������֮��
		sum = num1 + num2;

		//ע��:���ַ�ʽ��Ҫ��sum=0������ֳ�����������
		if ( sum == 0 )
		{
			printf("0\n");
			continue;
		}

		//��sum����(����ȡ�෨)
		while ( sum )
		{
			int temp = sum % m;	//�õ�������Ϊm�������ĵ�λ
			sum /= m;			//�ٽ��̼���������������,ֱ��Ϊ0

			ans.push_back(temp);//�ӵ�λ����λ���ans
		}
		//�������������
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			printf("%d", ans[i]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}

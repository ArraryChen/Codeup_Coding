#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	int num;

	//��Ŀ˵����,���������ж���,���Ա����������һ������,������ʣ���19������
	while ( scanf("%d", &num) != EOF )
	{
		int count[11] = { 0 };
		count[num]++;

		//����ʣ���19������
		for (int i = 1; i < 20; i++)
		{
			scanf("%d", &num);

			count[num]++;
		}
	
		//max:����
		//max_count:�������ֵĴ���
		int max = 1, max_count = -1;

		//ѭ���ҵ�����
		for (int i = 1; i < 11; i++)
		{
			if ( count[i] > max_count )
			{
				max = i;
				max_count = count[i];
			}
		}
		printf("%d\n", max);
	}

	system("pause");
	return 0;
}

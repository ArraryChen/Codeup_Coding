#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;

		//num:���������n������
		vector<int> num;

		//temp:��ʱ����,���浱ǰ���������
		int temp;
		
		//ѭ������
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			num.push_back(temp);
		}

		//m:��ʱ����,�������ѯ��������m��
		int m;
		scanf("%d", &m);

		//ѭ������
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &temp);

			//find:�ж�num���Ƿ��и�����temp(Ĭ��û��)
			bool find = false;
			for (int i = 0; i < num.size(); i++)
			{
				if ( num[i] == temp )
				{
					find = true;
					break;
				}
			}
			if ( find == true ) printf("YES\n");
			else printf("NO\n");
		}
 	}

	system("pause");
	return 0;
}

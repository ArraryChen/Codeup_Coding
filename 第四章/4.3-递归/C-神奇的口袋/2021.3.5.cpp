#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

//ans:�������������
vector<int> ans;

int func(int n, int w){
	
	if ( w == 40 ) return 1;									//������40ʱ,������ĿҪ��
	else if ( w > 40 ) return 0;								//��������40ʱ,��������ĿҪ��,����0
	else if ( n == ans.size() ) return 0;						//���Ѿ�����������Ԫ��ʱ,���������ﵽ40,����0
	else return func( n + 1, w + ans[n] ) + func( n + 1, w );	//��δ����������Ԫ��ʱ,���������ﵽ40,�������ַ���ѡ��:ѡ��ǰ��Ʒ & ��ѡ��ǰ��Ʒ

}

int main(){

	//n:���������������
	int n;
	while ( scanf("%d" ,&n) != EOF )
	{
		if ( n == 0 ) break;
		
		//num:��ʱ����,��������������
		int num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			ans.push_back( num );
		}

		//count:��¼�˱��εķ�����
		int count = func( 0, 0 );

		printf("%d\n", count);

		//��ձ������������
		ans.clear();
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

//�������Ϊ:�γ�����,ÿ���γ̶�Ӧѡ�޸ÿγ̵�ѧ����
vector<string> course[3000];

int main(){
	
	//name:��ʱ����,ѧ������
	string name;

	//n:ѧ������
	//k:�γ�����
	int n, k;
	scanf("%d %d", &n, &k);

	//course_num:ѡ�޿γ���
	//course_id:ѡ�޿γ̱��
	int course_num, course_id;

	//ѭ������
	for (int i = 0; i < n; i++)
	{
		cin >> name >> course_num;
		for (int j = 0; j < course_num; j++)
		{
			scanf("%d", &course_id);
			course[course_id].push_back(name);
		}
	}

	//����ÿ���γ�
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, course[i].size());
		
		//��������
		sort(course[i].begin(), course[i].end());

		for ( auto it = course[i].begin(); it != course[i].end(); it++ )
		{
			cout << *it << endl;
		}
	}

	system("pause");
	return 0;
}

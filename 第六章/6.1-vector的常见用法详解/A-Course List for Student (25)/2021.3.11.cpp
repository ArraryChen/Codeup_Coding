//������string����,�����ֳ�ʱ,��������Ϊ cin | cout ��Ե��
//���ù�ϣ����,ÿ��ѧ����ӦΨһ������

#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//����ĸ��Ϊ26������,�������һλ��������Ҫ�ٳ�10,��������Ե��,��Ҫ��1
const int maxn = 26 * 26 * 26 * 10 + 1;

//ans:����ÿ��ѧ��ѡ�޵Ŀγ̱��
vector<int> ans[maxn];

//��ȡѧ����Ӧ��ID��
int getID(char name[]){

	int id = 0;

	for (int i = 0; i < 3; i++)
	{
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');

	return id;
}


int main(){

	//name:����
	char name[5];

	//n:��������ѧ����
	//k:�γ�����
	int n, k;
	scanf("%d %d", &n, &k);

	//course_index:�γ�����
	//course_num:ѡ��ÿγ̵�������
	int course_index, course_num;

	//ѭ������k���γ�,���ÿ���γ�ѡ�޵�ѧ��,���ÿγ̼���ѧ����ѡ���б�
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d", &course_index, &course_num);

		for (int j = 0; j < course_num; j++)
		{
			scanf("%s", name);
			int id = getID(name);
			
			ans[id].push_back(course_index);
		}
	}

	//ѭ������ѧ������,�������Ӧ��Ϣ
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);

		int id = getID(name);
		sort(ans[id].begin(), ans[id].end());

		printf("%s %d", name, ans[id].size());
		for (int j = 0; j < ans[id].size(); j++)
		{
			printf(" %d", ans[id][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
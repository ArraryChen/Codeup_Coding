#include<cstdio>
#include<iostream>

using namespace std;

struct student{

	int id;
	char name[20];	//ע��:�����������Ա��Ժ�������,����Ҫ���ַ��������ʽ����
	char sex[20];
	int age;

}students[30];

int main(){
	int m;
	scanf("%d", &m);
	while (m)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %s %s %d", &students[i].id, students[i].name, students[i].sex, &students[i].age);
		}

		int search_num;
		scanf("%d", &search_num);

		printf("%d %s %s %d\n", students[search_num].id, students[search_num].name, students[search_num].sex, students[search_num].age);

		m--;
	}
	
	system("pause");
	return 0;
}

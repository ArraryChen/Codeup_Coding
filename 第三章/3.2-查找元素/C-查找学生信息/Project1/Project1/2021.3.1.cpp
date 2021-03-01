#include<cstdio>
#include<iostream>

using namespace std;

const int maxn = 1010;

bool visit[maxn] = { false };

struct student{
	char id[10];
	char name[100];
	char sex[20];
	int age;

}students[maxn];

int main(){

	int n;
	while ( scanf("%d", &n) != EOF )
	{
		if ( n == 0 ) break;	
		for (int i = 1; i <= n; i++)
		{
			scanf("%s %s %s %d", students[i].id, students[i].name, students[i].sex, &students[i].age);
			visit[i] = true;
		}

		int m;
		scanf("%d", &m);

		int temp_id;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &temp_id);
			if ( visit[temp_id] == false )
			{
				printf("No Answer!\n");
				continue;
			}
			printf("%s %s %s %d\n", students[temp_id].id, students[temp_id].name, students[temp_id].sex, students[temp_id].age);
		}
	}
	
	system("pause");
	return 0;
}

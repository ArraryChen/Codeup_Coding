#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct student{

	char id[10];
	char name[10];
	int score;

}students[100010];

bool cmp1(student a, student b){

	return strcmp(a.id, b.id) < 0;

}

bool cmp2(student a, student b){

	if ( strcmp(a.name, b.name) != 0 ) return strcmp(a.name, b.name) < 0;
	else return strcmp(a.id, b.id) < 0;
}

bool cmp3(student a, student b){

	if ( a.score != b.score ) return a.score < b.score;
	else return strcmp(a.id, b.id) < 0;

}

int main(){

	int count = 1;

	int n, c;
	while ( scanf("%d %d", &n, &c) != EOF, n )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s %s %d", students[i].id, students[i].name, &students[i].score);
		}

		printf("Case %d:\n", count++);

		if ( c == 1 )  sort(students, students + n, cmp1);
		else if ( c == 2 ) sort(students, students + n, cmp2);
		else if ( c == 3 ) sort(students, students + n, cmp3);

		for (int i = 0; i < n; i++)
		{
			printf("%s %s %d\n", students[i].id, students[i].name, students[i].score);
		}
	}

	system("pause");
	return 0;
}

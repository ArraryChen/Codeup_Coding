#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

struct student{

	char id[30];
	int solve_count;
	int solve_number[20];
	int total_score;

}students[1010];

bool cmp(student a, student b){

	if ( a.total_score != b.total_score ) return a.total_score > b.total_score;
	else return strcmp( a.id, b.id ) < 0;

}

int main(){

	int n;
	while ( scanf("%d", &n) != EOF, n )
	{
		int pass_count = 0;

		int score[20];

		int M, G;
		scanf("%d %d", &M, &G);

		for (int i = 1; i <= M; i++)
		{
			scanf("%d", &score[i]);
		}

		for (int i = 0; i < n; i++)
		{
			scanf("%s %d ", students[i].id, &students[i].solve_count);

			students[i].total_score = 0;
			for (int j = 0; j < students[i].solve_count; j++)
			{
				scanf("%d", &students[i].solve_number[j]);
				students[i].total_score += score[students[i].solve_number[j]];
			}
			if ( students[i].total_score >= G ) pass_count++;
		}

		sort(students, students + n, cmp);

		printf("%d\n", pass_count);

		for (int i = 0; i < n; i++)
		{
			if ( students[i].total_score >= G ) printf("%s %d\n", students[i].id, students[i].total_score);
		}
	}

	system("pause");
	return 0;
}

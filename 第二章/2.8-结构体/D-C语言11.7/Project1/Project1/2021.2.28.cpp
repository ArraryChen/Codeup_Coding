#include<cstdio>
#include<iostream>

using namespace std;

struct student{

	int num;
	char name[10];
	int s1, s2, s3;

}students[5];

int main(){

	for (int i = 0; i < 5; i++)
	{
		scanf("%d %s %d %d %d", &students[i].num, students[i].name, &students[i].s1, &students[i].s2, &students[i].s3);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d %s %d %d %d\n", students[i].num, students[i].name, students[i].s1, students[i].s2, students[i].s3);
	}

	system("pause");
	return 0;
}

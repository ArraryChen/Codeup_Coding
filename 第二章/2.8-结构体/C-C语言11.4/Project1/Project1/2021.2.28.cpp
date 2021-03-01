#include<cstdio>
#include<iostream>

using namespace std;

struct {
    int num;
    char name[10];
    char sex;
    char job;
    union {
        int classNum;
        char position[10];
    }category;
}persons[110];

int main(){

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %s %c %c", &persons[i].num, persons[i].name, &persons[i].sex, &persons[i].job);
		if ( persons[i].job == 's' )
		{
			scanf("%d", &persons[i].category.classNum);
		}
		else if ( persons[i].job == 't' )
		{
			scanf("%s", persons[i].category.position);
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d %s %c %c ", persons[i].num, persons[i].name, persons[i].sex, persons[i].job);
		if ( persons[i].job == 's' ) printf("%d\n", persons[i].category.classNum);
		else if ( persons[i].job == 't' ) printf("%s\n", persons[i].category.position);
	}

	system("pause");
	return 0;
}

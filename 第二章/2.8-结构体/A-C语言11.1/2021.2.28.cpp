#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

struct person {
    char name[20];
    int count;
}leader[3] = {"Li", 0, "Zhang", 0, "Fun", 0};

int main(){

	int n;
	scanf("%d", &n);

	char str[10];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if ( strcmp(str, "Li") == 0 ) leader[0].count++;
		else if( strcmp(str, "Zhang") == 0 ) leader[1].count++;
		else if( strcmp(str, "Fun") == 0 ) leader[2].count++;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%s:%d\n", leader[i].name, leader[i].count);
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int maxn = 20;

int main(){

	char str1[maxn], str2[maxn];

	while ( scanf("%s %s", str1, str2) != EOF )
	{
		int sum = 0, length1 = strlen(str1), length2 = strlen(str2);
		for (int i = 0; i < length1; i++)
		{
			for (int j = 0; j < length2; j++)
			{
				sum += (str1[i] - '0') * (str2[j] - '0');
			}
		}
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 1010;

struct bign{

	int d[maxn];
	int len;
	
	bign(){

		memset(d, 0, sizeof(d));
		len = 0;

	}
}nums[maxn];

bign change(char str[]){

	bign a;
	a.len = strlen(str);

	for (int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] - '0';
	}

	return a;
}

bool cmp(bign a, bign b){

	if ( a.len != b.len ) return a.len < b.len;

	for (int i = a.len - 1; i >= 0; i--)
	{
		if ( a.d[i] != b.d[i] ) return a.d[i] < b.d[i];
	}
}

void print(bign a){

	for (int i = a.len - 1; i >= 0; i--)
	{
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main(){

	int n;
	char num[maxn];
	while ( scanf("%d", &n) != EOF && n > 0 )
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", num);
			nums[i] = change(num);
		}

		sort(nums, nums + n, cmp);

		for (int i = 0; i < n; i++)
		{
			print(nums[i]);
		}
	}

	system("pause");
	return 0;
}

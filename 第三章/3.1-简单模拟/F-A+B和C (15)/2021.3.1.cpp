#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);

	long long num1, num2, num3;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld %lld %lld", &num1, &num2, &num3);
		if ( num1 + num2 > num3 ) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}

	system("pause");
	return 0;
}

#include<cstdio>
#include<iostream>

using namespace std;

int n;

int Fab(int x){

	if (x == 0) return 0;
	else if (x == 1) return 1;
	else return Fab(x-1) + Fab(x-2);

}

int main(){

	while ( scanf("%d", &n) != EOF )
	{
		printf("%d\n", Fab(n));
	}

	system("pause");
	return 0;
}

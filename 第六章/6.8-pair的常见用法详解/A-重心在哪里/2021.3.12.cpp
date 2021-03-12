#include<cstdio>
#include<map>
#include<iostream>

using namespace std;

int main(){

	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		while ( n-- )
		{
			double wx = 0, wy = 0;
			for (int i = 0; i < 3; i++)
			{
				pair<double, double> p;
				scanf("%lf %lf", &p.first, &p.second);

				wx += p.first;
				wy += p.second;
			}
			printf("%.1f %.1f\n", wx / 3, wy / 3);
		}
	}

	system("pause");
	return 0;
}
#include<cstdio>
#include<iostream>

using namespace std;

int main(){

	double n;
	while ( scanf("%lf", &n) != EOF )
	{
		for (int x = 0; x <= 100; x++)
		{
			for (int y = 0; y <= 100; y++)
			{
				for (int z = 100; z >= 0; z--)
				{
					if ( x * 5 + y * 3 + z * (1/3.0) <= n && x + y + z == 100)
					{
						printf("x=%d,y=%d,z=%d\n", x, y, z);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}

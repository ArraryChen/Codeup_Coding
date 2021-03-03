#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

int main(){

	int m;
	scanf("%d", &m);

	char str[30];
	vector<char> words[110];

	int count = 0;

	while ( m )
	{
		scanf("%s", str);
		int i = 0;
		while ( str[i] != '\0' )
		{
			words[count].push_back(str[i]);
			i++;
		}
		count++;

		if ( count < 4 )
		{
			int count_time = 0;
			for (int j = count - 1; j >= 0; j--)
			{
				printf("%d=", count_time + 1);
				for (int k = 0; k < words[j].size(); k++)
				{
					printf("%c", words[j][k]);
				}
				if ( count_time < count - 1 ) printf(" ");
				else printf("\n");

				count_time++;
			}
		}
		else
		{
			int count_time = 0;
			for (int j = count - 1; j >= count - 4; j--)
			{
				printf("%d=", count_time + 1);
				for (int k = 0; k < words[j].size(); k++)
				{
					printf("%c", words[j][k]);
				}
				if ( count_time < 3 ) printf(" ");
				else printf("\n");

				count_time++;
			}
		}

		m--;
	}

	system("pause");
	return 0;
}

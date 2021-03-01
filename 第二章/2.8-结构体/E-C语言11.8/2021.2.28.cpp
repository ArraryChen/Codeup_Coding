#include<cstdio>
#include<iostream>

using namespace std;

struct student{

	int num;
	char name[10];
	int s1, s2, s3;

}students[10];

int main(){

	double avg_s1 = 0, avg_s2 = 0, avg_s3 = 0, max_avg = 0;
	int max_pos = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %s %d %d %d", &students[i].num, students[i].name, &students[i].s1, &students[i].s2, &students[i].s3);
		avg_s1 += students[i].s1;
		avg_s2 += students[i].s2;
		avg_s3 += students[i].s3;

		double temp = ( students[i].s1 + students[i].s2 + students[i].s3 ) / 3.0;
		if ( temp > max_avg ) 
		{
			max_avg = temp;
			max_pos = i;
		}
	}

	avg_s1 /= 10.0;
	avg_s2 /= 10.0;
	avg_s3 /= 10.0;

	printf("%.2f %.2f %.2f\n", avg_s1, avg_s2, avg_s3);
	printf("%d %s %d %d %d", students[max_pos].num ,students[max_pos].name, students[max_pos].s1, students[max_pos].s2, students[max_pos].s3); 


	system("pause");
	return 0;
}

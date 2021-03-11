#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

//可以理解为:课程数组,每个课程对应选修该课程的学生名
vector<string> course[3000];

int main(){
	
	//name:临时变量,学生名字
	string name;

	//n:学生总数
	//k:课程总数
	int n, k;
	scanf("%d %d", &n, &k);

	//course_num:选修课程数
	//course_id:选修课程编号
	int course_num, course_id;

	//循环输入
	for (int i = 0; i < n; i++)
	{
		cin >> name >> course_num;
		for (int j = 0; j < course_num; j++)
		{
			scanf("%d", &course_id);
			course[course_id].push_back(name);
		}
	}

	//遍历每个课程
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, course[i].size());
		
		//进行排序
		sort(course[i].begin(), course[i].end());

		for ( auto it = course[i].begin(); it != course[i].end(); it++ )
		{
			cout << *it << endl;
		}
	}

	system("pause");
	return 0;
}

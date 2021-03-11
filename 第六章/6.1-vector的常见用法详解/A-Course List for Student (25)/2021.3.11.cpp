//若利用string类型,则会出现超时,可能是因为 cin | cout 的缘故
//利用哈希方法,每个学生对应唯一的索引

#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

//将字母视为26进制数,由于最后一位是数字需要再乘10,由于数组缘故,需要加1
const int maxn = 26 * 26 * 26 * 10 + 1;

//ans:保存每个学生选修的课程编号
vector<int> ans[maxn];

//获取学生对应的ID号
int getID(char name[]){

	int id = 0;

	for (int i = 0; i < 3; i++)
	{
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');

	return id;
}


int main(){

	//name:名字
	char name[5];

	//n:待搜索的学生数
	//k:课程总数
	int n, k;
	scanf("%d %d", &n, &k);

	//course_index:课程索引
	//course_num:选秀该课程的总人数
	int course_index, course_num;

	//循环操作k个课程,针对每个课程选修的学生,将该课程加入学生的选修列表
	for (int i = 1; i <= k; i++)
	{
		scanf("%d %d", &course_index, &course_num);

		for (int j = 0; j < course_num; j++)
		{
			scanf("%s", name);
			int id = getID(name);
			
			ans[id].push_back(course_index);
		}
	}

	//循环输入学生名字,并输出相应信息
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);

		int id = getID(name);
		sort(ans[id].begin(), ans[id].end());

		printf("%s %d", name, ans[id].size());
		for (int j = 0; j < ans[id].size(); j++)
		{
			printf(" %d", ans[id][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
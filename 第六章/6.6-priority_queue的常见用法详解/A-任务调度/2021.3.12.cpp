//参考:https://www.jianshu.com/p/48a40bf9ad2c

#include<cstdio>
#include<string>
#include<map>
#include<queue>
#include<iostream>

using namespace std;

struct task{

	string name;	//任务名
	int priority;	//任务优先级

	friend bool operator < (task a, task b){	//设置任务优先级
		if ( a.priority != b.priority )			//优先级不同时
			return a.priority > b.priority;		//priority小的优先级大
		else
			return a.name > b.name;				//priority相同时,字典序小的优先级大
	}

};

//load函数:设置任务优先级并存入priority_queue
void load(string s, priority_queue<task> &pq, map<string, int> &have){

	string word = "";	//单词名
	task t;				//任务结构体,暂存单词及其优先级,便于存入priority_queue

	for (int i = 0; s[i] != '(' ; i++)	//找到本次输入的前序任务
		word += s[i];

	if ( have[word] == 0 )				//在map中寻找,若未能找到它
	{
		t.name = word;					//表明其优先级最高(因为它不属于任何一个任务的后序任务)
		t.priority = 1;					//设置优先级
		have[word] = 1;					//设置map
		pq.push(t);						//存入priority_queue
	}
	s.erase(s.begin(), s.begin() + s.find("(") + 1);	//除去左口号及其前序任务,便于之后处理

										//若map中已经存有word的优先级,则have[word]存的就是word的优先级

	int temp = have[word] + 1;			//将要处理后序任务,理所当然temp保存的是后序任务的优先级 = 前序任务优先级 + 1

	word = "";							//清空word

	for (int i = 0; i < s.size(); i++)	//遍历后序任务
	{
		if ( (s[i] == ',' || s[i] == ')' ) && (word != "NULL" && have[word] == 0) )	//如果遇到逗号或右括号(表明遇到一个task),不为空并且不能在priority中找到
		{
			t.name = word;				//同上
			t.priority = 1;
			have[word] = temp + 1;
			pq.push(t);
			word = "";					//处理完该task,清空word
		}
		else
			word += s[i];				//单词未遍历结束,word += s[i]
	}

}

int main(){

	//n:任务数
	int n;
	while ( scanf("%d", &n) != EOF && n )
	{
		//pq:按优先级顺序(当优先级相同时按字典序)保存每个任务
		//have:保存每个任务及其优先级
		priority_queue<task> pq;
		map<string, int> have;

		//s:输入的前序任务及其后序任务
		string s;

		//循环输入
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			load(s, pq, have);
		}

		//循环输出
		while ( !pq.empty() )
		{
			cout << pq.top().name;

			if ( pq.size() > 1 )
				cout << " ";
			else
				cout << endl;

			pq.pop();
		}
	}

	system("pause");
	return 0;
}

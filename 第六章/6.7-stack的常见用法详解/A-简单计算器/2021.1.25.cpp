////����˼·������׺���ʽת��Ϊ��׺���ʽ���ú����α�����׺���ʽ����
////ͷ�ļ�
//#include<cstdio>
//#include<iostream>
//#include<string>
//#include<stack>
//#include<queue>
//#include<map>
//
//using namespace std;
//
////�ṹ��
//struct node{	//�������ֻ������
//	double num;	//��������
//	char op;	//���������
//	bool flag;	//flag = true:����
//				//flag = false:�����
//};
//
////ȫ�ֱ���
//string str;		//str:��������ı��ʽ
//stack<node> s;	//s:���������
//queue<node> q;	//q:��������
//map<char,int> op;//op:��������������ȼ�
//
//
////����
//void Change(){
//	//����׺���ʽת��Ϊ��׺���ʽ
//	double num;	//num:����
//	node temp;	
//	for (int i = 0; i < str.length(); )
//	{
//		if (str[i] >='0' && str[i] <='9')//������������
//		{
//			temp.flag = true;
//			temp.num = str[i++] - '0';
//			while(i < str.length() && str[i] >= '0' && str[i] <= '9'){
//				temp.num = temp.num * 10 + (str[i] - '0');
//				i++;
//			}
//			q.push(temp);
//		}else//�������ǲ�����
//		{
//			temp.flag = false;
//			while(!s.empty() && op[str[i]] <= op[s.top().op]) {//�Ƚϵ�ǰ���������������ջ������������ȼ�
//				q.push(s.top());
//				s.pop();
//			}
//			temp.op = str[i];
//			s.push(temp);
//			i++;
//		}
//	}
//	while(!s.empty()){//�������������������ջ�в�Ϊ�գ��������ѹ�������
//		q.push(s.top());
//		s.pop();
//	}
//}
//
//double Cal() {//��ʱջ�б���������
//	double temp1,temp2;
//	node cur, temp;
//	while(!q.empty())
//	{
//		cur = q.front();
//		q.pop();
//		if (cur.flag == true)//����������
//		{
//			s.push(cur);
//		}else
//		{//�����������
//			temp2 = s.top().num;//ȡ����������
//			s.pop();
//			temp1 = s.top().num;
//			s.pop();
//
//			temp.flag = true;
//			if (cur.op == '+')
//			{
//				temp.num = temp1 + temp2;
//			}else if (cur.op == '-')
//			{
//				temp.num = temp1 - temp2;
//			}else if (cur.op == '*')
//			{
//				temp.num = temp1 * temp2;
//			}else
//			{
//				temp.num = temp1 / temp2;
//			}
//			s.push(temp);//��������ѹ��ջ��
//		}
//	}
//	return s.top().num;//���ջֻ��һ��Ԫ�ؾ��ǽ��
//}
//
////�������
//int main(){
//
//	op['+'] = op['-'] = 1;
//	op['*'] = op['/'] = 2;
//
//	while(getline(cin,str),str!="0"){
//		if(str=="^Z" || str.length()==0) break;
//
//		for(string::iterator it=str.end()-1; it!=str.begin(); it--){
//			if(*it==' ') str.erase(it);
//		}
//		while(!s.empty()) s.pop();
//		Change();
//		printf("%.2f\n",Cal());
//	}
//
//	system("pause");
//	return 0;
//}
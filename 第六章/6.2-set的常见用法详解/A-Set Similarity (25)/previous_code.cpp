//#include<cstdio>
//#include<set>
//
//using namespace std;
//
//int main(){
//
//	//n:������
//	int n;
//	scanf("%d",&n);
//
//	//������
//	set<int> sets[51];
//
//	//cap:ÿ����������
//	//number:�����е���
//	int cap=0;
//	int number=0;
//	for(int i=1;i<=n;i++){
//		scanf("%d",&cap);
//		for(int j=0;j<cap;j++){
//			scanf("%d",&number);
//			sets[i].insert(number);
//		}
//	}
//
//	//count:����ѯ������������
//	int count=0;
//	scanf("%d",&count);
//
//	//set_num1:����ѯ����1
//	//set_num2:����ѯ����2
//	int set_num1;
//	int set_num2;
//	for(int i=0;i<count;i++){
//		scanf("%d %d",&set_num1,&set_num2);
//
//		double same_count=0;//��ͬԪ��
//		double dis_count=0;	//��ͬԪ��
//							
//		set<int>::iterator it1=sets[set_num1].begin();
//		set<int>::iterator it2=sets[set_num2].begin();
//		for( ; it1!=sets[set_num1].end() && it2!=sets[set_num2].end();){
//			if(*it1==*it2){
//				++same_count;
//				++it1;
//				++it2;
//			}
//			else if(*it1 < *it2){
//				++dis_count;
//				++it1;
//			}
//			else{
//				++dis_count;
//				++it2;
//			}
//		}
//		if(it1!=sets[set_num1].end()){
//			++dis_count;
//			++it1;
//		}
//		if(it2!=sets[set_num2].end()){
//			++dis_count;
//			++it2;
//		}
//		printf("%.1lf%%\n",same_count/(same_count+dis_count)*100.0);	// ��ͬԪ�� / (��ͬԪ��+��ͬԪ��)
//	}
//
//	system("pause");
//	return 0;
//}
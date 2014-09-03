/*模拟n个人参加选举的过程，并输出选举结果：假设候选人有四人，分别用“A”、”B”、”C”、”D”表示，选举时开始计票, 
若输入的不是“A”、”B”、”C”、”D”则视为无效票。选举结束后获取各个候选人的得票数以及无效票的个数，输出结果以添
加候选人的顺序进行顺序输出,最后一行为无效的数量。同时getVoteResult命令为结束命令。

输入为多行形式输入，每一行为一条命令。输入的命令只会是有效命令不会有非法命令，但可能存在非法的投票，上面已经描述了。
添加候选人的命令如下：addCandidate为命令 xx1为候选人
addCandidate xx1
投票的命令如下：vote为命令 xx1为候选人的字符串
vote xx1
统计投票的命令如下：getVoteResult为命令
getVoteResult

输出结果以添加候选人的顺序进行顺序输出,最后一行为无效的数量。

样例输入:
addCandidate xx1
addCandidate xx2
addCandidate xx3
addCandidate xx4
addCandidate xx5
addCandidate xx6
vote xx1
vote xx3
vote xx4
vote xx1
vote xx2
vote xx7
vote xx4
vote xx5
vote xx3
vote xx2
vote xx1
vote xx7
getVoteResult

样例输出:
xx1 3
xx2 2
xx3 2
xx4 2
xx5 1
xx6 0
2
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

typedef map<string,int> Candidate;
int main(void){
	Candidate theMap;
	Candidate :: iterator it;
	string name,tmp;
	int a,cnt = 0;
	while(cin >> tmp && tmp.compare("getVoteResult") != 0){
		if(tmp.compare("addCandidate") == 0){
			a = 1;
		}else if(tmp.compare("vote") == 0){
			a = 2;
		}
		switch(a)
		{
			case 1:
			cin >> name;
			theMap.insert(pair<string,int> (name,0));
			a = 0;
			break;

			case 2:
			cin >> name;
			it = theMap.find(name);
			if(it != theMap.end()){
				it->second++;
			}else
			cnt++;
			break;
		}
	}
	for(it = theMap.begin(); it != theMap.end(); it++){
		cout << it->first << ' ' << it->second <<endl;
	}
	cout << cnt <<endl;
	return 0;
}
/*输入一串数字，找到其中包含的最大递增数。递增数是指相邻的数位从小到大排列的数字。如： 2895345323，递增数有：289，345，23, 那么最大的递减数为345。
输入一串数字，默认这串数字是正确的，即里面不含有字符/空格等情况
输出最大递增数
样例输入:	
123526897215
样例输出:	
2689			*/

#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int max = 0,cnt = 0,flag = 0;
	for(int i = 0; i < s.size(); i++){
		int j = i;
		while(s[j] < s[j+1] && j < s.size() - 1){
			j++;
			cnt++;
		}
		if(max <= cnt){
			max = cnt;
			flag = i;
		}
		cnt = 0;
	}
	string ans = s.substr(flag,max +1);
	cout << ans << endl;
	return 0;
}
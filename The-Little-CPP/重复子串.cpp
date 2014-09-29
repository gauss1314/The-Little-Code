/*输入整数（n是小于9位数的整数），当作字符串处理，
看是否有相同的子串，如1212，相同子串是12，
141516则没有子串（子串长度必须大于等于2）。
若有相同子串则输出1,否则输出0
输入：长度小于9的整数 
输出1或者0				*/

#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	while(cin >> s){
		int cnt = 0,max = 0;
		for(int i = 0; i < s.size(); i++){
			for(int j = i+1; j < s.size(); ){
				if(s[i] == s[j]){
					while(s[i++] == s[j++])
						cnt++;
					if(cnt > max)
						max = cnt;
					cnt = 0;
				}else
					j++;
			}
		}
		if(max > 1){
			cout << 1 << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	return 0;
}
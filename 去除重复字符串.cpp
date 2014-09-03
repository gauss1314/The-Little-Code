/*去除重复字符并排序
运行时间限制：无限制
内容限制：       无限制
输入：              字符串
输出：              去除重复字符并排序的字符串
样例输入：       aabcdefff
样例输出：       abcdef                   */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
	string s;
	while(cin >> s){
		string ans;
		ans = ans + s[0];
		int m = 1,flag = 0;
		for(int i = 1; i < s.size(); i++){
			for(int j = 0; j < m; j++){				//依次将字符s[i]与字符串ans的每个字符比较
				if(ans[j] == s[i]){
					flag = 1;
				}
			}
			if(flag != 1){
				ans += s[i];
				m++;
			}else{
				flag = 0;
			}
		}
		sort(ans.begin(),ans.end());
		cout << ans <<endl;
	}
	return 0;
}
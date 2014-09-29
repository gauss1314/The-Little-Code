/*（2）字符串处理

输入：由数字和字母组成的字符串，例如：333aaabb55ppin

输出：数字后面的连续出现的（2个或多个）相同字符（数字或者字符），删去一个，非数字后面的不要删除，例如，对应输出为：33aabb55pin。

考查点：字符串的简单处理*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	string::iterator it;
	while (cin >> s){
		bool flag = false;
		int cnt = 0;
		for (it = s.begin(); it != s.end();){
			if (it != s.end() && (*it >= '0' && *it <= '9')){
				it++;
				flag = true;
			}
			else if (it == s.end())
				break;
			else
				it++;
			while (it != s.end() && (it + 1) != s.end() && *it == *(it + 1)){
				it++;
				cnt++;
			}
			if (flag == true && cnt >=1){
				if (*it >= '0' && *it <= '9'){
					s.erase(it);
				}
				else{
					s.erase(it);
					flag = false;
				}
				cnt = 0;
			}
		}
		cout << s << endl;
	}
	return 0;
}
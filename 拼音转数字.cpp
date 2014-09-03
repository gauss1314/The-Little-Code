/*输入是一个只包含拼音的字符串，请输出对应的数字序列。转换关系如下：
描述：      拼音        yi  er  san  si  wu  liu  qi  ba  jiu
      阿拉伯数字        1   2   3    4   5    6    7   8   9
输入字符只包含小写字母，所有字符都可以正好匹配

运行时间限制：无限制
内存限制：       无限制
输入：              一行字符串，长度小于1000
输出：              一行字符（数字）串
样例输入：       yiersansi
样例输出：       1234                                           */

#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	while(cin >> s){
		string ans;
		for(int i = 0; i < s.size(); i++){
			switch(s[i])
			{
				case 'y':{
					ans += '1';
					break;
				}
				case 'e':{
					ans += '2';
					break;
				}
				case 's':{
					switch(s[i+1]){
						case 'a':{
							ans += '3';
							i++;
							break;
						}
						default:{
							ans += '4';
						}
					}
				}
				case 'w':{
					ans += '5';
					break;
				}
				case 'l':{
					ans += '6';
					i++;
					break;
				}
				case 'q':{
					ans += '7';
					break;
				}
				case 'b':{
					ans += '8';
					break;
				}
				case 'j':{
					ans += '9';
					i++;
					break;
				}
				default:
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
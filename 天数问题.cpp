/*  （1）天数问题

输入：MM-YYYY，MM为月份，YYYY为年份，例如：08-2014

输出：指定年份和月份的天数。例如，08-2014,对应输出为31。

考查点：字符串的分割、字符串转整型、判断是否闰年。*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void) {
	string s;
	while(cin >> s){
		int y,n;
		y = atoi((s.substr(0,2)).c_str());
		n = atoi((s.substr(3,4)).c_str());
		switch(y){
			case 1 :
			case 3 :
			case 5 :
			case 7 :
			case 8 :
			case 10 :
			case 12 :
			{
				cout << 31 <<endl;
				break;
			}
			case 4 :
			case 6 :
			case 9 :
			case 11 :
			{
				cout << 30 <<endl;
				break;
			}
			case 2 :
			{
				if( (n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0) ){
					cout << 29 <<endl;
				}
				else{
					cout << 28 <<endl;
				}
				break;
			}
			default :
			{
				cout << "ERROR" <<endl;
			}
		}
	}
	return 0;
}
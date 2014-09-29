/*输入整数m【视作分子】,整数n【视作分母】（m<n）,
输出小数形式，若是无穷小数保留小数部分100的长度，
若小数部分循环则写成如下形式 比如1/3=0.（3）*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int LEN = 100;

int m,n;
void calc(int,int);
int main(void){
	while(cin >> m >> n){
		calc(m, n);
	}
	return 0;
}

void calc(int m,int n)
{
	int copym = m,copyn = n;
	int tmpi;
	string tmps;
	int a[LEN],cnti = 0, cntj = 0;
	bool flag = true;
	bool finite = false;
	string str1,str2;
	for(int i = 0; i < LEN; i++){
		a[i] = m/n;
		m = (m % n) * 10;
		if(m == 0){
			finite = true;
			break;
		}
	}
	for(int i = 1; i < LEN && flag && !finite; i++){
		for(int j = 1; j < LEN/2 && flag && !finite; j++){
			if(a[i] == a[i+j]){
				cnti = i;
				cntj = i + j;
				while(a[i] == a[i+j] && flag){
					i++;
					if(i == cntj){
						for(int k = cnti; k< cntj; k++){
							tmpi = a[k];
							tmps = to_string(tmpi);
							str2 += tmps;
						}
						for(int k = 1; k < cnti; k++){
							tmpi = a[k];
							tmps = to_string(tmpi);
							str1 += tmps;
						}
						flag = false;
						break;
					}
				}
			}
		}
	}
	if(finite == false && str1 != ""){
		cout << 0 << '.' << str1 << '(' << str2 << ')' <<endl;
	}else if(finite == false && str1 == ""){
		cout << 0 << '.' << '(' << str2 << ')' << endl;
	}else if(finite == true){
		cout << (float)copym / (float)copyn << endl;
	}
}
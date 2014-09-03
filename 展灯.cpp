/*1，2，3。。。n展灯，同时有n个人，
第1个人将1的倍数的灯拉一下，
第2个人将2的倍数的灯拉一下，
问最后有几展灯是亮的，
初始状态灯是灭的，
输入整数n(n<65536) 
输出亮的灯数*/

#include <iostream>
using namespace std;

int main(void){
	int n;
	while(cin >> n){
		int ans = 0;
		int *a = new int[n];
		for(int i = 0; i< n; i++)
			a[i] = 1;
		for(int ren = 1; ren <= n; ren++){
			for(int deng = 1; deng<= n; deng++){
				if(deng % ren == 0){
					a[deng] = a[deng] * (-1);
				}
			}
		}
		for(int i = 0; i < n; i++){
			if(a[i] == -1)
				ans++;
		}
		delete[] a;
		cout << ans << endl;
	}
	return 0;
}
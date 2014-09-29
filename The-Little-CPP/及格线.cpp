/*10个学生考完期末考试评卷完成后，A老师需要划出及格线，要求如下：
(1) 及格线是10的倍数；
(2) 保证至少有60%的学生及格；
(3) 如果所有的学生都高于60分，则及格线为60分

输入：输入10个整数，取值0~100
输出：输出及格线，10的倍数

输入样例：61 51 49 30 20 10 70 80 90 99
输出样例：50			*/

#include <iostream>
using namespace std;

void bubleSort(int a[],int len);

int main(void){
	int a[10];
	int ans = 0;
	for(int i = 0; i< 10; i++){
		cin >> a[i];
	}
	bubleSort(a,10);
	if(a[0] >= 60){
		ans = 60;
	}else{
		ans = a[4];
		while(ans % 10 != 0){
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

void bubleSort(int a[], int len)
{
	int tmp;
	for(int i = len - 1; i > 0; i--){
		for(int j = 0; j < len; j++){
			if(a[j] > a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}
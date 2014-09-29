/*  描述：将一个整型数组中的各个值进行比较，删除重复的数值，并向前对齐。
	输入：多行，每行一组数据，用“,”隔开，其最大长度小于4096个字符。
	输出：多行，每行对应删除重复后的结果。

	样例输入：3，5，4，5，3
			9，9，10，2，3，10，21，2，10
	样例输出：3，5，4
			9，10，2，3，21                */

#include <iostream>
#include <vector>
using namespace std;

const int MAXSIZE = 4096;
void fun(int a[], int len);

int main(){
	int a[MAXSIZE] = { 0 },i = 0;
	while(!cin.eof()){
		cin >> a[i++];
		if(cin.get() == '\n'){
			break;
		}
	}
	fun(a,i-1);
	return 0;
}

void fun(int a[], int len)
{
	vector<int> ans;
	int *hash = new int[len];
	ans.push_back(a[0]);
	for(int i = 1,j = 0; i < len; ){
		while(a[i] != a[j] && i > j)
			j++;
		if(j == i){
			ans.push_back(a[i]);
			i++;
			j = 0;
		}else{
			i++;
			j = 0;
		}
	}
	for(int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] <<',';
	cout <<ans[ans.size() - 1] <<endl;
}
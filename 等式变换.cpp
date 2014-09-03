/*输入一个正整数X，在下面的等式左边的数字之间添加+号或者-号，使得等式成立。
1 2 3 4 5 6 7 8 9 = X
比如：
12-34+5-67+89 = 5
1+23+4-5+6-7-8-9 = 5
请编写程序，统计满足输入整数的所有整数个数。
输入：       正整数，等式右边的数字
输出：       使该等式成立的个数
样例输入：5
样例输出：21       */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void getSign(int,int[]);
void showAns(int[]);
int calc(char,int,string);

int x = 0,cnt = 0;

int main(void){
	int sign[8] = { 0 };
	while(cin >> x){
		getSign(0,sign);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

void getSign(int index, int sign[])
{
	if(index == 8){
		showAns(sign);
		return ;
	}
	for(int i = 0; i < 3; i++){
		sign[index] = i;
		getSign(index+1,sign);
		sign[index] = 0;
	}
}

void showAns(int sign[])
{
	int sum = 0;
	char op = '+';
	string source[] = {"1","2","3","4","5","6","7","8","9"};
	string number,expression;
	number += source[0];
	expression += source[0];
	for(int i = 0; i < 8; i++){
		if(sign[i] == 0){
			number += source[i+1];
			expression += source[i+1];
		}else if(sign[i] == 1){
			sum = calc(op, sum, number);
			op = '+';
			number.clear();
			number += source[i+1];
			expression += '+';
			expression += source[i+1];
		}else if(sign[i] == 2){
			sum = calc(op, sum, number);
			op = '-';
			number.clear();
			number += source[i+1];
			expression += '-';
			expression += source[i+1];
		}
	}
	sum = calc(op, sum, number);
	if(sum  == x){
		cnt ++;
		expression += " = ";
		expression += 'x';
		cout << expression <<endl;
		expression.clear();
	}
}

int calc(char op, int sum, string number)
{
	if(op == '+'){
		sum += atoi(number.c_str());
	}else if(op == '-'){
		sum -= atoi(number.c_str());
	}return sum;
}
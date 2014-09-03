/*已知2条地铁线路，其中A为环线，B为东西向线路，线路都是双向的。经过的站点名分别如下，
两条线交叉的换乘点用T1、T2表示。编写程序，任意输入两个站点名称，
输出乘坐地铁最少需要经过的车站数量（含输入的起点和终点，换乘站点只计算一次）。
地铁线A（环线）经过车站：A1 A2 A3 A4 A5 A6 A7 A8 A9 T1 A10 A11 A12 A13 T2 A14 A15 A16 A17 A18
地铁线B（直线）经过车站：B1 B2 B3 B4 B5 T1 B6 B7 B8 B9 B10 T2 B11 B12 B13 B14 B15

输入：输入两个不同的站名
输出：输出最少经过的站数,含输入的起点和终点，换乘站点只计算一次

输入样例：A1 A3
输出样例：3			*/

#include <iostream>
#include <string>

using namespace std;

typedef struct MGraph
{
	string str[35];
	int arc[36][36];
	int numVertexes,numEdges;
}MGraph;

void floyd(MGraph &G,int[35][35],int[36][36]);
int findNum(string s);
void printPath(int[35][35],int n1,int n2);

int n1,n2;
int D[36][36];
int P[35][35];

int main(void){
	MGraph G;
	G.numVertexes = 35;
	G.numEdges = 36;
	for(int i = 0; i < G.numVertexes; i++){
		for(int j = 0; j< G.numVertexes; j++){
			if(i == j){
				G.arc[i][j] = 0;
			}else{
				G.arc[i][j] = 65535;
			}
		}
	}
	int a[21] = {1,2,3,4,5,6,7,8,9,34,10,11,12,13,35,14,15,16,17,18,1};
	int b[17] = {19,20,21,22,23,34,24,25,26,27,28,35,29,30,31,32,33};
	for(int i = 0; i < 20; i++){
		G.arc[a[i]][a[i+1]] = 1;
		G.arc[a[i+1]][a[i]] = 1;
	}
	for(int i = 0; i < 16; i++){
		G.arc[b[i]][b[i+1]] = 1;
		G.arc[b[i+1]][b[i]] = 1;
	}
	string s1,s2;
	cin >> s1 >> s2;
	n1 = findNum(s1);
	n2 = findNum(s2);
	int P[35][35];
	floyd(G,P,D);
	printPath(P,n1,n2);
	cout << D[n1][n2] +1 <<endl;
	return 0;
}

void floyd(MGraph &G,int P[35][35],int D[36][36])
{
	for(int i = 0; i < G.numVertexes; i++){
		for(int j = 0; j < G.numVertexes; j++){
			P[i][j] = j;
			D[i][j] = G.arc[i][j];
		}
	}
	for(int k = 0; k < G.numVertexes; k++){
		for(int i = 0; i < G.numVertexes; i++){
			for(int j = 0; j < G.numVertexes; j++){
				if(D[i][j] > D[i][k] + D[k][j]){
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}
}

int findNum(string s)
{
	string ss[35] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10","A11","A12","A13","A14","A15","A16",\
	"A17","A18","B1","B2","B3","B4","B5","B6","B7","B8","B9","B10","B11","B12","B13","B14","B15","T1","T2"};
	for(int i = 0; i < 35; i++){
		if(s == ss[i]){
			return i+1;
		}
	}
}

void printPath(int P[35][35],int n1,int n2)
{
	int k = P[n1][n2];
	while(k != n2){
		k = P[k][n2];
		cout << k << "->";
	}cout << endl;
}
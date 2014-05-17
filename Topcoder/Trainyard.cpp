#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Trainyard {
public:
	int reachableSquares(vector <string>, int);
};

char mapa[11][11];
int n,m;
bool vis[11][11][11];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int a, int b, int f) {
	if (f<0) return;
	if (vis[a][b][f] == 1) return;
	
	vis[a][b][f] = 1;
	for (int i=0; i<4; i++) {
		int px = a + dx[i];
		int py = b + dy[i];

		if (px>=n || py>=m) continue;
		if (px<0 || py<0) continue;
		if (mapa[px][py]=='.') continue;
		
		
		if (((mapa[a][b]=='-' || mapa[a][b]=='+') && (mapa[px][py]=='-' || mapa[px][py]=='+') ) && dy[i]!=0) dfs(px,py,f-1);
		if (((mapa[a][b]=='|' || mapa[a][b]=='+') && (mapa[px][py]=='|' || mapa[px][py]=='+') )&& dx[i]!=0) dfs(px,py,f-1);
		if (mapa[a][b] == 'S') {
			if (dx[i]!=0 && (mapa[px][py]=='|' || mapa[px][py]=='+')) dfs(px,py,f-1);
			if (dy[i]!=0 && (mapa[px][py]=='-' || mapa[px][py]=='+')) dfs(px,py,f-1);
		}
	}
	
	return;
}
		
	
int Trainyard::reachableSquares(vector <string> layout, int fuel) {
	n = layout.size();
	m  = layout[0].length();
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) mapa[i][j] = layout[i][j];
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0;k<=fuel; k++) vis[i][j][k] = 0;

	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (mapa[i][j]=='S') 
		dfs(i,j,fuel);
	
	int res = 0;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
		bool reach = 0;
		for (int k=0; k<=fuel; k++) if (vis[i][j][k]) reach = 1;
		res += reach;
	}
	
	return res;

}


double test0() {
	string t0[] = {
".-....",
"-S---.",
"......"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	Trainyard * obj = new Trainyard();
	clock_t start = clock();
	int my_answer = obj->reachableSquares(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {
"..+-+.",
"..|.|.",
"S-+-+."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	Trainyard * obj = new Trainyard();
	clock_t start = clock();
	int my_answer = obj->reachableSquares(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {
"-....-",
"|....+",
"+-S++|",
"|.|..|",
"..+-++"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 8;
	Trainyard * obj = new Trainyard();
	clock_t start = clock();
	int my_answer = obj->reachableSquares(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {
".|...",
"-+S+|",
".|..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	Trainyard * obj = new Trainyard();
	clock_t start = clock();
	int my_answer = obj->reachableSquares(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

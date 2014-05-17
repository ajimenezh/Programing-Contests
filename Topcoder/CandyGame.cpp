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

class CandyGame {
public:
	int maximumCandy(vector <string>, int);
};

int vis[50];
int n;
bool a[50][50];

void dfs(int p) {
	vis[p]=1;
	for (int i=0; i<n; i++) {
		if (a[p][i] && !vis[i]) dfs(i);
	}
	return ;
}
int CandyGame::maximumCandy(vector <string> graph, int target) {
	n = graph.size();
	for (int i = 0; i<n; i++) vis[i] = -1;
	for (int i=0; i<n; i++) for (int j = 0; j<n; j++) a[i][j] = graph[i][j] == 'Y';
	dfs(target);
	for (int i=0; i<n; i++) if (!vis[i]) return -1;
	
	stack<int> s;
	s.push(target);
	for (int i=0; i<n; i++) vis[i]=-1;
	int count = 1;
	vis[target]=0;
	while (!s.empty()) {
		int p = s.top();
		s.pop();
		if (p!=target) vis[p]=count;
		bool path = false;
		for (int i=0; i<n; i++) {
			if (vis[i]==-1 && a[p][i]) {
				vis[i]=count;
				s.push(i);
				path = true;
			}
		}
		if (!path) count++;
	}
	

	int res = 0;
	for (int i=1; i<count; i++) {
		int k = -1;
		for (int j=0; j<n; j++) if (vis[j]==i) k++;
		if (k!=-1) 
		for (int j=0; j<=k; j++) res+=1<<j;
	}
	
	if (res>2000000000) return -1;
	return res;
				
}


double test0() {
	string t0[] = {"NYN", "YNY", "NYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = {"NYN", "YNY", "NYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"NYYY", "YNNN", "YNNN", "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = {"NYYY", "YNNN", "YNNN", "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
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
double test4() {
	string t0[] = {"NYNNNYN",
 "YNYNYNN",
 "NYNYNNN",
 "NNYNNNN",
 "NYNNNNN",
 "YNNNNNY",
 "NNNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 11;
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
double test5() {
	string t0[] = {"NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNYNYNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNYNYNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNYNYNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNYNYNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNYNYNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNYNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNYNYNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNYNYNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNYNYNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNYNYNNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNYNYNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNYNYNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNYNYNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNYNYNNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNYNYNNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNYNYNNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNYNYNNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNYNYNNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNYNNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNYNYNNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNYNYNNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNYN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNY",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	CandyGame * obj = new CandyGame();
	clock_t start = clock();
	int my_answer = obj->maximumCandy(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

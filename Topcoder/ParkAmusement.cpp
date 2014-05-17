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

class ParkAmusement {
public:
	double getProbability(vector <string>, int, int);
};

double dp[51][51];
int vis[51][51];
vector<string> m;
int n;
int k;

double solve(int a, int b) {
	if (b>k) return 0;
	if (vis[a][b]!=-1) return dp[a][b];
	
	for (int i=0; i<n; i++) {
		if (m[a][i]=='E' && b==k) return 1.0;
		else if (m[a][i]=='E' && b!=k) return 0;
		else if (m[a][i]=='P') return 0;
	}
	
	double res = 0;
	double count = 0.0;

	for (int i=0; i<n; i++) {
		if (m[a][i]=='1') {
			res+=solve(i,b+1);
			count = count + 1.0;
		}
	}
	
	
	dp[a][b]=1.0*res/count;
	vis[a][b]=1;
	
	return dp[a][b];
}
	
double ParkAmusement::getProbability(vector <string> landings, int startLanding, int K) {
	m = landings;
	n = m.size();
	k=K;
	
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) vis[i][j]=-1;
	double possible = 0;
	for (int i=0; i<n; i++) if (m[i][i]!='E' && m[i][i]!='P') possible += solve(i,0);

	
	return 1.0*solve(startLanding,0)/possible;
	
}


double test0() {
	string t0[] = {"E000",
 "1000",
 "1000",
 "1000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ParkAmusement * obj = new ParkAmusement();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.3333333333333333;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"E000",
 "1000",
 "1001",
 "000P"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ParkAmusement * obj = new ParkAmusement();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.6666666666666666;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"01000100",
 "00111000",
 "00001010",
 "000E0000",
 "0000E000",
 "00000P00",
 "000000P0",
 "01000000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 2;
	ParkAmusement * obj = new ParkAmusement();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.14285714285714288;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"0100",
 "0010",
 "0001",
 "000E"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 2;
	ParkAmusement * obj = new ParkAmusement();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"E00",
 "0E0",
 "010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	int p2 = 1;
	ParkAmusement * obj = new ParkAmusement();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

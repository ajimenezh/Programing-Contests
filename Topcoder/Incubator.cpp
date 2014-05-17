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

class Incubator {
public:
	int maxMagicalGirls(vector <string>);
};

int n;
int t[51][51];
long long m[51];
long long p[51];
int dp[51];

long long _or(long long a, long long b) {
	long long c = 0;
	for (int i = 0; i<64; i++) {
		if (((a>>i) & 1) || ((b>>i) & 1)) c += 1LL<<i;
	}
	return c;
}

int count(long long a, long long b) {
	int c = 0;
	for (int i=0; i<64; i++) if ((a>>i) & 1) c++;
	for (int i=0; i<64; i++) if (((a>>i) & 1) && ((b>>i) & 1)) c--;
	
	return c;
}

int Incubator::maxMagicalGirls(vector <string> love) {
	n = love.size();
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) t[i][j] = (love[i][j]=='Y');
	
	for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (!t[i][j]) t[i][j] = (t[i][k] && t[k][j]);
	
	for (int i=0; i<n; i++) {for (int j=0; j<n; j++) cout<<t[i][j]<<" "; cout<<endl;}
	
	for (int i = 0; i<n; i++) {
		m[i] = 0;
		for (int j=0; j<n; j++) m[i] += t[i][j]<<j;
		cout<<m[i]<<endl;
		p[i] = (m[i]<<i) & 1;
	}
	
	
	for (int i=0; i<n; i++) {
		dp[i] = 1;
		long long temp = m[i];
		
		for (int j=0; j<i; j++) {
			long long temp2 = _or(m[j],temp);
			long long temp3 = _or(p[j],1LL<<i);
			int c = count(temp3,temp2);
			if (dp[i]<c) {
				dp[i] = c;
				m[i] = temp2;
				p[i] = temp3;
			}

			if (dp[i]<dp[j]) {
				dp[i] = dp[j];
				m[i] = m[j];
				p[i] = p[j];
			}
		}
		
		cout<<dp[i]<<" "<<m[i]<<endl;
	}
	
	return dp[n-1];
	
	
}


double test0() {
	string t0[] = {"NY","NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"NYN", "NNY", "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"NNYNN","NNYNN","NNNYY","NNNNN","NNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"NNNNN","NYNNN","NYNYN","YNYNN","NNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"NNNNN","NNNNN","NNNNN","NNNNN","NNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"NNYNNNNN","NNNYNNNN","NNNNYNNN","NNYNNNNN","NNNNNYYN","NNNYNNNY","NNNNNNNN","NNNNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {"Y"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Incubator * obj = new Incubator();
	clock_t start = clock();
	int my_answer = obj->maxMagicalGirls(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

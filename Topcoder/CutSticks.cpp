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

class CutSticks {
public:
	double maxKth(vector <int>, int, int);
};

vector<int> v;
int n;
int c, k;

bool check(double l) {
	vector<int> a;
	for (int i=0; i<n; i++) if (v[i]>=l) a.push_back(v[i]);
	
	if (a.size()==0 || a.size()+c < k) return false;
	
	long long res=0;
	for (int i=0; i<a.size(); i++) res += floor(a[i]/l);
	if (res>=k) return true;
	return false;
}

double CutSticks::maxKth(vector <int> sticks, int C, int K) {
	v = sticks;
	n= sticks.size();
	c = C;
	k = K;
	double hi=0;
	for (int i=0; i<n; i++) hi = max(hi, double(v[i]));
	double lo=0;
	double mi;
	while (abs(hi-lo)>0.0000001) {
		mi = lo + (hi-lo)/2.0;
		if (check(mi)) lo = mi;
		else hi = mi;
	}
	
	return hi;
}


double test0() {
	int t0[] = {5, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 1;
	CutSticks * obj = new CutSticks();
	clock_t start = clock();
	double my_answer = obj->maxKth(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 8.0;
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
	int t0[] = {5, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 2;
	CutSticks * obj = new CutSticks();
	clock_t start = clock();
	double my_answer = obj->maxKth(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 5.0;
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
	int t0[] = {5, 8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 3;
	CutSticks * obj = new CutSticks();
	clock_t start = clock();
	double my_answer = obj->maxKth(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 4.0;
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
	int t0[] = {1000000000, 1000000000, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	int p2 = 5;
	CutSticks * obj = new CutSticks();
	clock_t start = clock();
	double my_answer = obj->maxKth(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.0;
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
	int t0[] = {76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 789;
	int p2 = 456;
	CutSticks * obj = new CutSticks();
	clock_t start = clock();
	double my_answer = obj->maxKth(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 34.92;
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

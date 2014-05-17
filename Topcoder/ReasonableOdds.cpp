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

class ReasonableOdds {
public:
	string check(int, int, int, int);
};

int n;
double f(double x, double y,int p1) {
	double p;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++) {
			p+=pow(x,i)*pow(1-x,n-i)*pow(y,j)*pow(1-y,n-j);
		}
	}
	return p - p1/100.0;
}

double g(double x, double y,int p1) {
	double p;
	for (int i=0; i<n; i++) {
		p+=pow(x,i)*pow(1-x,n-i)*pow(y,i)*pow(1-y,n-i);
	}
	return p - p1/100.0;
}

double solve(int x, int p) {
	double hi=1.0;
	double lo=0.0;
	
	while (abs(hi-lo)>0.0001) {
		double mi=(hi-lo)/2.0;
		if (f(x,mi,p)>0) hi = mi;
		else lo=mi;
	}
	
	return lo;
}

string ReasonableOdds::check(int p1, int pDraw, int p2, int k) {
	n=k;
	
	double x=0;
	double y=0;
	while (true) {
		x = solve(y,p2);
		y = solve(x,p1);
		if (abs(f(x,y,p1))<0.0001 && abs(f(y,x,p2))<0.0001) break;
	}
	
	if (g(x,y,pDraw) < 0.00001) return "YES";
	return "NO";
}


double test0() {
	int p0 = 0;
	int p1 = 100;
	int p2 = 0;
	int p3 = 1;
	ReasonableOdds * obj = new ReasonableOdds();
	clock_t start = clock();
	string my_answer = obj->check(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 50;
	int p1 = 0;
	int p2 = 50;
	int p3 = 1;
	ReasonableOdds * obj = new ReasonableOdds();
	clock_t start = clock();
	string my_answer = obj->check(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 30;
	int p1 = 0;
	int p2 = 70;
	int p3 = 5;
	ReasonableOdds * obj = new ReasonableOdds();
	clock_t start = clock();
	string my_answer = obj->check(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 30;
	int p1 = 10;
	int p2 = 60;
	int p3 = 2;
	ReasonableOdds * obj = new ReasonableOdds();
	clock_t start = clock();
	string my_answer = obj->check(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 30;
	int p1 = 40;
	int p2 = 30;
	int p3 = 2;
	ReasonableOdds * obj = new ReasonableOdds();
	clock_t start = clock();
	string my_answer = obj->check(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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

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

class PrimeSoccer {
public:
	double getProbability(int, int);
};

double fastpow(double x, int a) {
	if (a==0) return 1.0;
	double temp = fastpow(x,a/2);
	if (a%2==0) return temp*temp;
	return x*temp*temp;
}

double PrimeSoccer::getProbability(int skillOfTeamA, int skillOfTeamB) {
	double p1=0, p2 = 0, p12 = 0;
	
	int p[] = {2,3,5,7,11,13,17};
	int n = 18;
	long long c[19][19];
	c[0][0] = 1;
	for (int i=1; i<19; i++) {
		c[i][0] = 1;
		for (int j=1; j<i; j++) {
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
		c[i][i] = 1;
	}
	
	double q1 = 1.0*skillOfTeamA/100.0;
	double q2 = 1.0*skillOfTeamB/100.0;
	
	
	for (int i = 0; i<7; i++) {
		p1 += fastpow(q1,p[i])*fastpow(1.0-q1,n-p[i])*c[n][p[i]];
	}
	for (int i = 0; i<7; i++) {
		double temp = fastpow(q2,p[i])*fastpow(1.0-q2,n-p[i])*c[n][p[i]];
		p2 += temp;
		p12 += p1*temp;
	}
	
	return p1+p2 - p12;
	
}


double test0() {
	int p0 = 50;
	int p1 = 50;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5265618908306351;
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
	int p0 = 100;
	int p1 = 100;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	int p0 = 12;
	int p1 = 89;
	PrimeSoccer * obj = new PrimeSoccer();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.6772047168840167;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

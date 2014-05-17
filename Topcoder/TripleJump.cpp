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

class TripleJump {
public:
	vector <double> getProbabilities(int, int, int, vector <int>);
};

int x;
int y;
int n;

double integral(int a, int b) {
	
	double temp = 0.0;
	double dx = 1.0/1000.0;
	
	
	for (int i=0; i<1001; i++) for (int j=0; j<1001; j++) {
		double t1 = 1.0*x + 1.0*(1.0*y-x)*(1.0*i/1000.0);
		double t2 = 1.0*x + 1.0*(1.0*y-x)*(1.0*j/1000.0);
		
		
		if ((t1+t2)>1.0*a && (t1+t2)<1.0*b) temp += dx*dx;
	}
	
	return temp;
}

vector <double> TripleJump::getProbabilities(int lower, int upper, int first, vector <int> opponents) {
	
	n = opponents.size();
	vector<double> v(n+1,0.0);
	x = lower + first;
	y = upper + first;
	
	int pos = 0;
	double area = (upper - lower)*(upper - lower);
	
	for (int i=0; i<=n; i++) {
		int t;
		if (i<n) t = opponents[i];
		else t = 3001;
		
		v[i] = integral(pos,t)/area;
		pos = t;
	}
	
	return v;
		
}


double test0() {
	int p0 = 1;
	int p1 = 2;
	int p2 = 1;
	int t3[] = {1,2,3,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.5, 0.5, 0.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 7;
	int p2 = 5;
	int t3[] = {9,9,19,19,19};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.0, 0.0, 0.0, 1.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 1;
	int p1 = 10;
	int p2 = 1;
	int t3[] = {5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.9753086419753086, 0.024691358024691357 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 1;
	int p1 = 10;
	int p2 = 5;
	int t3[] = {1,2,3,5,10,11,12,19};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	TripleJump * obj = new TripleJump();
	clock_t start = clock();
	vector <double> my_answer = obj->getProbabilities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t4[] = {0.22222222222222227, 0.6234567901234567, 0.05555555555555558, 0.043209876543209846, 0.05555555555555558, 0.0, 0.0, 0.0, 0.0 };
	vector <double> p4(t4, t4+sizeof(t4)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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

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

class CatchTheMice {
public:
	double largestCage(vector <int>, vector <int>, vector <int>, vector <int>);
};

int n;
vector<int> xp,yp,xv,yv;

double dist(double t) {
	double max_x = -10000;
	double max_y = -10000;
	double min_x = 100000;
	double min_y = 100000;
	
	for (int i=0; i<n; i++) {
		double x = xp[i]*1.0 + t*xv[i]*1.0;
		double y = yp[i]*1.0 + t*yv[i]*1.0;
	
		
		min_x = min(x,min_x);
		min_y = min(y,min_y);
		max_x = max(max_x,x);
		max_y = max(max_y,y);
	}
	
	return max(max_x-min_x,max_y-min_y);
}

double CatchTheMice::largestCage(vector <int> _xp, vector <int> _yp, vector <int> _xv, vector <int> _yv) {
	n = _xp.size();
	
	xp = _xp; yp = _yp; 
	xv = _xv; yv = _yv;
	
	double lo = 0.0;
	double hi = 5000;
	
	for (int i=0; i<100; i++) {
		double left = (2*lo + hi)/3.0;
		double right = (lo + 2*hi)/3.0;
		
		if (dist(left) > dist(right)) lo = left;
		else hi = right;
	}
	
	return dist(lo);
}


double test0() {
	int t0[] = {0,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10,-10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 10.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {0,10,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,-6,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {4,5,-4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {50,10,30,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-10,30,20,40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-5,-10,-15,-5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {40,-10,-1,-50};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 40.526315789473685;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {0,10,10,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,10,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,0,-1,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,1,0,-1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 10.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int t0[] = {13,50,100,40,-100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {20,20,-150,-40,63};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,50,41,-41,-79};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1,3,-1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 212.78688524590163;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {0,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 10.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {-49,-463,-212,-204,-557,-67,-374,-335,-590,-4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {352,491,280,355,129,78,404,597,553,445};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-82,57,-23,-32,89,-72,27,17,100,-94};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-9,-58,9,-14,56,75,-32,-98,-81,-43};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	CatchTheMice * obj = new CatchTheMice();
	clock_t start = clock();
	double my_answer = obj->largestCage(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 25.467532467532468;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

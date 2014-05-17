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

class ColorfulDecoration {
public:
	int getMaximum(vector <int>, vector <int>, vector <int>, vector <int>);
};

int x[110];
int y[110];
bool graph[110][110];
int dist[110][110];

int ColorfulDecoration::getMaximum(vector <int> xa, vector <int> ya, vector <int> xb, vector <int> yb) {
	
	int hi = 2000000100;
	int lo = 0;
	int n = xa.size();
	
	for (int i=0; i<n; i++) {
		x[2*i] = xa[i];
		x[2*i + 1] = xb[i];
		y[2*i] = ya[i];
		y[2*i + 1] = yb[i];
	}
	
	for (int i=0; i<2*n; i++) for (int j=0; j<2*n; j++) dist[i][j] = min(abs(x[i]-x[j]),abs(y[i]-y[j])); 
		
	
	while (hi-lo>1) {
		int mi = lo + (lo - hi)/2;
		
		for (int i=0; i<2*n; i++) for (int j=0; j<2*n; j++) graph[i][j] = 0;
		for (int i=0; i<2*n; i++) graph[i][i] = true;
		
		for (int i=0; i<2*n; i++) for (int j=0; j<2*n; j++) if (i/2!=j/2 && dist[i][j]<mi) graph[i^1][j] = graph[j^1][i] = true;
		
		for (int k=0; k<2*n; k++) for (int i=0; i<2*n; i++) for (int j=0; j<2*n; j++) {
			graph[i][j] = graph[i][k] && graph[k][j];
		}
		
		int pos = true;
		for (int i=0; i<n; i++) if (graph[2*i][2*i + 1] && graph[2*i+1][2*i]) pos = false;
		
		if (pos) lo = mi; else hi = mi;
	}
	
	return hi;
		
}


double test0() {
	int t0[] = { 10,  0,  7 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {  0, 19,  6 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 20, 10, 25 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 20, 35, 25 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 19;
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
	int t0[] = { 464, 20 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 464, 10 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 464,  3 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 464, 16 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 461;
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
	int t0[] = { 0, 0, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0, 0, 1, 1 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 1, 1, 0, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 1, 1, 0, 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
	int t0[] = { 0, 3, 0, 5, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 1, 6, 0, 8, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 6, 1, 7, 4, 7 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 5, 9, 2, 8, 9 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
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
	int t0[] = { 1000000000, 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0, 1000000000 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 0, 1000000000 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 1000000000 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	ColorfulDecoration * obj = new ColorfulDecoration();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1000000000;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

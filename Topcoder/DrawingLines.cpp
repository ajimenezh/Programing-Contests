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

class DrawingLines {
public:
	double countLineCrossings(int, vector <int>, vector <int>);
};

double DrawingLines::countLineCrossings(int n, vector <int> startDot, vector <int> endDot) {
	
	int m = startDot.size();
	
	double tot = 0;
	
	for (int i=0; i<m; i++) {
		for (int j=i+1; j<n; j++) {
			if (startDot[i]>startDot[j] && endDot[i]<startDot[j]) tot++;
			else if  (startDot[i]<startDot[j] && endDot[i]>startDot[j]) tot++;
		}
	}
	
	tot += 1.0*(n-m)*(n-m-1)/4;
	
	vector<bool> visUp(n,0);
	vector<bool> visDown(n,0);
	for (int i=0; i<m; i++) visUp[startDot[i]] = 1;
	for (int i=0; i<m; i++) visDown[endDot[i]] = 1;
	
	vector<int> leftUp(m,0);
	vector<int> leftDown(m,0);
	vector<int> rightUp(m,0);
	vector<int> rightDown(m,0);
	
	for (int i=0; i<n; i++) {
		if (!visUp[i]) {
			for (int j=0; j<m; j++) {
				if (i<startDot[j]) leftUp[j]++;
				else rightUp[j]++;
			}
		}
		if (!visDown[i]) {
			for (int j=0; j<m; j++) {
				if (i<endDot[j]) leftDown[j]++;
				else rightDown[j]++;
			}
		}
	}
	
	for (int i=0; i<m; i++) {
		tot += 1.0*leftUp[i]*rightDown[i]/(leftDown[i] + rightDown[i]);
		tot += 1.0*rightUp[i]*leftDown[i]/(leftDown[i] + rightDown[i]);
	}
	
	return tot;
}


double test0() {
	int p0 = 3;
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.5;
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
	int p0 = 5;
	int t1[] = {1,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 5.5;
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
	int p0 = 4;
	int t1[] = {4,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5;
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
	int p0 = 8;
	int t1[] = {1,4,3,6,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,3,2,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	DrawingLines * obj = new DrawingLines();
	clock_t start = clock();
	double my_answer = obj->countLineCrossings(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 7.5;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

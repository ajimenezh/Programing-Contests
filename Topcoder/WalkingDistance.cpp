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

class WalkingDistance {
public:
	double getLongestShortest(vector <int>, vector <int>, vector <string>);
};

double d[51][51];
int x[51];
int y[51];
int n;

double dist(int i,int j) {
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

double WalkingDistance::getLongestShortest(vector <int> _x, vector <int> _y, vector <string> streets) {
	n = _x.size();
	
	for (int i=0; i<n; i++) {
		x[i] = _x[i];
		y[i] = _y[i];
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		d[i][j] = streets[i][j]=='Y' ? dist(i,j) : 10000000.0;
	}
	
	for (int i=0; i<n; i++) d[i][i] = 0.0;
	
	for (int k=0; k<n; k++) 
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++) 
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	double res = 0.0;
	for (int i=0; i<n; i++) for (int j=0; i<n; i++) 
		res = max(res,d[i][j]);
	
	
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++) {
			
			if (i==j) continue;
			if (streets[i][j]=='N') continue;
			
			for (int p=0; p<n; p++) 
				for (int r=0; r<n; r++) {
					
					if (streets[p][r]=='N') continue;
					if ((p==i && r==j) || (p==j && i==r)) continue;
					
					res = max(res, min(dist(i,j) + dist(r,p) + d[i][p] + d[r][j],dist(i,j) + dist(r,p) + d[i][r] + d[j][p])/2.0);
				

			}
	}
	
	return res;
}


double test0() {
	int t0[] = {0,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = {"NY","YN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WalkingDistance * obj = new WalkingDistance();
	clock_t start = clock();
	double my_answer = obj->getLongestShortest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.4142135623730951;
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
	int t0[] = {0,2,2,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,2,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = {"NNYY","NNYY","YYNN","YYNN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WalkingDistance * obj = new WalkingDistance();
	clock_t start = clock();
	double my_answer = obj->getLongestShortest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 4.82842712474619;
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
	int t0[] = {0,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = {"NYY","YNY", "YYN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WalkingDistance * obj = new WalkingDistance();
	clock_t start = clock();
	double my_answer = obj->getLongestShortest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.7071067811865475;
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
	int t0[] = {0, 1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	string t2[] = {"NYY", "YNN", "YNN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WalkingDistance * obj = new WalkingDistance();
	clock_t start = clock();
	double my_answer = obj->getLongestShortest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 4.242640687119286;
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

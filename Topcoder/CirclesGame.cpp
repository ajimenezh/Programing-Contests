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

class CirclesGame {
public:
	string whoCanWin(vector <int>, vector <int>, vector <int>);
};

vector<int> v;
bool vis[51];
int n;

int sqr(int x) {return x*x;}

string CirclesGame::whoCanWin(vector <int> x, vector <int> y, vector <int> r) {
	n = x.size();
	for (int i=0; i<n; i++) vis[i] = 0;
	for (int i=0; i<n; i++) if (!vis[i]){
		int num = 1;
		for (int j=0; j<n; j++) if (j!=i) {
			int d = sqr(x[i] - x[j]) + sqr(y[i]-y[j]);
			if (d+r[i]<r[j]) {
				num++;
				vis[j] = 1;
			}
		}
		v.push_back(num);
	}
	
	int m = v[0];
	
	for (int i=1; i<v.size(); i++) m ^= v[i];
	
	return m%2!=0 ? "Alice" : "Bob";
	
	
	
}


double test0() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 0, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {0, 0, 0, 10, 10, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 0, 0, 0, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 3, 1, 2, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {10,20,30,40,50,60,70,80};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8,7,6,5,4,3,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,2,2,2,2,2,2,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {0, 3, 6, 9, 12, -4747, -4777};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-5858, -5858, -5858, -5858, -5858, 777, 777};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {58, 1, 1, 1, 1, 44, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {5202, 5699, -7433, 5068, -9483, -684, -6593, 5108, -7813, 6823, 3267, -8222, -8547, 2878, 2413, 8557, 5149, 5073, -8638, -6108, 8097};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8728, -7407, 4338, -8414, 7652, -3705, -984, 5976, -9180, -9119, 9301, 2398, 7915, 6205, 7665, 717, -9884, 11, -8579, -6903, -746};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4196, 9303, 7152, 5875, 2943, 788, 502, 416, 1958, 3174, 182, 1256, 1147, 444, 979, 65, 1040, 1233, 438, 175, 1140};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CirclesGame * obj = new CirclesGame();
	clock_t start = clock();
	string my_answer = obj->whoCanWin(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

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
#define INF 1000000;
class GetToTheTop {
public:
	int collectSweets(int, vector <int>, vector <int>, vector <int>, vector <int>);
};

int dp[52][2];
vector<pair<pair<int,int>,pair<int,int> > > v;
int k;
int n;

double dist(int x1,int y1,int x2,int y2) {return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));}
int solve(int i, int pos) {
	if (i>=n) return 0;
	if (dp[i][pos]!=-1) return dp[i][pos];
	
	int res=0;
	if (pos==0) res = solve(i,pos+1) + v[i].second.first;
	int x,y;
	y=v[i].first.first;
	x=v[i].first.second;
	if (pos==1) x+=v[i].second.second;
	
	for (int j=i+1; j<n; j++) {
		if (dist(x,y,v[j].first.second,v[j].first.first)<k) res=max(res,solve(j,0));
	}
	
	dp[i][pos]=res;
	return res;
}
int GetToTheTop::collectSweets(int K, vector <int> sweets, vector <int> x, vector <int> y, vector <int> stairLength) {
	k=K;
	n=x.size();
	
	for (int i=0; i<n; i++) v.push_back(make_pair(make_pair(y[i],x[i]),make_pair(sweets[i],stairLength[i])));
	sort(v.begin(),v.end());
	
	for (int i=0; i<52; i++) for (int j=0; j<2; j++) dp[i][j]=-1;
	
	return solve(0,0);
}


double test0() {
	int p0 = 2;
	int t1[] = {1, 2, 3, 4, 3, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 1, 4, 5, 5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 3, 4, 1, 2, 3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {2, 1, 1, 2, 1, 1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 13;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 4;
	int t1[] = {2, 8, 7, 4, 1, 4, 7, 5, 11, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 9, 4, 6, 10, 5, 2, 8, 1, 10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 1, 3, 3, 3, 5, 6, 6, 8, 9};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {2, 2, 1, 2, 2, 2, 4, 3, 2, 2};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 47;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 10;
	int t1[] = {1, 3, 5, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 6, 2, 8};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2, 4, 1, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {4, 1, 7, 4};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 16;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 3;
	int t1[] = {80, 20, 15, 13, 10, 7, 8, 9, 1, 4, 3, 15, 14, 19, 22, 12, 6, 15, 10, 30, 1, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 8, 11, 17, 20, 14, 10, 16, 8, 14, 19, 6, 6, 6, 6, 15, 15, 15, 14, 20, 20, 20};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 2, 3, 2, 1, 4, 6, 7, 8, 8, 8, 9, 10, 11, 12, 9, 10, 11, 12, 9, 10, 11};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {2, 2, 2, 2, 2, 2, 3, 2, 3, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 129;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 10;
	int t1[] = {0, 10, 11, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 26, 29, 22, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 83, 88, 22, 5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {11, 1, 23, 15, 8};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 5;
	int t1[] = {2, 0, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 8, 9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {6, 6, 1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {3, 6, 3};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int p0 = 2;
	int t1[] = {2, 9, 9, 1, 9, 9, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {10, 8, 6, 6, 8, 7, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {6, 7, 5, 4, 5, 2, 5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1, 1, 1, 1, 1, 1, 1};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	GetToTheTop * obj = new GetToTheTop();
	clock_t start = clock();
	int my_answer = obj->collectSweets(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 47;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

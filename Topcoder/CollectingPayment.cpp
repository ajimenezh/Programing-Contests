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

class CollectingPayment {
public:
	double maximumProfit(vector <int>, vector <int>, int, int);
};

double dp[366][51][51];
int er[51];
int mom[51];
int f;
int r;
int n;
map<int,int>  md;
int cost[51][51];

double fastpow(double a, int n) {
	if (n%2==0) {
		double b = fastpow(a,n/2);
		return b*b;
	}
	else return fastpow(a,n-1)*a;
}

double win(int d, double res) {
	int n = 364/7 - d/7;
	
	return fastpow(1.0*r/100.0,n)*res;
}
double solve(int d, int in, int fn) {
	if (d == 364) return cost[in][fn]-f;
	if (dp[d][in][fn]!=-1) return dp[d][in][fn];
	
	double res=0;
	if (md.find(d)!=md.end()) res+=er[md[d]];
	
	if (in!=fn) res += cost[in][fn-1];
	
	double temp;
	if (d%7==0) temp = max(solve(d+1,in,fn+1), solve(d+1,fn+1,fn+1) + win(d,res) - f);
	else temp = solve(d+1,in,fn+1);
	
	dp[d][in][fn] = temp;
	
	return temp;
}
	
double CollectingPayment::maximumProfit(vector <int> earning, vector <int> moment, int fee, int rate) {
	r = rate;
	f = fee;
	n = moment.size();
	for (int i=0; i<n; i++) er[i]=earning[i];
	for (int i=0; i<n; i++) mom[i] = moment[i];
	
	for (int i=0; i<n; i++) md[moment[i]] = i;
	
	for (int i=0; i<366; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) dp[i][j][k] = 0.0;
	
	for (int i=0; i<n; i++) for (int j = i; j<=n; j++) {
		if (i+1==j) cost[i][j]=earning[i];
		else if (i==j) cost[i][j] = 0;
		else cost[i][j] = cost[i][j-1] + earning[j];
	}
	
	return solve(0,0,0);
}


double test0() {
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {120,124,200,202};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 40;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1325.1174146859212;
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
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,122,243,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 40;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1240.733092976253;
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
	int t0[] = {300,290,320,150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,122,243,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 200;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 868.6;
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
	int t0[] = {150};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 50;
	int p3 = 100;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 110.0;
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
	int t0[] = {1000,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {155,365};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 100;
	int p3 = 100;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 17274.90824619758;
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
	int t0[] = {1,346,7,346,345,3,453,5,346,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,7,34,74,163,200,250,352,360};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	int p3 = 0;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 1855.0;
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
	int t0[] = {1,346,7,346,345,3,453,5,346,354,25,23,354,235,235};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,7,34,74,98,154,163,178,200,210,250,279,325,352,360};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 50;
	int p3 = 10;
	CollectingPayment * obj = new CollectingPayment();
	clock_t start = clock();
	double my_answer = obj->maximumProfit(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3693.6800093457805;
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

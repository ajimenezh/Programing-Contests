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

#define INF 10000000;

class CheapestRoute {
public:
	vector <int> routePrice(vector <int>, vector <int>, vector <int>, int);
};

pair<int,int> dp[55][55];
int cost[55];
vector<int> enter;
vector<int> ex;
int tprice;
int n;
int t;

pair<int,int> solve (int o, int t, int c) {
	if (o==t) return make_pair(cost[o],0);
	if (dp[o][c].first!=-1) return dp[o][c];
	
	pair<int,int> temp = make_pair(solve (o+1,t,c).first + cost[o+1], solve (o+1,t,c).second);
	
	for (int i=0; i<t; i++) {
		if (enter[i]==o && cost[ex[i]]!=INF) {
			if (temp.first > solve(ex[i],t,c+1).first + tprice + c)
				temp = make_pair(solve(ex[i],t,c+1).first + tprice + c,solve(ex[i],t,c+1).second + 1);
		}
	}
	
	dp[o][c]=temp;
	return temp;
}
vector <int> CheapestRoute::routePrice(vector <int> cellPrice, vector <int> enterCell, vector <int> exitCell, int teleportPrice) {
	tprice = teleportPrice;
	enter = enterCell;
	ex = exitCell;
	n = cellPrice.size();
	for (int i=0; i<n; i++) {cost[i]=cellPrice[i]; if (cost[i]==-1) cost[i]=INF;
	t = enter.size();
	for (int i=0; i<n; i++) for (int j=0; j<t; j++) dp[i][j]=make_pair(-1,0);
	
	pair<int,int> res = solve(0,n-1,0);
	
	vector<pair<int,int> > sol;
	
	if (res.first == INF ) return sol;
	sol.push_back(res.first);
	sol.push_back(res.second);
	
	return sol;
}


double test0() {
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 1000;
	CheapestRoute * obj = new CheapestRoute();
	clock_t start = clock();
	vector <int> my_answer = obj->routePrice(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
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
	int t0[] = {0,-1,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 1000;
	CheapestRoute * obj = new CheapestRoute();
	clock_t start = clock();
	vector <int> my_answer = obj->routePrice(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {1000, 2 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
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
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	vector <int> p1;
	vector <int> p2;
	int p3 = 100;
	CheapestRoute * obj = new CheapestRoute();
	clock_t start = clock();
	vector <int> my_answer = obj->routePrice(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {5, 2 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
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
	int t0[] = {1,0,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 0;
	CheapestRoute * obj = new CheapestRoute();
	clock_t start = clock();
	vector <int> my_answer = obj->routePrice(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p4;
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
double test4() {
	int t0[] = {4,2,1,0,5,6,0,3,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,4,3,7,5,4,2,5,8,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7,3,5,0,5,4,5,0,8,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 8;
	CheapestRoute * obj = new CheapestRoute();
	clock_t start = clock();
	vector <int> my_answer = obj->routePrice(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {14, 6 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

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

#define mod 1000003LL

class RaceOrdering {
public:
	int countOrders(int, vector <int>, vector <int>);
};

vector<int> edges[31];
vector<int> father[31];
bool vis[31];
bool used[31];

bool dfs(int i) {
	if (vis[i]) return false;
	
	used[i] = 1;
	vis[i] = 1;
	
	bool state = true;
	
	for (int k=0; k<edges[i].size(); k++) {
		state = state && dfs(edges[i][k]);
	}
	
	return state;
}

int dfs2(int i) {
	if (used[i]) return 0;
	
	used[i]=1;
	
	if (edges[i].size()==0) return 1;
	
	int f = 0;
	
	for (int j=0; j<edges[i].size(); i++) {
		f += dfs2(edges[i][j]);
	}
	
	return f;
}

long long c[31][31];

int RaceOrdering::countOrders(int n, vector <int> first, vector <int> second) {
	
	int m = first.size();
	
	c[0][0]=1;
	for (int i=1; i<n; i++) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j=1; j<i; j++) {
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	
	for (int i=0; i<m; i++) {
		edges[first[i]-1].push_back(second[i]-1);
		father[second[i]-1].push_back(first[i]-1);
		vis[first[i]-1] = 1;
		vis[second[i]-1] = 1;

	}
	
	for (int i=0; i<n; i++) vis[i] = !vis[i];

	vector<int> ind;

	for (int i=0; i<n; i++) {
		if (!vis[i] && father[i].size()==0) {
			for (int j=0; j<n; j++) used[j] = 0;
			
			if (!dfs(i)) return 0;
			
			for (int j=0; j<n; j++) used[j] = 0;
			ind.push_back(dfs2(i));
		}
	}
	
	long long res = 1;
	int s = 0;
	for (int i=0; i<ind.size(); i++) {
		for (int k=0; k<ind[i]; k++) {
			for (int j=0; j<=s; j++) 
				res *= (j+1)%mod;
			s++;
		}
	}

	res = res%mod;

	for (int i=0; i<(n-2*m); i++) {

		res = res*(i+1+s)%mod;
	}
	
	return res;
			
}


double test0() {
	int p0 = 3;
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RaceOrdering * obj = new RaceOrdering();
	clock_t start = clock();
	int my_answer = obj->countOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 4;
	int t1[] = {0, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RaceOrdering * obj = new RaceOrdering();
	clock_t start = clock();
	int my_answer = obj->countOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 8;
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
	int p0 = 10;
	int t1[] = {1, 2, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2, 3, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	RaceOrdering * obj = new RaceOrdering();
	clock_t start = clock();
	int my_answer = obj->countOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int p0 = 30;
	vector <int> p1;
	vector <int> p2;
	RaceOrdering * obj = new RaceOrdering();
	clock_t start = clock();
	int my_answer = obj->countOrders(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 90317;
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

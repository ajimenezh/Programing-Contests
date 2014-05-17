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

#define INF 1000000

class ConnectTheCities {
public:
	int minimalRange(int, int, vector <int>);
};

int p[51];
int n;
int range;
int dp[101][51];

int solve(int d, int i) {
	if (d<=0) return 0;
	if (i==n) return INF;
	if (dp[d][i]!=-1) return dp[d][i];
	
	int res = solve(d,i+1);
	int pos = p[i];
	
	if (pos>=d) {
		for (int j=pos; j>=d; j--) {
			
			res = min(res, abs(j-pos) + solve(j - range,i+1));
			
		}
	}
	
	if (pos<d) res = min(res, abs(pos-d) + solve(d - range,i+1));

	
	dp[d][i] = res;
	
	return res;
}

int ConnectTheCities::minimalRange(int distance, int funds, vector <int> position) {
	if (distance == 0) return 0;
	
	n = position.size();
	sort(position.begin(),position.end());
	reverse(position.begin(),position.end());
	for (int i=0; i<n; i++) p[i] = position[i];
	
	int lo = 1;
	int hi = 100;
	
	for (int k=1; k<100; k++) {
		range = lo + ;
		for (int i=0; i<101; i++) for (int j=0; j<n; j++) dp[i][j] = -1;
		if (solve(distance-range,0)<=funds) return range;
		cout<<solve(distance,0)<<endl;
	}
	
	return 100;
}


double test0() {
	int p0 = 10;
	int p1 = 5;
	int t2[] = { 3, 7, 9 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
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
	int p0 = 20;
	int p1 = 100;
	int t2[] = { 0, 0, 0, 0 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 63;
	int p1 = 19;
	int t2[] = { 34, 48, 19, 61, 24 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ConnectTheCities * obj = new ConnectTheCities();
	clock_t start = clock();
	int my_answer = obj->minimalRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 12;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

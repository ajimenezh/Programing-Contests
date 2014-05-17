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

#define INF 1000;

class TheSoccerDivTwo {
public:
	int find(vector <int>);
};

int TheSoccerDivTwo::find(vector <int> points) {
	int dp[51][50][2];
	int n=points.size();
	
	for(int j=0; j<50; j++) for (int k=0; k<2; k++) {
		if (k==0 && j==0) dp[n][j][k] = 0;
		else dp[n][j][k] = INF;
	}
	
	int pos=1;
	points[0]+=3;
	
	
	for (int i=0; i<n; i++) if (points[i]>points[0]) pos++;
	
	int c;
	
	for (int i=n-1; i>0; i--) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<2; k++) {
				int temp=INF;
				
				//team i wins
				c=0;
				if (points[i]<points[0] && (points[i]+3)>points[0]) c=1;
				if (j<n-1 && i<n) temp=min(temp, c+dp[n+1][j+1][k]);
				
				//team i lose
				if (j>=1) temp = min(temp, dp[n+1][j-1][k]);
				
				//team i draw
				if (points[i]<points[0] && points[i]+1>points[0]) c=1;
				temp=min(temp, c+dp[n+1][j][(k+1)%2]);
				
				dp[i][j][k]=temp;
			}
		}
	}
	
	return pos + dp[0][1][0];			
				
}


double test0() {
	int t0[] = {4, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheSoccerDivTwo * obj = new TheSoccerDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {4, 7, 7, 7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheSoccerDivTwo * obj = new TheSoccerDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {5, 9, 11, 9, 10, 9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheSoccerDivTwo * obj = new TheSoccerDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {2, 1, 3, 7, 6, 5, 3, 4, 2, 6, 5, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	TheSoccerDivTwo * obj = new TheSoccerDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

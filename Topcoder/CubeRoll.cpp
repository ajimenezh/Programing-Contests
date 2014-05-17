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
#include <queue>

using namespace std;

class CubeRoll {
public:
	int getMinimumSteps(int, int, vector <int>);
};

vector<int> a;
int n;
int CubeRoll::getMinimumSteps(int initPos, int goalPos, vector <int> holePos) {
	if (goalPos<initPos) {
		int temp = goalPos;
		goalPos = initPos;
		initPos = temp;
	}
	a = holePos;
	n = a.size();
	sort(a.begin(),a.end());
	int left=-100000,right=200000;
	for (int i=0; i<n; i++) {
		if (a[i]>=initPos && a[i]<=goalPos) return -1;
		if (a[i]<initPos) left = max(left,a[i]);
		if (a[i]>goalPos) right = min(right,a[i]);
	}
	
	queue<int> q;
	int dist[300000];
	int m = 100000;
	for (int i=left + m; i<=right+m; i++) dist[i]=-1;
	dist[initPos]=0;
	q.push(initPos);
	
	int maxsqr = 320;
	
	while ((q.front()!=goalPos || dist[goalPos]==-1) && !q.empty()) {
		int p = q.front();
		q.pop();
		for (int i=1; i<maxsqr; i++) {
			if ((p+i*i)<right && dist[p+i*i]==-1) {
				dist[p + i*i] = dist[p] + 1;
				q.push(p);
			}
			if ((p-i*i)>left && dist[p+i*i]==-1) {
				dist[p - i*i] = dist[p] + 1;
				q.push(p);
			}
		}
	}
	
	if (dist[goalPos]==-1) return -1;
	return dist[goalPos];
	
}


double test0() {
	int p0 = 5;
	int p1 = 1;
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CubeRoll * obj = new CubeRoll();
	clock_t start = clock();
	int my_answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	int p0 = 36;
	int p1 = 72;
	int t2[] = {300, 100, 200, 400};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CubeRoll * obj = new CubeRoll();
	clock_t start = clock();
	int my_answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	int p1 = 21;
	int t2[] = {38,45};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CubeRoll * obj = new CubeRoll();
	clock_t start = clock();
	int my_answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int p0 = 98765;
	int p1 = 4963;
	int t2[] = {10,20,40,30};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CubeRoll * obj = new CubeRoll();
	clock_t start = clock();
	int my_answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
double test4() {
	int p0 = 68332;
	int p1 = 825;
	int t2[] = {99726,371,67,89210};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CubeRoll * obj = new CubeRoll();
	clock_t start = clock();
	int my_answer = obj->getMinimumSteps(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

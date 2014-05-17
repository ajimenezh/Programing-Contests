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

class TheTournamentDivOne {
public:
	int find(vector <int>, int, int);
};

int TheTournamentDivOne::find(vector <int> points, int w, int d) {
	int n=points.size();
	vector<int> draw(n,0);
	
	for (int i=0; i<n; i++) {
	for (int j=10000; j>-1; j--) {
		if (points[i] - d*j>=0 && (points[i] - d*j)%w==0) {
			draw[i]=j;
			break;
		}
	}
	
}


double test0() {
	int t0[] = {10, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	int p2 = 1;
	TheTournamentDivOne * obj = new TheTournamentDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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
	int t0[] = {1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	int p2 = 1;
	TheTournamentDivOne * obj = new TheTournamentDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
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
double test2() {
	int t0[] = {1, 4, 0, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	int p2 = 1;
	TheTournamentDivOne * obj = new TheTournamentDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
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
double test3() {
	int t0[] = {8, 3, 8, 5, 9, 2, 7, 11};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	int p2 = 2;
	TheTournamentDivOne * obj = new TheTournamentDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 15;
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

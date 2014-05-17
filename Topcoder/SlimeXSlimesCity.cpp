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

class SlimeXSlimesCity {
public:
	int merge(vector <int>);
};

bool possible (int a, vector<long long> v) {
	int n= v.size();
	for (int i=0; i<(n-1); i++) {
		long long m=1000000010;
		int ind = -1;
		for (int j=0; j<n; j++) {
			if (j!=a && v[j]!=-1 && v[j]<m) {m=v[j]; ind = j;}
		}
		if (ind==-1 || m>v[a]) return false;
		v[a]+=m;
		v[ind]=-1;
	}
	
	return true;
}
		
		
int SlimeXSlimesCity::merge(vector <int> population) {
	int res = 0;
	vector<long long> pop;
	for (int i=0; i<population.size(); i++) pop.push_back((long long)population[i]);
	for (int i=0; i<population.size(); i++) {
		if (possible(i,pop)) res++;
	}
	
	return res;
}


double test0() {
	int t0[] = {2, 3, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
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
double test1() {
	int t0[] = {1, 2, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
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
	int t0[] = {8,2,3,8};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
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
double test3() {
	int t0[] = {1000000000, 999999999, 999999998, 999999997};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
double test4() {
	int t0[] = {1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
double test5() {
	int t0[] = {1, 2, 4, 6, 14, 16, 20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SlimeXSlimesCity * obj = new SlimeXSlimesCity();
	clock_t start = clock();
	int my_answer = obj->merge(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

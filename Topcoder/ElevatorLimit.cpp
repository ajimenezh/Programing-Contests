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

class ElevatorLimit {
public:
	vector <int> getRange(vector <int>, vector <int>, int);
};

vector <int> ElevatorLimit::getRange(vector <int> enter, vector <int> exit, int physicalLimit) {
	int m = 99999;
	int M = -1;
	
	int p = 0;
	int n = exit.size();
	
	for (int i=0; i<1000; i++) {
		
		bool pos = true;
		p=i;
		for (int j=0; j<n; j++) {
			p -= exit[j];
			if (p<0) {pos = false; break;}
			p+= enter[j];
			if (p>physicalLimit) {pos = false; break;}
		}
		
		
		if (pos) {
			m = min(m,i);
			M = max(M,i);
		}
	}
	
	vector<int> v;
	if (m==99999 || M == -1) return v;
	if (m<0 || M >physicalLimit) return v;
	v.push_back(m);
	v.push_back(M);
	return v;
}


double test0() {
	int t0[] = {1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0,  0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0,  1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {6, 85, 106, 1, 199, 76, 162, 141} ;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {38, 68, 62, 83, 170, 12, 61, 114} ;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 668;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 223,  500 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {179, 135, 104, 90, 97, 186, 187, 47, 152, 100, 119, 28, 193, 11, 103, 100,
 179, 11, 80, 163, 50, 131, 103, 50, 142, 51, 112, 62, 69, 72, 88, 3, 162,
 93, 190, 85, 79, 86, 146, 71, 65, 131, 179, 119, 66, 111} ;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {134, 81, 178, 168, 86, 128, 1, 165, 62, 46, 188, 70, 104, 111, 3, 47, 144,
 69, 163, 21, 101, 126, 169, 84, 146, 165, 198, 1, 65, 181, 135, 99, 100,
 195, 171, 47, 16, 54, 79, 69, 6, 97, 154, 80, 151, 76} ;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 954;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 453,  659 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	int t0[] = {2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	ElevatorLimit * obj = new ElevatorLimit();
	clock_t start = clock();
	vector <int> my_answer = obj->getRange(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
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

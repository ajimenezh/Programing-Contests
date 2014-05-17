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

class CorporationSalary {
public:
	long long totalSalary(vector <string>);
};

int dp[50];
vector<int> rel[50];
int search(int a) {
	if (dp[a]!=-1) return dp[a];
	if (rel[a].size()==0) return 1;
	
	int temp=0;
	for (int i=0; i<rel[a].size(); i++) temp+=search(rel[a][i]);
	
	dp[a]=temp;
	return temp;
}
long long CorporationSalary::totalSalary(vector <string> relations) {
	int n = relations.size();
	for (int i=0; i<n; i++) dp[i]=-1;
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++)
			if (relations[i][j]=='Y') rel[i].push_back(j);

	
	int res=0;
	for (int i=0; i<n; i++) res+=search(i);
	
	return res;
}


double test0() {
	string t0[] = {"N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CorporationSalary * obj = new CorporationSalary();
	clock_t start = clock();
	long long my_answer = obj->totalSalary(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
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
	string t0[] = {"NNYN",
 "NNYN",
 "NNNN",
 "NYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CorporationSalary * obj = new CorporationSalary();
	clock_t start = clock();
	long long my_answer = obj->totalSalary(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 5LL;
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
	string t0[] = {"NNNNNN",
 "YNYNNY",
 "YNNNNY",
 "NNNNNN",
 "YNYNNN",
 "YNNYNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CorporationSalary * obj = new CorporationSalary();
	clock_t start = clock();
	long long my_answer = obj->totalSalary(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 17LL;
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
	string t0[] = {"NYNNYN",
 "NNNNNN",
 "NNNNNN",
 "NNYNNN",
 "NNNNNN",
 "NNNYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CorporationSalary * obj = new CorporationSalary();
	clock_t start = clock();
	long long my_answer = obj->totalSalary(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 8LL;
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
	string t0[] = {"NNNN",
 "NNNN",
 "NNNN",
 "NNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CorporationSalary * obj = new CorporationSalary();
	clock_t start = clock();
	long long my_answer = obj->totalSalary(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 4LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

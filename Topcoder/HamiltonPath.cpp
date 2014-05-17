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

class HamiltonPath {
public:
	int countPaths(vector <string>);
};

vector<string> r;
vector<int> vis;
int n;
	
bool dfs(int a,int pre) {
	bool res=true;
	vis[a]=1;
	for (int i=0; i<n; i++) {
		if (r[a][i]=='Y' && vis[i]==-1 && i!=pre) res=res&dfs(i,a);
		else if (r[a][i]=='Y' && vis[i]!=-1 && i!=pre) return false;
	}
	
	return res;
}
			
int HamiltonPath::countPaths(vector <string> roads) {
	n=roads.size();
	vector<int> v(n,-1);
	vis=v;
	int is=0;
	
	r=roads;
	
	for (int i=0; i<n; i++) {	
		int count=0;
		for (int j=0; j<n; j++) {	
			if (r[i][j]=='Y') count++;
		}
		if (count>2) return 0;
		if (count==0) is++;
	}
	
	int tot=0;
	for (int i=0; i<n; i++) {
		if (vis[i]==-1) {
			if (!dfs(i,i)) return 0;
			tot++;
		}
	}
	
	int c=tot-is;
	long long res=1;
	long long mod=1000000007;
	for (int i=1; i<=tot; i++) {
		res = (res*i)%mod;
	}
	for (int i=1; i<=c; i++) {
		res=(res*2)%mod;
	}
	
	return res;
	
}
	


double test0() {
	string t0[] = {"NYN",
 "YNN",
 "NNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
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
double test1() {
	string t0[] = {"NYYY",
 "YNNN",
 "YNNN",
 "YNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"NYY",
 "YNY",
 "YYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"NNNNNY",
 "NNNNYN",
 "NNNNYN",
 "NNNNNN",
 "NYYNNN",
 "YNNNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HamiltonPath * obj = new HamiltonPath();
	clock_t start = clock();
	int my_answer = obj->countPaths(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 24;
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

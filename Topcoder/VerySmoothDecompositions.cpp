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

class VerySmoothDecompositions {
public:
	int solve(vector <string>);
};

long long mod = 1000000009;

bool divide(vector<int> &n, int p) {
	vector<int> v = n;
	int rest = 0;
	reverse(v.begin(),v.end());
	vector<int> vnew;
	

	for (int i=0; i<v.size(); i++) {
		rest = 10*rest + v[i];
		if (rest >= p) {
			vnew.push_back(rest/p);
			rest = rest%p;
		}
	}
	reverse(vnew.begin(),vnew.end());
	if (rest==0) n = vnew;
	return rest==0;
}
	

int primes[] = {2,3,5,7,11,13};

int decom[6][2] = {{1,0},{0,1},{2,0},{1,1},{3,0},{2,3}};

int VerySmoothDecompositions::solve(vector <string> digits) {
	string s;
	for (int i=0; i<digits.size(); i++) s += digits[i];
	reverse(s.begin(),s.end());
	
	vector<int> d;
	for (int i=0; i<s.length(); i++) d.push_back(s[i]-'0');
	
	vector<int> powers(6,0);
	for (int i=0; i<6; i++) {
		int n = 0;
		while (divide(d,primes[i])) n++;
		powers[i] = n;
	}
	if (d[0]!=1) return 0;
	for (int i=1; i<d.size(); i++) if (d[i]>0) return 0;
	
	vector<vector<int> > c(powers[0]+1,vector<int> (powers[1]+1,0));
	
	c[0][0] = 1;
	
	for (int i=0; i<6; i++) {
		for (int j=0; j<=powers[0]; j++) for (int k=0; k<=powers[1]; k++) {
			if (j-decom[i][0]>=0 && k-decom[i][1]>=0) 
				c[j][k] += c[j-decom[i][0]][k-decom[i][1]]%mod;
		}
	}
	
	long long res = 0;
	
	for (int a15=0; a15<=min(powers[1],powers[2]); a15++) {
		vector<int> p(1,0);
		for (int i=0; i<=powers[0]; i++) p.push_back(p[i] + c[i][powers[1] - a15]);
		
		for (int a14=0; a14<=min(powers[0],powers[3]); a14++){
			int maxa10 = min(powers[0]-a14,powers[1] - a15);
			
			res = res + (p[powers[0] - a14 + 1] - p[powers[0] - a14 - maxa10])%mod;
		}
		
		res %= mod; res += mod; res %=mod;
	}
	
	return res;
}


double test0() {
	string t0[] = {"47"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
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
double test1() {
	string t0[] = {"2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
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
double test2() {
	string t0[] = {"10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
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
	string t0[] = {"36"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {"1","21"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
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
double test5() {
	string t0[] = {"1024"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	VerySmoothDecompositions * obj = new VerySmoothDecompositions();
	clock_t start = clock();
	int my_answer = obj->solve(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 23;
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

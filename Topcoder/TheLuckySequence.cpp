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

class TheLuckySequence {
public:
	int count(vector <int>, int);
};

#define mod 1234567891;
typedef long long LL;

int first(int a) {
	return a%10;
}
int second(int a) {
	while (a>0) {
		if (a/10 <1) return a;
		a=a/10;
	}
	return 0;
}
bool lucky(int a) {
	while (a>0) {
		if (a%10!= 4 && a%10!=7) return false;
		a=a/10;
	}
	return true;
}
vector<vector<LL> > mult(vector<vector<LL> > a, vector<vector<LL> > b) {
	vector<vector<LL> > res(2,vector<LL>(2,0));
	
	LL temp=0;
	for (int i=0; i<2; i++) for(int j=0; j<2; j++) {
		temp=0;
		for(int k=0; k<2; k++) {
			temp+=a[i][k]*b[k][j];
		}
		res[i][j]=temp%mod;;
	}
	
	return res;
		
}
vector<vector<LL> > pow(vector<vector<LL> > m, int n) {
	if (n==1) return m;
	if (n%2==0) return mult(pow(m,n/2),pow(m,n/2));
	return mult(pow(m,n-1),m);
}
LL fact(int n) {
	if (n==1) return 1;
	return n*fact(n-1);
}
int TheLuckySequence::count(vector <int> numbers, int length) {
	
	vector<vector<LL> > m(2,vector<LL> ( 2,0));
	set<int> s;

	for (int i=0; i<numbers.size(); i++) if (lucky(numbers[i]) && s.find(numbers[i])==s.end()) {
		int a,b;
		a=first(numbers[i]);
		b=second(numbers[i]);
		if (a==4 && b==4) m[0][0]++;
		if (a==4 && b==7) m[0][1]++;
		if (a==7 && b==4) m[1][0]++;
		if (a==7 && b==7) m[1][1]++;
		
		s.insert(numbers[i]);
	}
	
	m = pow(m,length);

	long long res=(m[0][0] + m[1][1] + m[0][1]+ m[1][0])%mod;
	
	
	return res;
		
}


double test0() {
	int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {47, 74, 47};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {100, 4774, 200, 747, 300};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 47;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {44, 47, 74, 77};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	TheLuckySequence * obj = new TheLuckySequence();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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

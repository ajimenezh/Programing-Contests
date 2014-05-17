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

class PalindromicNumbers {
public:
	int countPalNums(int, int);
};

pair<long,long> pal(int a) {
	vector<int> v;
	while (a>0) {
		v.push_back(a%10);
		a=a/10;
	}
	long c=0;
	long b=0;
	
	long fact = 1;
	for (int i=v.size()-1; i>=0; i--) {
		c += v[i]*fact;
		fact*=10;
	}
	for (int i=0; i<v.size(); i++) {
		c += v[i]*fact;
		fact*=10;
	}
	fact = 1;
	for (int i=v.size()-1; i>=0; i--) {
		b += v[i]*fact;
		fact*=10;
	}
	for (int i=1; i<v.size(); i++) {
		b += v[i]*fact;
		fact*=10;
	}
	
	return make_pair(c,b);
}

int PalindromicNumbers::countPalNums(int lower, int upper) {
	pair<long,long> n;
	int res=0;
	for (int i=1; i*i<=(10*upper); i++) {
		n = pal(i);
		if (n.first>=lower && n.first<=upper) res++;
		if (n.second>=lower && n.second<=upper) res++;
		
		cout<<i<<" "<<n.first<<" "<<n.second<<endl;
	}
	
	return res;
}


double test0() {
	int p0 = 8;
	int p1 = 25;
	PalindromicNumbers * obj = new PalindromicNumbers();
	clock_t start = clock();
	int my_answer = obj->countPalNums(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int p0 = 111;
	int p1 = 222;
	PalindromicNumbers * obj = new PalindromicNumbers();
	clock_t start = clock();
	int my_answer = obj->countPalNums(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int p0 = 88966989;
	int p1 = 88977987;
	PalindromicNumbers * obj = new PalindromicNumbers();
	clock_t start = clock();
	int my_answer = obj->countPalNums(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int p0 = 999999990;
	int p1 = 1000000000;
	PalindromicNumbers * obj = new PalindromicNumbers();
	clock_t start = clock();
	int my_answer = obj->countPalNums(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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

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

class StringFragmentation {
public:
	int largestFontSize(string, int, int);
};

int StringFragmentation::largestFontSize(string text, int width, int height) {
	
	vector<string> v;
	stringstream ss(text);
	string str;
	
	while (ss>>str) v.push_back(str);
	
	double lo = 0;
	double hi = 10001;
	int i;
	
	while (hi - lo > 0.5) {
		double mi = lo + (hi - lo)/2;
		
		int x = 0;
		int y = mi*2;
		
		for (i=0; i<v.size(); i++) {
			if ((x + (mi+2)*v[i].length()) < width) x += (mi+2)*(v[i].length() + 1);
			else {y += 2*mi; x = 0; i--;}
			
			if (y>=height) {
				if (hi == lo + 1) return lo;
				hi = mi;
				break;
			}
			
			cout<<x<<" "<<y<<endl;
		}
		
		if (i==v.size()) {
			if (hi == lo + 1) return hi;
			lo = mi;
		}
		
		cout<<lo<<" "<<hi<<endl;
	}
	
	return lo > 7 ? int(hi) : -1;
	
			
}


double test0() {
	string p0 = "ONE TWO THREE FOUR FIVE";
	int p1 = 150;
	int p2 = 40;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 9;
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
	string p0 = "ONE TWO THREE FOUR FIVE";
	int p1 = 150;
	int p2 = 60;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	string p0 = "ONE TWO THREE FOUR FIVE";
	int p1 = 150;
	int p2 = 10000;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 28;
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
	string p0 = "ONE TWO THREE FOUR FIVE";
	int p1 = 10000;
	int p2 = 10000;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1250;
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
	string p0 = "ONE TWO THREE FOUR FIVE";
	int p1 = 50;
	int p2 = 50;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
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
double test5() {
	string p0 = "A";
	int p1 = 9;
	int p2 = 14;
	StringFragmentation * obj = new StringFragmentation();
	clock_t start = clock();
	int my_answer = obj->largestFontSize(p0, p1, p2);
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

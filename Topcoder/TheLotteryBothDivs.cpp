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

class TheLotteryBothDivs {
public:
	double find(vector <string>);
};

bool inside(string s1, string s2) {
	
	if (s1==s2) return true;
	if (s2.length()<s1.length()) return false;
	

	bool equal=true;
	for (int j=0;j<s1.length(); j++) {
		if (s1[s1.length()-1-j]!=s2[s2.length()-1-j]) {equal = false; break;}
	}
	if (equal) return true;

	return false;
}

double TheLotteryBothDivs::find(vector <string> goodSuffixes) {
	int n=goodSuffixes.size();
	vector<int> v(n,1);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i!=j && v[j]==1 && inside(goodSuffixes[j],goodSuffixes[i])) {
				v[i]=0;
				break;
			}
		}
	}
	double prob[11];
	prob[0]=1.0;
	for (int i=1; i<11; i++) prob[i]=prob[i-1]/10.0;
	
	double res=0;
	for (int i=0; i<n; i++) {
		if (v[i]==1) {
			res+=prob[goodSuffixes[i].length()];
		}
	}
	
	return res;
}


double test0() {
	string t0[] = {"4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.1;
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
	string t0[] = {"4", "7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.2;
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
	string t0[] = {"47", "47"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.01;
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
	string t0[] = {"47", "58", "4747", "502"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.021;
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
	string t0[] = {"8542861", "1954", "6", "523", "000000000", "5426", "8"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheLotteryBothDivs * obj = new TheLotteryBothDivs();
	clock_t start = clock();
	double my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 0.201100101;
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

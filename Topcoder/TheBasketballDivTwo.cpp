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

class TheBasketballDivTwo {
public:
	int find(vector <string>);
};


int TheBasketballDivTwo::find(vector <string> table) {

	int n=table.size();
	int k=0;
	map<pair<int,int>,int > m;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		if (table[i][j]=='?') {
			m[make_pair(i,j)]=k;
			k++;
		}
	}
	
	int res=100;
	if (k==0) {
		int sol=0;
		for (int l=0; l<n; l++) {
			int t=0;
			for(int j=0; j<n; j++) if (table[l][j]=='W') t++;
			for(int j=0; j<n; j++) if (table[j][l]=='L') t++;

			sol=max(t,sol); 
		}
		return sol;
	}
	
	for (int i=0; i<(1<<k); i++) {
		vector<string> temp=table;
		for (int p=0; p<n; p++) for(int r=0; r<n; r++) {
			if (temp[p][r]=='?') {

				if ((1<<m[make_pair(p,r)] & i) == 1<<m[make_pair(p,r)]) temp[p][r]='W'; 
				else temp[p][r]='L'; 
			}
		}

		int sol=0;
		for (int l=0; l<n; l++) {
			int t=0;
			for(int j=0; j<n; j++) if (temp[l][j]=='W') t++;
			for(int j=0; j<n; j++) if (temp[j][l]=='L') t++;

			sol=max(t,sol); 
		}
		//cout<<endl;
		res=min(res,sol);
	}
	
	return res;
	
	
}


double test0() {
	string t0[] = {"X?", "?X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
double test1() {
	string t0[] = {"XW", "LX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
	string t0[] = {"XWL", "?XW", "WLX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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
	string t0[] = {"X?????", "?X???", "??X??","???X?","????X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TheBasketballDivTwo * obj = new TheBasketballDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0);
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

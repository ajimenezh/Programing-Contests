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

class ShipLoading {
public:
	int minimumTime(vector <int>, vector <string>);
};

int ShipLoading::minimumTime(vector <int> cranes, vector <string> boxes) {
	vector<int> c = cranes;
	sort(c.begin(),c.end());
	vector<int> b;
	string s;
	for (int i=0; i<boxes.size(); i++) s += boxes[i];
	stringstream ss(s);
	string str;
	while(ss>>str) {
		b.push_back(atoi(str.c_str()));
	}
	sort(b.begin(),b.end());
	
	if (b[b.size()-1]>c[c.size()-1]) return -1;
	
	vector<int> vis(b.size(),0);
	
	reverse(c.begin(),c.end());
	reverse(b.begin(),b.end());
	
	for (int i=0; i<b.size(); i++) cout<<b[i]<<" ";
	cout<<endl;
	

	int t = 0;
	while (true) {
		t++;
		bool done = false;
		for (int i=0; i<c.size(); i++) {

			for (int j=0; j<b.size(); j++) {
				if (!vis[j] && b[j]<=c[i]) {
					done = true;
					vis[j] = 1;
					break;
				}
			}
		}
		for (int i=0; i<b.size(); i++) cout<<vis[i]<<" ";
		cout<<endl;
		if (!done) break;
	}
	
	for (int i=0; i<b.size(); i++) if (!vis[i]) return -1;
	return t-1;

}


double test0() {
	int t0[] = {6,8,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"2 5 2 4 7"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ShipLoading * obj = new ShipLoading();
	clock_t start = clock();
	int my_answer = obj->minimumTime(p0, p1);
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
	int t0[] = {19,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"14 12 16 19 16 1 5"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ShipLoading * obj = new ShipLoading();
	clock_t start = clock();
	int my_answer = obj->minimumTime(p0, p1);
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
double test2() {
	int t0[] = {23,32,25,28};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"5 27 10 16 24 20 2 32 18 7"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ShipLoading * obj = new ShipLoading();
	clock_t start = clock();
	int my_answer = obj->minimumTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {11,17,5,2,20,7,5,5,20,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"18 18 15 15 17"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ShipLoading * obj = new ShipLoading();
	clock_t start = clock();
	int my_answer = obj->minimumTime(p0, p1);
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
double test4() {
	int t0[] = {56,114,979,120,120,87,480};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"221 882 504 358 642 674 212 679 203 279 632 799 79","6 502 275 823 372 594 482 343"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ShipLoading * obj = new ShipLoading();
	clock_t start = clock();
	int my_answer = obj->minimumTime(p0, p1);
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

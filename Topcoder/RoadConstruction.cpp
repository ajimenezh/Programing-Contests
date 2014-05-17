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

class RoadConstruction {
public:
	int getExitTime(vector <string>);
};

int RoadConstruction::getExitTime(vector <string> currentLanes) {
	int c=0;
	
	int n = currentLanes.size(); 
	vector<int> pos(n,0);
	vector<int> yield(26,0); 
	
	bool exit = false;
	
	while (!exit) {
		
		for (int i=0; i<n; i++) {
			if (pos[i]>=currentLanes[i].length()) continue;

			if (yield[currentLanes[i][pos[i]]-'A']) {
				pos[i]++;

				if (currentLanes[i][pos[i]-1]=='D') return c;
				cout<<currentLanes[i][pos[i]-1]<<endl;
				break;
			}
			else {
				int k = i;
				while (k<(n-1) && pos[k]<currentLanes[k].length() && yield[currentLanes[k][pos[k]]-'A']==0) {yield[currentLanes[k][pos[k]]-'A']=1; k++;}
				if (pos[k]>=currentLanes[k].length()) k--;
				if (currentLanes[k][pos[k]]=='D') return c;
				cout<<currentLanes[k][pos[k]]<<endl;
				pos[k]++;
				break;
			}
		}
		
		cout<<c<<endl;
		
		c++;
		
		exit = true;
		for (int i=0; i<n; i++) if (pos[i]<currentLanes[i].length()) exit = false;
	}
			
	return c;
}


double test0() {
	string t0[] = {"AB",
 "CD",
 "E"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RoadConstruction * obj = new RoadConstruction();
	clock_t start = clock();
	int my_answer = obj->getExitTime(p0);
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
	string t0[] = {"AH",
 "D",
 "BCG",
 "E",
 "F"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RoadConstruction * obj = new RoadConstruction();
	clock_t start = clock();
	int my_answer = obj->getExitTime(p0);
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
	string t0[] = {"AAA",
 "A",
 "AAA",
 "A",
 "AAD",
 "A",
 "AAB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RoadConstruction * obj = new RoadConstruction();
	clock_t start = clock();
	int my_answer = obj->getExitTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	string t0[] = {"DEFGHIJK"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RoadConstruction * obj = new RoadConstruction();
	clock_t start = clock();
	int my_answer = obj->getExitTime(p0);
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
double test4() {
	string t0[] = {"I",
 "WANT",
 "TO",
 "DRINK",
 "SOME",
 "COFFEE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	RoadConstruction * obj = new RoadConstruction();
	clock_t start = clock();
	int my_answer = obj->getExitTime(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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

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

class Algrid {
public:
	vector <string> makeProgram(vector <string>);
};

vector <string> Algrid::makeProgram(vector <string> output) {
	vector<string> a=output;
	int n=a.size();
	int m=a[0].length();
	
	for(int i=1; i<n; i++) {
	for (int j=0; j<m-1; j++) {
		cout<<a[i-1][j]<<" "<<a[i-1][j+1]<<endl;
		if (a[i-1][j]=='B' && a[i-1][j+1]=='B') {
			char temp=a[i][j];
			a[i][j]=a[i][j+1];
			a[i][j+1]=temp;
		}
		else if (a[i-1][j]=='B' && a[i-1][j+1]=='W') {
			if (!(a[i][j]=='W' || a[i][j+1]=='W')) {
				a[i][j]='X';
				a[i][j+1]='X';
			}
			else return vector<string> (0,"");
		} 
		else if (a[i-1][j]=='W' && a[i-1][j+1]=='B') {
			//cout<<a[i][j]<<" "<<a[i][j+1]<<endl;
			if (!(a[i][j]=='B' || a[i][j+1]=='B')) {
				a[i][j]='X';
				a[i][j+1]='X';
			}
			else return vector<string> (0,"");
		} 
	}
	for (int j=0; j<m; j++) if (a[i][j]=='X') a[i][j]='B';
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (a[i][j]=='X') a[i][j]='B';
	
	return a;
}


double test0() {
	string t0[] = {"WWWWWWW",
 "WWWWWWB",
 "BBBBBWW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Algrid * obj = new Algrid();
	clock_t start = clock();
	vector <string> my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"WWWWWWW", "WWWWWWB", "BBBBBBB" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"BBBBB",
 "WBWBW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Algrid * obj = new Algrid();
	clock_t start = clock();
	vector <string> my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"BBBBB", "WWBWB" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"BBBB",
 "BBBB",
 "BBWB",
 "WWBB",
 "BWBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Algrid * obj = new Algrid();
	clock_t start = clock();
	vector <string> my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <string> p1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"WWBBBBW",
 "BWBBWBB",
 "BWBBWBW",
 "BWWBWBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Algrid * obj = new Algrid();
	clock_t start = clock();
	vector <string> my_answer = obj->makeProgram(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"WWBBBBW", "BBBBBWB", "BBBBBBB", "BBBWBBB" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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

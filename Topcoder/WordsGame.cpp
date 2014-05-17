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

class WordsGame {
public:
	int minimumSwaps(vector <string>, string);
};

bool in(string str, set<char> s) {
	for (int j=0; j<str.length(); j++) if (s.find(str[j])==s.end()) return false;
	return true;
}
int WordsGame::minimumSwaps(vector <string> grid, string word) {
	int n=grid.size();
	int res = 10000;
	// search word in a row
	for (int i=0; i<n; i++) {
		set<char> s;
		for (int j=0; j<n; j++) s.insert(grid[i][j]);
		if (in(word,s)) {
			string str=grid[i];
			int sol=0;
			for (int p=0; p<n; p++) {
				for (int r=0; r<n; r++) {
					if (str[r]==word[p] && p!=r) {
						char temp = str[r];
						str[r]=str[p];
						str[p] = temp;
						sol++;
					}
				}
			}
			res = min(res,sol);
		}
	}
	//search in a column
	for (int i=0; i<n; i++) {
		set<char> s;
		for (int j=0; j<n; j++) s.insert(grid[j][i]);	
		if (in(word,s)) {
			int sol=0;
			string str;
			for (int j=0; j<n; j++) str+=grid[j][i];	
			for (int p=0; p<n; p++) {
				for (int r=0; r<n; r++) {
					if (str[r]==word[p] && p!=r) {
						char temp = str[r];
						str[r]=str[p];
						str[p] = temp;
						sol++;
					}
				}
			}
			res = min(res,sol);
		}
	}
	if (res < 10000) return res;
	return -1;
}


double test0() {
	string t0[] = {"Mu",
 "uM"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "Mu";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
double test1() {
	string t0[] = {"sdf",
 "bca",
 "hgf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "abc";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
	string t0[] = {"cdf",
 "bca",
 "agf"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "abc";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
double test3() {
	string t0[] = {"xSZB",
 "gbHk",
 "kbgH",
 "WFSg"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "bkHg";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
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
	string t0[] = {"eKUNGHktLB",
 "EtBFDndTlG",
 "RRFHmjwrDs",
 "eKYsHlYhlu",
 "ljxyJSwTds",
 "dUQToyWHvl",
 "azDPWRwioE",
 "EARdktoDBh",
 "dmIqcGSvCE",
 "wXypNQEMxz"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "oDmWcJHGNk";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
double test5() {
	string t0[] = {"ab",
 "bA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "aB";
	WordsGame * obj = new WordsGame();
	clock_t start = clock();
	int my_answer = obj->minimumSwaps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

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

class NimForK {
public:
	vector <int> winners(int, int, vector <string>);
};

double dp[51][21];
vector<int> m[51];
int K;

double rec(int p, int k) {
	if (p==0) return 0.0;
	if (dp[p][k]!=-1) return dp[p][k];
	
	vector<double> moves;
	for (int i=0; i<m[p].size(); i++) {
		if (p>=m[p][i]) {
			moves.push_back(1.0 - rec(p - m[p][i],(k+1)%K));
		}
	}
	
	bool win=false;
	vector<double> pos_moves;
	for (int i=0; i<moves.size();i++) {
		if (moves[i]>0.9999999) win = true;
		if (moves[i]>0.00000001) pos_moves.push_back(moves[i]);
	}
	
	if (win) {
		dp[p][k] = 1.0;
		return dp[p][k];
	}
	
	double res = 0.0;
		
	for (int i=0; i<pos_moves.size(); i++) res += pos_moves[i];
	
	if (pos_moves.size()>1) res /= pos_moves.size();
	
	dp[p][k] = res;
	
	return res;
}

vector <int> NimForK::winners(int n, int k, vector <string> moves) {
	for (int i=0; i<n; i++) {
		stringstream ss(moves[i]);
		string s;
		while (ss>>s) m[i].push_back(atoi(s.c_str()));
	}
	
	K = k;
	
	for (int i=0; i<k; i++) for (int j=0; j<=n; j++) dp[j][i] = -1;
	
	vector<int> v;
	for (int i=0; i<k; i++) {
		double p = rec(n,i);
		if (p>0.0000001) v.push_back(i);
	}
	
	return v;
}


double test0() {
	int p0 = 8;
	int p1 = 2;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {2 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 7;
	int p1 = 2;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 3;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {2, 3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 6;
	int p1 = 3;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {1, 3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 1;
	int p1 = 20;
	string t2[] = {""};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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

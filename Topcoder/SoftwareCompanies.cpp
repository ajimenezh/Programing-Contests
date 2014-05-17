#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
int n;
map<string,int> id;
int cap[24][24];
int a[24][24];
int f[24][24];
int lab[12];
bool canUse[12];
#define inf 1000000;

class SoftwareCompanies {
public:
	vector <string> produceData(vector <string>, vector <string>, vector <int>, vector <int>, string, string);
};
int augment_path(int s, int t) {
	queue<int> q;
	int from[24];
	for (int i=0; i<24; i++) from[i]=-1;
	for (int i=0; i<24; i++) for (int j=0; j<24; j++) f[i][j]=0;
	from[s]=s;
	q.push(s);
	int flow=0;
	int v=-1;
	while (!q.empty() && v!=t) {
		v=q.front();
		q.pop();
		for (int i=0; i<2*n; i++) {
			if (from[i]==-1 && a[v][i]>0 && canUse[i/2]) {
				from[i]=v;
				q.push(i);
				if (i==t) break;
			}
		}
	}
	
	v=t;
	while (from[v]!=v) {
		flow = min(a[from[v]][v],flow);
		v=from[v];
	}
	v=t;
	while (from[v]!=v) {
		a[from[v]][v]-=flow;
		f[from[v]][v]+=flow;
		v=from[v];
	}
	return flow;
}
		
	
		
int findFlow(int s, int t) {
	int flow=0;

	while (true) {
		flow+=augment_path(s,t);
		if (flow == 0) break;
	}
	
	return flow;
}
vector <string> SoftwareCompanies::produceData(vector <string> names, vector <string> process, vector <int> cost, vector <int> amount, string company1, string company2) {
	n = names.size();
	for (int i=0; i<n; i++) id[names[i]] = i;
	
	for (int i=0; i<24; i++) for (int j=0; j<24; j++) cap[i][j]=0;
	int c1 = id[company1];
	int c2 = id[company2];
	
	for (int i=0; i<n; i++) {
		stringstream ss(process[i]);
		string s;
		while (ss>>s) {
			int j=id[s];
			cap[2*i +1][2*j] = inf;
		}
	}
	for (int i=0; i<n; i++) cap[2*i][2*i+1] = amount[i];
	vector<string> res;
	int bestAm = 0;
	int bestCost = 0;
	for (int mask=0; mask<(1<<n); mask++) {
		if (mask & 1<<c1 == 1<<c1 || mask & 1<<c2 == 1<<c2) continue;
		for (int i=0; i<2*n; i++) canUse[i] =  mask & 1<<(i/2) == 1<<(i/2);
		for (int i=0; i<2*n; i++) for (int j=0; j<2*n; j++) {
			a[i][j] = cap[i][j];
		}
		int flow = findFlow(2*c1, 2*c2 +1);
		vector<string> cur;
		int curCost=0;
		for (int i=0; i<n; i++) {
			if (mask & 1<<i == 1<<i) {
				cur.push_back(names[i]);
				curCost += cost[i];
			}
		}
		sort(cur.begin(),cur.end());
		if (flow>bestAm || flow == bestAm && (curCost < bestCost || curCost == bestCost && cur < res)) {
			bestAm = flow;
			bestCost = curCost;
			res = cur;
		}
	}
	return res; 
	
}


double test0() {
	string t0[] = {"topcoder", "doodle", "nasa", "ninny", "idm", "noname", "kintel"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"doodle nasa noname", "idm ninny noname", "idm ninny noname", "kintel", "kintel", "", ""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {1, 2, 7, 4, 6, 1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {50, 10, 11, 9, 14, 11, 23};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	string p4 = "topcoder";
	string p5 = "kintel";
	SoftwareCompanies * obj = new SoftwareCompanies();
	clock_t start = clock();
	vector <string> my_answer = obj->produceData(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t6[] = {"doodle", "idm", "kintel", "nasa", "ninny", "topcoder" };
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<"\""<<p6[0]<<"\"";
		for (int i=1; i<p6.size(); i++)
			cout <<", \"" <<p6[i]<<"\"";
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
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {5, 5, 5, 10, 6, 6, 3, 0, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10, 7, 10, 9, 6, 9, 23, 13, 11};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	string p4 = "b";
	string p5 = "d";
	SoftwareCompanies * obj = new SoftwareCompanies();
	clock_t start = clock();
	vector <string> my_answer = obj->produceData(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t6[] = {"a", "b", "ba", "d" };
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<"\""<<p6[0]<<"\"";
		for (int i=1; i<p6.size(); i++)
			cout <<", \"" <<p6[i]<<"\"";
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
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"b", "bz", "ba", "d", "z", "ca", "y", "a", "x"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"bz ba z ca", "ba", "d", "", "ca", "d", "a", "x", ""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {5, 5, 5, 10, 6, 6, 3, 1, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10, 7, 10, 9, 6, 9, 23, 13, 11};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	string p4 = "b";
	string p5 = "d";
	SoftwareCompanies * obj = new SoftwareCompanies();
	clock_t start = clock();
	vector <string> my_answer = obj->produceData(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t6[] = {"b", "ba", "d" };
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<"\""<<p6[0]<<"\"";
		for (int i=1; i<p6.size(); i++)
			cout <<", \"" <<p6[i]<<"\"";
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
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"coma", "comb", "comc", "comd"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"comb", "coma", "comd", "comc"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {10, 54, 18, 93};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10, 10, 10, 10};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	string p4 = "comb";
	string p5 = "comc";
	SoftwareCompanies * obj = new SoftwareCompanies();
	clock_t start = clock();
	vector <string> my_answer = obj->produceData(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <string> p6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<"\""<<p6[0]<<"\"";
		for (int i=1; i<p6.size(); i++)
			cout <<", \"" <<p6[i]<<"\"";
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
	if (my_answer != p6) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"c", "b", "a"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"b", "c", ""};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {1, 1, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1, 1, 22};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	string p4 = "c";
	string p5 = "b";
	SoftwareCompanies * obj = new SoftwareCompanies();
	clock_t start = clock();
	vector <string> my_answer = obj->produceData(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t6[] = {"a", "b", "c" };
	vector <string> p6(t6, t6+sizeof(t6)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p6.size() > 0) {
		cout <<"\""<<p6[0]<<"\"";
		for (int i=1; i<p6.size(); i++)
			cout <<", \"" <<p6[i]<<"\"";
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
	if (my_answer != p6) {
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

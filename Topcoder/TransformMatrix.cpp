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

#define INF 1000000;

class TransformMatrix {
public:
	int transform(vector <string>, vector <string>, vector <string>);
};

int sx,sy;
int numvert;
int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int maxflow(vector<vector<int> > cap, vector<vector<int> >cost, int s, int t) {
	int res = 0;
	
while (true) {
	vector<int> dist(numvert,INF);
	vector<int> pre(numvert,-1);
	dist[s]=0;
	pre[s]=s;
		
	while (true) {
		bool update = false;
		for (int i=0; i<numvert; i++) {
			if (dist[i]<INF) {
				for (int j=0; j<numvert; j++) {
					if (dist[j] > dist[i] + cost[i][j] && cap[i][j]>0) {
						dist[j] = dist[i] + cost[i][j];
						pre[j] = i;
						update = true;
					}
				}
			}
		}
		
		if (!update) break;
	}
	if (dist[t]>=INF) break;
	
	int u = t;
	res++;
	
	while (pre[u]!=u) {
		int v = pre[u];
		cap[v][u]-=1;
		cap[u][v]+=1;
		u = v;
	}
}

return res;
}


						

int TransformMatrix::transform(vector <string> A, vector <string> B, vector <string> count) {
	sx = A.size();
	sy = B.size();
	int count1 = 0, count2 = 0;
	for (int i=0; i<sx; i++) for (int j=0; j<sy; j++) {
		if (A[i][j]=='1') count1++;
		if (B[i][j]=='1') count2++;
	}
	if (count1 != count2) return -1;
	
	numvert = 3*sx*sy + 2;
	vector<vector<int> > cap(numvert,vector<int> (numvert, 0);
	vector<vector<int> > cost(numvert,vector<int> (numvert,INF);
	int s = sx*sy*3;
	int t = sx*sy*3 + 1;
	
	for (int i=0; i<sx; i++) for (int j=0; j<sy; j++) {
		if (A[i][j]==B[i][j]) {
			cap[i*j][sx*sy + i*j] = c[i][j]/2;
			cap[i*j][sx*sy + i*j] = 0;
			cap[sx*sy + i*j][2*sx*sy + i*j] = c[i][j]/2;
			cap[sx*sy + i*j][2*sx*sy + i*j] = 0;
		}
		else {
			if (A[i][j]=='1') {
				cap[i*j][sx*sy + i*j] = c[i][j]/2 + 1;
				cap[i*j][sx*sy + i*j] = 0;
				cap[sx*sy + i*j][2*sx*sy + i*j] = c[i][j]/2;
				cap[sx*sy + i*j][2*sx*sy + i*j] = 0;
			}
			else {
				cap[i*j][sx*sy + i*j] = c[i][j]/2;
				cap[i*j][sx*sy + i*j] = 0;
				cap[sx*sy + i*j][2*sx*sy + i*j] = c[i][j]/2 + 1;
				cap[sx*sy + i*j][2*sx*sy + i*j] = 0;
			}
		}
		if (A[i][j]=='1') {
			cap[s][sx*sy + i*j]=1;
			cost[s][sx*sy + i*j]=0;
		}
		if (B[i][j]=='1') {
			cap[sx*sy + i*j][t]=1;
			cost[sx*sy + i*j][t]=0;
		}
		
		for (int k=0; k<8; k++) {
			int x = i + dx[k];
			int y = j + dy[k];
			if ((x>-1 && x<sx) && (y>-1 && y<sy)) {
				cap[2*sx*sy + i*j][x*y]=INF;
				cost[2*sx*sy + i*j][x*y]=1;
			}
		}
	}
	
	int flow = mincostmaxflow(cap,cost,s,t);
	
	if (flow >=INF) return -1;
	return flow;
}


double test0() {
	string t0[] = {"110", 
 "000",
 "001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"000",
 "110",
 "100"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"222",
 "222",
 "222"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	string t0[] = {"10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"01"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"11"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string t0[] = {"111",
 "000",
 "111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"111",
 "000",
 "111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"013",
 "537",
 "136"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"001",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"000",
 "111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"000",
 "111"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
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
double test4() {
	string t0[] = {"100",
 "000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"000",
 "000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"999",
 "999"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
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
	string t0[] = {"011101",
 "110000",
 "000011",
 "000000",
 "100000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"110100",
 "000011",
 "000000",
 "110001",
 "000010"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"305713",
 "537211",
 "352421",
 "242212",
 "333313"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
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
double test6() {
	string t0[] = {"10",
 "00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00",
 "01"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"11",
 "11"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TransformMatrix * obj = new TransformMatrix();
	clock_t start = clock();
	int my_answer = obj->transform(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

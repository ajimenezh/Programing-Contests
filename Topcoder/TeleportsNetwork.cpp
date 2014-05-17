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

class TeleportsNetwork {
public:
	int distribute(int, vector <int>, vector <int>);
};

int dist(int x1, int y1, int x2, int y2) {
	int x = x1-x2;
	int y = y1-y2;
	return x*x + y*y;
}
int TeleportsNetwork::distribute(int teleportCount, vector <int> citiesX, vector <int> citiesY) {
	int n = citiesX.size();
	vector<vector<int> > m(n,vector<int>(n,0));
	
	for (int i=1; i<n; i++) {
		vector<int> closer;
		for (int j=0; j<n; j++) {
			if (i!=j) {
				if (dist(citiesX[0],citiesY[0],citiesX[j],citiesY[j])<dist(citiesX[0],citiesY[0],citiesX[i],citiesY[i])) {
					closer.push_back(j);
				}
			}
		}
		if (closer.size()==1) {
			m[i][closer[0]]=1;
			m[closer[0]][i]=1;
		}
		else {
			int m=10000000;
			for (int j=0; j<closer.size(); j++) if (dist(citiesX[0],citiesY[0],citiesX[closer[j]],citiesY[closer[j]]]<m) 
				m = dist(citiesX[0],citiesY[0],citiesX[closer[j]],citiesY[closer[j]]];
			}
			vector<int> closer2;
			for (int j=0; j<closer.size(); j++) if (dist(citiesX[0],citiesY[0],citiesX[closer[j]],citiesY[closer[j]]]==m) 
				closer2.push_back(closer[j]);
			if (closer2.size()==1) {
				m[i][closer2[0]]=1;
				m[closer2[0]][i]=1;
			}
			else {
				m = 100000;
				for (int j=0; j<closer2.size(); j++) if (m>citiesX[closer2[j]]) m = citiesX[closer2[j]];
				closer.clear();
				for (int j=0; j<closer2.size(); j++) if (m==citiesX[closer2[j]]) closer.push_back(j);
				if (closer.size()==1) {
					m[i][closer2[0]]=1;
					m[closer2[0]][i]=1;
				}
				else {
					m = 100000;
					for (int j=0; j<closer.size(); j++) if (m>citiesY[closer[j]]) m = citiesY[closer[j]];

					for (int j=0; j<closer.size(); j++) if (m==citiesY[closer[j]]) {
						m[i][closer[0]]=1;
						m[closer[0]][i]=1;
					}
				}
			}
		}
		
	}
	
	vector<vector<int> > dist(n,vector<int> (n,100000000);
	
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		if (m[i][j]==1) {
			dist[i][j]=1;
			if (i==0 || j==0) dist[i][0];
		}
		dist[i][i]=0;
	}
	for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (dist[i][j]<dist[i][k] + dist[k][j]) 
		dist[i][j] = dist[i][k] + dist[k][j];
	
	int res = 10000000;
	for (int i=1; i<n; i++) for (int j=1; j<n; j++) for (int k=1; k<n; k++) for (int s=1; s<n; s++) {
		int inconv = 0;
		for (int r=1; r<n; r++) incov += min(min(min(dist[r][0],dist[r][i]),dist[r][j]),min(dist[r][k],dist[r][s]));
		if (incov<res ) res = incov;
	}
	
	return res;
}


double test0() {
	int p0 = 2;
	int t1[] = {0,1,1,1,2,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,0,1,2,0,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TeleportsNetwork * obj = new TeleportsNetwork();
	clock_t start = clock();
	int my_answer = obj->distribute(p0, p1, p2);
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
double test1() {
	int p0 = 1;
	int t1[] = {0,1,1,1,2,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,0,1,2,0,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TeleportsNetwork * obj = new TeleportsNetwork();
	clock_t start = clock();
	int my_answer = obj->distribute(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int p0 = 0;
	int t1[] = {0,1,1,1,2,3,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,1,2,0,0,0,2,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TeleportsNetwork * obj = new TeleportsNetwork();
	clock_t start = clock();
	int my_answer = obj->distribute(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	int p0 = 1;
	int t1[] = {0,1,2,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0,0,0,0,0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TeleportsNetwork * obj = new TeleportsNetwork();
	clock_t start = clock();
	int my_answer = obj->distribute(p0, p1, p2);
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
double test4() {
	int p0 = 4;
	int t1[] = {64,200,384,294,175,107,303,374,224,220,223,99,442};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {79,161,83,281,344,217,184,336,431,262,75,474,257};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	TeleportsNetwork * obj = new TeleportsNetwork();
	clock_t start = clock();
	int my_answer = obj->distribute(p0, p1, p2);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

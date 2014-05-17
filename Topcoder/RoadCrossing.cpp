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

class RoadCrossing {
public:
	double passTime(vector <string>, int, int, int);
};

vector<pair<int,int> > v;
int w;
int cw;

double mintime(int i, int j) {
	
	

double RoadCrossing::passTime(vector <string> pedestrians, int roadWidth, int carWidth, int carArrival) {
	

	int n = pedestrians.size(); 
	w = roadWidth;
	cw = carWidth;
	double eps = 0.000001;
	
	int x0 = w - cw;
	
	
	for (int i=0; i<n; i++) {
		int a,b;
		stringstream ss(pedestrians[i]);
		string s;
		ss>>s; a = atoi(s.c_str());
		ss>>s; b = atoi(s.c_str());
		
		v.push_back(make_pair(a,b));
	}
	
	vector<pair<double,double> > intv;
	for (int i=0; i<n; i++) {
		double a,b;
		
		a = 1.0*x0/(1.0*v[i].second) + v[i].first;
		b = 1.0*cw/(1.0*v[i].second) + v[i].first;
		
		intv.push_back(make_pair(a,b));
	}
	
	double tmin = 100000;
	for (int i=0; i<n; i++) tmin = min(tmin, 1.0*v[i].first);
	
	if (tmin<carArrival) tmin = 100000;
	
	for (int i=0; i<n; i++) {
		double b = v[i].second;
		
		bool exist = true;
		
		for (int j=0; j<n; j++) if (j!=i) 
			if (b>v[j].first+eps && b<v[j].second-eps) exist = false;
		
		if (exist && b > carArrival - eps) tmin = min(tmin,b);
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (i!=j)
			double t = mintime(i,j);
			double a,b;
			a = v[i].second*(t - v[i].first);
			b = v[j].second*(t - v[j].first);
			bool pos = true;
			for (int k=0; k<n; k++) {
				if (k!=i && k!=j) {
					double c = v[k].second*(t - v[k].first);;
					if (c<b-eps || c>a+eps) pos = false;
				}
			}
		}
	}
				
	cout<<tmin;
	
	return tmin<carArrival - eps ? carArrival : tmin;
		
			
}


double test0() {
	string t0[] = {"0 1", "2 5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 8;
	int p2 = 4;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"40 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 100;
	int p3 = 41;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 140.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 50;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.125;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 51;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 51.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"1000 1", "100 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000;
	int p2 = 1000;
	int p3 = 1000;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2000.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

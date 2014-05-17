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

class ColorfulMazeTwo {
public:
	double getProbability(vector <string>, vector <int>);
};

double ColorfulMazeTwo::getProbability(vector <string> maze, vector <int> trap) {
	int x = maze.size();
	int y = maze[0].length();
	
	int ox,oy;
	int tx,ty;
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
		if (maze[i][j]=='$') {
			ox = i;
			oy = j;
		}
		if (maze[i][j]=='!') {
			tx = i;
			ty = j;
		}
	}
	
	double dist[51][51];
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) dist[i][j] = 1.0;
	
	priority_queue<double,pair<int,int>,greater<int> > q;
	q.push(make_pair(0,make_pair(ox,oy)));
	
	int destx[] = {1,0,-1,0};
	int desty[] = {0,1,0,-1};
	
	while (!q.empty()) {
		pair<double,pair<int,int> > temp = q.top();
		double value = temp.first;
		pair<int,int> = temp.second;
		
		q.pop();
		
		for (int k=0; k<4; k++) {
			int px,py;
			px = p.first + destx[k];
			py = p.second+ desty[k];
			
			if (px>=0 && py>=0 && px<x && py<<y) {
				if (maze[px][py]!='#') {
					double cost = value;
					if (maze[px][py]>='A' && maze[px][py]<='G') 
						cost = (1.0-value)*trap[(maze[px][py] - 'A')]/100.0;
					if (cost<dist[px][py]) {
						dist[px][py] = cost;
						q.push(make_pair(cost,make_pair(px,py)));
					}
				}
			}
		}
	}
	
	return dist[tx][ty];
		
		
}


double test0() {
	string t0[] = { ".$.",
  "A#B",
  "A#B",
  ".!." };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 50, 50, 0, 0, 0, 0, 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5;
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
	string t0[] = { ".$.",
  "A#B",
  "A#B",
  ".!." };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 50, 40, 0, 0, 0, 0, 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.6;
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
	string t0[] = { "$A#",
  ".#.",
  "#B!" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 10, 10, 10, 10, 10, 10, 10 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	string t0[] = { "$A..",
  "##.A",
  "..B!" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 50, 50, 0, 0, 0, 0, 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5;
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
	string t0[] = { "$C..",
  "##.A",
  "..B!" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 50, 50, 100, 0, 0, 0, 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
	string t0[] = { ".$.D.E.F.G.!." };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 10, 20, 30, 40, 50, 60, 70 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ColorfulMazeTwo * obj = new ColorfulMazeTwo();
	clock_t start = clock();
	double my_answer = obj->getProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.036000000000000004;
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

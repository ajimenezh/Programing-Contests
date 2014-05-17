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

#define INF 10000

class MazeOnFire {
public:
	int maximumTurns(vector <string>);
};

int m[51][51];
int reach[51][51];
int x,y;
int px,py;
bool vis[51][51];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int a, int b, int c) {
	if (vis[a][b]) return;
	vis[a][b] = 1;
	if (m[a][b]!=-1 && m[a][b]>c) m[a][b] = c;
	else return;
	
	for (int i=0; i<4; i++) {
		int p1 = a + dx[i];
		int p2 = b + dx[i];
		
		if (p1>=0 && p2>=0 && p1<x && p2<y) dfs(p1,p2,c+1);	
	}
	
	return;
}

void dfs2(int a, int b, int c) {
	if (vis[a][b]) return;
	vis[a][b] = 1;
	if (reach[a][b]!=-1) reach[a][b] = c;
	else return;
	
	for (int i=0; i<4; i++) {
		int p1 = a + dx[i];
		int p2 = b + dx[i];
		
		if (p1>=0 && p2>=0 && p1<x && p2<y) dfs(p1,p2,c+1);	
	}
	
	return;
}
	


int MazeOnFire::maximumTurns(vector <string> maze) {
	x = maze.size();
	y = maze[0].length();
	vector<pair<int,int> > fire;
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
		if (maze[i][j]!='#') m[i][j] = INF;
		else m[i][j] = -1;
		
		if (maze[i][j]!='#') reach[i][j] = INF;
		else reach[i][j] = -1;

		if (maze[i][j] == '$') {
			px = i;
			py = j;
		}
		if (maze[i][j]=='F') fire.push_back(make_pair(i,j));
	}
	
	for (int i=0; i<fire.size(); i++) {
		for (int k=0; k<x; k++) for (int j=0; j<y; j++) vis[k][j]=0;
		dfs(fire[i].first,fire[i].second,0);
	}
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) vis[i][j]=0;
	dfs2(px,py,0);
	
	int res = 0;
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
		if (m[i][j]!=-1 && m[i][j]>=reach[i][j]) 
			res = min(m[i][j],res);
	}
	
	return res;

		
}


double test0() {
	string t0[] = {"F..",
 ".$.",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeOnFire * obj = new MazeOnFire();
	clock_t start = clock();
	int my_answer = obj->maximumTurns(p0);
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
	string t0[] = {".F#...",
 "F....#",
 ".F###.",
 "F.#.$.",
 "F.#..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeOnFire * obj = new MazeOnFire();
	clock_t start = clock();
	int my_answer = obj->maximumTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"....#.",
 "$##.#.",
 ".#..#F",
 ".F#.#.",
 "..#..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeOnFire * obj = new MazeOnFire();
	clock_t start = clock();
	int my_answer = obj->maximumTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {"...$..",
 "..#...",
 "..###.",
 "..#...",
 "F.#.F."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeOnFire * obj = new MazeOnFire();
	clock_t start = clock();
	int my_answer = obj->maximumTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	string t0[] = {".F....F.",
 ".#.##.#.",
 ".#....#.",
 "F.$##..F",
 ".#....#.",
 ".###.##.",
 ".F....F."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MazeOnFire * obj = new MazeOnFire();
	clock_t start = clock();
	int my_answer = obj->maximumTurns(p0);
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

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

class RoboRace {
public:
	int startTime(vector <string>, vector <string>);
};

string moves;
bool dp[51][51][2501];
bool vis[51][51][2501];
int n;
int x,y;
char maze[51][51];
int ox,oy;
int fx,fy;

bool pos(int px, int py) {
	if (px<0 || py<0) return false;
	if (px>=x || py>=y) return false;
	if (maze[px][py]=='#') return false;
	
	return true;
}

bool check(int ox, int oy, int fx, int fy, int i) {
	if (ox!=fx && oy!=fy && maze[ox][oy]=='X') return true;
	if (maze[fx][fy]=='X') return false;
	if (vis[ox][oy][i]) return dp[ox][oy][i];
	
	vis[ox][oy][i] = 1;
	
	bool b;
	
	int dx=0,dy=0;
	if (moves[i]=='S') dy=1;
	else if (moves[i]=='N') dy=-1;
	else if (moves[i]=='E') dx=1;
	else if (moves[i]=='W') dx=-1;
	
	if (!pos(ox+dx, oy+dy) && !pos(fx+dx, fy+dy)) b = check(ox,oy,fx,fx,i+1);
	else if (!pos(ox+dx, oy+dy) && pos(fx+dx, fy+dy)) b = check(ox,oy,fx+dx,fx+dy,i+1) && check(ox,oy,fx,fx,i+1);
	else if (pos(ox+dx, oy+dy) && !pos(fx+dx, fy+dy)) b = check(ox+dx,oy+dy,fx,fx,i+1) || check(ox,oy,fx,fx,i+1);
	else {
		b = (check(ox,oy,fx+dx,fx+dy,i+1) && check(ox,oy,fx,fx,i+1)) || (check(ox+dx,oy+dy,fx,fx,i+1) && check(ox+dx,oy+dy,fx+dx,fx+dy,i+1));
	}
	
	dp[ox][oy][i] = b;
	
	return b;
}
		

int RoboRace::startTime(vector <string> board, vector <string> commands) {
	
	for (int i=0; i<moves.size(); i++) moves += commands[i];
	n = moves.length();
	x = board.size();
	y = board[0].length();
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) maze[i][j] = board[i][j];
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) for (int k=0; k<n; k++) vis[i][j][k]=0;
	
	for (int i=0; i<x; i++) for (int j=0; j<y; j++) {
		if (board[i][j]=='Y') {
			ox = i;
			oy = j;
		}
		if (board[i][j]=='F') {
			fx = i;
			fy = j;
		}
	}
	
	for (int i=0; i<n; i++) {
		bool ans = check(ox,oy,fx,fy,i);
		if (ans) return i;
	}
	return -1;
}


double test0() {
	string t0[] = {"#F",
 "YX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NES"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	RoboRace * obj = new RoboRace();
	clock_t start = clock();
	int my_answer = obj->startTime(p0, p1);
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
	string t0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"SSEEESSW"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	RoboRace * obj = new RoboRace();
	clock_t start = clock();
	int my_answer = obj->startTime(p0, p1);
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
	string t0[] = {"########",
 "#......#",
 "#.Y....#",
 "#.F.#..#",
 "#...X..#",
 "#...#..#",
 "#......#",
 "########"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ESSEESSW"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	RoboRace * obj = new RoboRace();
	clock_t start = clock();
	int my_answer = obj->startTime(p0, p1);
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
double test3() {
	string t0[] = {"##.#.#.",
 "..##...",
 "..#...X",
 "Y...##.",
 "#...#.#",
 "..#..F."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"SSSNWSSSEWNSENENENNNNENWNEWESE"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	RoboRace * obj = new RoboRace();
	clock_t start = clock();
	int my_answer = obj->startTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string t0[] = {"#..#.........#...X##....",
 "#........#..........##.#",
 ".#.#........#.....#.#...",
 "..###...#..##.##...#....",
 "..#.#.....#....#.#.####.",
 "#...##.##.##..#.....##..",
 ".##...#.#....#.......#.#",
 "....##.#..#....#....#...",
 "....###.##.....###...#..",
 "#.#.......#.#......#..#.",
 ".##....##.#.##.......#.#",
 "......###...####......#.",
 "..#.##.#..#.#...#...#...",
 ".....#.#..........#...#.",
 "##.#....##F#.....#.##.#.",
 ".##....#.......##.##.##.",
 "..#...#..##....#..#...Y.",
 "#...........#...###..###",
 ".....#...#..#.........#.",
 ".#...##..#.#...#..#.##..",
 "#..#...######....###.#..",
 "#.#.....#.......#.##....",
 "#..#....###....#.#..#...",
 "..#...#.##.##.#.##.##..#",
 "#....##.##..........#..#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NWWSEWSSNWESSWES",
 "ESEEENSNWNNWSNSNWWNWWNNNWE",
 "NSNENENNSEENWWNSNNNNWWSSN",
 "EENEWNWESESEEESNNNSEENNEWNNESNEESSEESEEENENNNWSSW",
 "NWNNWSNWSWSSSSEEWSSWSESWWNNWWENSNNWWSSWWNNE",
 "NWEWNEWSNEN",
 "NNNEWNSWSNWESWNNNSWWNNNWWWNNEWNEEWSSWNSSWWNNWESEWS",
 "WSSSEESSEEEEENNSWEWWWENSENWNSEENES",
 "NNSNESESWNESNENSEESESWSENNESESNESNESEEW",
 "ESNENEENWSNS"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	RoboRace * obj = new RoboRace();
	clock_t start = clock();
	int my_answer = obj->startTime(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 18;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

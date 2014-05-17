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

class RoundOfEleven {
public:
	long long maxIncome(int, int);
};

int f(int a) {
	return a + 80;
}

long long RoundOfEleven::maxIncome(int n, int money) {
	vector<int> digits;
	
	while (n>0) {
		digits.push_back(n%10);
		n /= 10;
	}
	
	int sum = 0;
	for (int i=0; i<digits.size(); i+=2) sum += digits[i];
	for (int i=1; i<digits.size(); i+=2) sum -= digits[i];
	
	int dp[160][510][2];
	
	for (int i=0; i<160; i++) for (int j=0; j<money; j++) dp[i][j][1] = 0;
	
	
	for (int i=0; i<digits.size(); i++) {
		int cur = i%2;
		int next = 1 - cur;
		
		int sgn;
		if (i%2==0) sgn = 1;
		else sgn = -1;
		
		for (int j=0; j<=money; j++) for (int s=-70; s<70; s++) {
			for (int k=0; k<=9; k++) {
				if (k>digits[i] && s + sgn*(k-digits[i])!=0) 
					dp[s][j][cur] += dp[f(s + sgn*(k-digits[i]))][j-abs(k-digits[i])][next];
				else if (k>digits[i] && s + sgn*(k-digits[i])==0)
					dp[s][j][cur] += dp[f(s + sgn*(k-digits[i]))][j-abs(k-digits[i])][next] + j-abs(k-digits[i]);
				else if (k<digits[i] && s + sgn*(k-digits[i])!=0)
					dp[s][j][cur] += dp[f(s - sgn*(k-digits[i]))][j-abs(k-digits[i])][next];
				else if (k<digits[i] && s + sgn*(k-digits[i])==0)
					dp[s][j][cur] += dp[f(s - sgn*(k-digits[i]))][j-abs(k-digits[i])][next] + j-abs(k-digits[i]);
				else if (k==digits[i] && s==0)
					dp[s][j][cur] += money;
			}
		}
	}
	
	

				

}


double test0() {
	int p0 = 31;
	int p1 = 4;
	RoundOfEleven * obj = new RoundOfEleven();
	clock_t start = clock();
	long long my_answer = obj->maxIncome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 6LL;
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
	int p0 = 31;
	int p1 = 5;
	RoundOfEleven * obj = new RoundOfEleven();
	clock_t start = clock();
	long long my_answer = obj->maxIncome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 11LL;
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
	int p0 = 110;
	int p1 = 3;
	RoundOfEleven * obj = new RoundOfEleven();
	clock_t start = clock();
	long long my_answer = obj->maxIncome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 7LL;
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
	int p0 = 19759;
	int p1 = 435;
	RoundOfEleven * obj = new RoundOfEleven();
	clock_t start = clock();
	long long my_answer = obj->maxIncome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3788217LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

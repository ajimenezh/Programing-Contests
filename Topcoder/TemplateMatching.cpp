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

class TemplateMatching {
public:
	string bestMatch(string, string, string);
};

string TemplateMatching::bestMatch(string text, string prefix, string suffix) {
	int n = text.length();
	
	int sum = 0;
	string sol;
	int psol = 0;
	
	for (int i=0; i<n; i++) for (int j=1; i+j<=n; j++) {
		string s = text.substr(i,j);
		
		int p = 0;
		int suf = 0;
		
		for (int k=prefix.length(); k>0; k--) {
			if (k<=s.length()) {
				string a = prefix.substr(prefix.length()-k,k);
				string b = s.substr(0,k);
				if (a ==  b) {
					p = k;
					break;
				}
			}
		}
		
		for (int k=1; k<suffix.length(); k++) {
			if (k<=s.length()) {
				string a = suffix.substr(0,k);
				string b = s.substr(s.length()-k,k);
				if (a ==  b) {
					suf = k;
					break;
				}
			}
		}
		
		if (suf+p>sum) {
			psol = p;
			sol = s;
			sum = p + suf;
		}
		else if (suf+p==sum) {
			if (p>psol) {
				psol = p;
				sol = s;
				sum = p + suf;
			}
			else if (p == psol && s<sol) {
				sol = s;
			}
		}
	}
	
	char c = 'z' + 1;
	if (sol=="") 
		for (int i=0; i<n; i++) 
			if (text[i]<c)
				c = text[i];
	if (c!='z'+1)
		sol += c;
	return sol;
}


double test0() {
	string p0 = "something";
	string p1 = "awesome";
	string p2 = "ingenious";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "something";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "havka";
	string p1 = "eto";
	string p2 = "papstvo";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "a";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "abracadabra";
	string p1 = "habrahabr";
	string p2 = "bracket";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "abrac";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "mississippi";
	string p1 = "promise";
	string p2 = "piccolo";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "ippi";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "a a a a a a";
	string p1 = "a a";
	string p2 = "a";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "a a";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "ab";
	string p1 = "b";
	string p2 = "a";
	TemplateMatching * obj = new TemplateMatching();
	clock_t start = clock();
	string my_answer = obj->bestMatch(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "b";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

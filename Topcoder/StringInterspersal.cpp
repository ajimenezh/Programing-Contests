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

class StringInterspersal {
public:
	string minimum(vector <string>);
};

string StringInterspersal::minimum(vector <string> W) {
	vector<int> pos(W.size(),0);
	
	string s;
	
	while(true) {
		vector<pair<string,int> > v;
		bool exist=false;
		char m='Z'+1;
		for (int j=0; j<W.size(); j++) {
			if (pos[j]>=W[j].length()) continue;
			exist = true;
			if (W[j][pos[j]]<m) {
				v.clear();
				m = W[j][pos[j]];
				string stemp;
				stemp += m;
				for (int k=pos[j]+1; k<W[j].length(); k++) {
					if (W[j][k]>stemp[stemp.length()-1]) break;
					stemp += W[j][k];
				}
				v.push_back(make_pair(stemp,j));
			}
			else if (W[j][pos[j]]==m) {
				string stemp;
				stemp += m;
				for (int k=pos[j]+1; k<W[j].length(); k++) {
					if (W[j][k]>stemp[stemp.length()-1]) break;
					stemp += W[j][k];
				}
				v.push_back(make_pair(stemp,j));
			}
		}
		
		if (!exist) break;
		
		string stemp=v[0].first;
		int ind=0;
		for (int j=1; j<v.size(); j++) {
			cout<<v[j].first<<endl;
			if ((v[j].first+stemp)<(stemp+v[j].first)) {
				stemp = v[j].first;
				ind = j;
			}
		}
		s+=stemp;
		pos[v[ind].second]+=stemp.length();
	}
	
	return s;

}


double test0() {
	string t0[] = {"DESIGN","ALGORITHM","MARATHON"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ADELGMAORARISIGNTHMTHON";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"TOMEK","PETR","ACRUSH","BURUNDUK","KRIJGERTJE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABCKPERIJGERRTJETOMEKTRURUNDUKUSH";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"CCCA","CCCB","CCCD","CCCE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "CCCACCCBCCCCCCDE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"BKSDSOPTDD","DDODEVNKL","XX","PODEEE","LQQWRT"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "BDDKLODEPODEEEQQSDSOPTDDVNKLWRTXX";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"TOPCODER","BETFAIR","NSA","BT","LILLY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "BBELILLNSATFAIRTOPCODERTY";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"QITHSQARQV","BYLHVGMLRY","LKMAQTJEAM","AQYICVNIKK","HKGZZFFEWC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ABHKGLKMAQIQQTHSQARQTJEAMVYICVNIKKYLHVGMLRYZZFFEWC";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {"XHCYBTUQUW","EKBISADSSN","LOOISPOFAK","MIXBDHPJUQ","BNMNDHMOTC"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringInterspersal * obj = new StringInterspersal();
	clock_t start = clock();
	string my_answer = obj->minimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "BEKBILMINMNDHMOOIOSADSPOFAKSSNTCXBDHPJUQXHCYBTUQUW";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

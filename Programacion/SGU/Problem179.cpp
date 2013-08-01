#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string s;

bool check() {
	int sum = 0;
	for (int i=0; i<s.length(); i++) {
		if (s[i]=='(') sum++;
		else sum--;
		if (sum<0) return false;
	}
	return true;
}

bool last() {
	for (int i=0; i<s.length(); i+=2) {
		if (s[i]=='(' && s[i+1]==')') continue;
		else return false;
	}
	return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>s;
	if (last()) {
		cout<<"No solution"<<endl;
		return 0;
	}
	while (true) {
		next_permutation(s.begin(),s.end());
		if (check()) break;
	}
	
	cout<<s<<endl;

    return 0;

}

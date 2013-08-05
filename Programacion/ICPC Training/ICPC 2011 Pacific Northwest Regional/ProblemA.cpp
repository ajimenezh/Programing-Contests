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
int n;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	getline(cin,s);
	while (n--) {
		int g = 0;
		int b = 0;
		getline(cin,s);
		string str = s;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==' ') continue;
			if (s[i]>='A' && s[i]<='Z') s[i] = char(s[i]-'A'+'a');
			if (s[i]=='g') g++;
			if (s[i]=='b') b++;
		}
		if (g>b) {
			cout<<str<<" is "<<"GOOD"<<endl;
		}
		else if (g<b) {
			cout<<str<<" is "<<"A BADDY"<<endl;
		}
		else {
			cout<<str<<" is "<<"NEUTRAL"<<endl;
		}
	}
	
    return 0;

}

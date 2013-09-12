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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s,t;
	cin>>s>>t;
	
	int p = 0, m = 0;
	int n = s.length(); 
	if (t.length()!=n) {cout<<-1; return 0;}
	for (int i=0; i<n; i++) s[i]=='+'?p++:m++;
	for (int i=0; i<n; i++) t[i]=='+'?p--:m--;
	if (p!=0 || m!=0) {cout<<-1; return 0;}
	
	int j=0;
	int ans = 0;
	for (int i=0; i<n; i++) {
		if (s[i]=='+') {
			while (j<n && t[j]=='-') j++;
			ans += abs(i-j++);
		}
	}
	
	cout<<ans<<endl;

    return 0;

}

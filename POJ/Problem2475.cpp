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

int dp[210][210][2];

bool solve(string &s, int in, int fn, int t) {
	if (dp[in][fn][t]!=-1) return dp[in][fn][t];
	if (fn==in+1) return fn-in!=s.length();
	if (in>=fn) return t==1;
	
	bool res = 0;
	
	if (t==0) {
		if (s[in]!='{' || s[fn-1]!='}') res = 0;
		else res = solve(s, in+1, fn-1, 1) || solve(s, in+1, fn-1, 0);
	}
	else {
		if (solve(s,in,fn,0)) res = true;
		else {
			for (int i=in+1; i<fn-1; i++) {
				if (s[i]==',') {
					if (solve(s,in, i,0) && solve(s,i+1,fn,1)) {
						res = true;
						break;
					}
				}
			}
		}
	}
	
	dp[in][fn][t] = res;
	return res;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n;
	cin>>n;
	int k = 1;
	while (n--) {
		string s;
		cin>>s;
		for (int i=0; i<=s.length(); i++) for (int j=0; j<=s.length(); j++) for (int k=0; k<2; k++) {
			dp[i][j][k] = -1;
		}
		if (solve(s,0,s.length(),0)) printf("Word #%d: Set\n",k++);
		else printf("Word #%d: No Set\n",k++);
	}
	
    return 0;

}

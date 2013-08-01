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

int n,m;
string s;
string v[13];
bool dp[5010][1<<12];
bool is[5010][12];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&m) && n!=0) {
		for (int i=0; i<n; i++) cin>>v[i];
		s = "";
		for (int i=0; i<m; i++) {
			string str;
			cin>>str;
			s += str;
		}
		for (int i=0; i<=s.length(); i++) {
			for (int k=0; k<(1<<n); k++) dp[i][k] = 0;
		}
		for (int i=0; i<s.length(); i++) {
			for (int k=0; k<n; k++) is[i][k] = 0;
			for (int k=0; k<n; k++) if (i+v[k].length()<=s.length()) {
				if (s.substr(i,v[k].length())==v[k]) {
					is[i][k] = 1;
				}
			}
		}

		int ans = 0;
		for (int i=0; i<s.length(); i++) dp[i][0] = 1;
		for (int i=0; i<s.length(); i++) {
			for (int k=0; k<(1<<n); k++) if (dp[i][k]) {
				for (int j=0; j<n; j++) {
					if (i+v[j].length()<=s.length() && is[i][j] && (k&(1<<j))==0) {
						dp[i+v[j].length()][k+(1<<j)] = 1;
					}
				}
			}
			if (dp[i][(1<<n)-1]) ans++;
		}
		if (dp[s.length()][(1<<n)-1]) ans++;
		
		printf("%d\n",ans);
	}

    return 0;

}

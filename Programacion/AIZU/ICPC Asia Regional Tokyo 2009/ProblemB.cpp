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

int n;
string a[11];
string b[11];
string source;
string target;
int ans;

void dfs(string s, int i, int cur) {
	if (cur>=ans) return;
	if (s==target) ans = cur;
	if (s.length()>target.length()) return;
	
	bool done = 0;
	
	for (int j=0; j<s.length(); j++) {
		if (j+a[i].length()<=s.length()) {
			bool ok = 1;
			for (int k=0; k<a[i].length(); k++) {
				if (s[j+k]!=a[i][k]) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				s = s.substr(0,j) + b[i] + s.substr(j+a[i].length(),s.length()-j-a[i].length());
				j += b[i].length()-1;
				done = 1;
			}
		}
	}
	if (done) {
		for (int j=0; j<n; j++) dfs(s,j,cur+1);
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		for (int i=0; i<n; i++) {
			cin>>a[i]>>b[i];
		}
		cin>>source>>target;
		ans = 1000000;
		for (int i=0; i<n; i++) dfs(source,i,0);
		if (ans==1000000) printf("-1\n");
		else printf("%d\n",ans);
	}

    return 0;

}

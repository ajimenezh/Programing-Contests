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

int p[50];
int t[50];
int n;
int dp[50][5];
bool vis[50][5];
int bad[50];

int solve(int i, int cur) {
	if (i==n+1) return p[i-1];
	if (vis[i][cur]) return dp[i][cur];
	
	int tmp = -1;
	
	if (cur==3) {
		if ((p[i]+p[i-1]*4) > t[i]-t[i-1]) {
			dp[i][cur] = -1;
			vis[i][cur] = 1;
			return -1;
		}
		bad[i] = 0;
		int d = (p[i]+p[i-1]);
		if (solve(i+1,1)!=-1)
			d += solve(i+1,1);
		else d = -1;
		bad[i] = 0;
		dp[i][cur] = d;
		vis[i][cur] = 1;
		return d;
	}
	else {
		int d = -1;
		if ((p[i]+p[i-1]*(cur+1)) <= t[i]-t[i-1]) {
			d = p[i]+p[i-1];
			if (solve(i+1,1)!=-1) 
				d += solve(i+1,1);
			else d = -1;
			bad[i] = 0;
		}
		if (abs(p[i]-p[i-1])*(cur+1) <= t[i]-t[i-1]) {
			int tmp;
			tmp = abs(p[i]-p[i-1]);
			if (solve(i+1,cur+1)!=-1)
				tmp += solve(i+1,cur+1);
			else tmp = -1;
			if (d==-1) d = tmp;
			else if (tmp!=-1 && d!=-1) d = min(tmp,d);
			bad[i] = 0;
		}
		dp[i][cur] = d;
		vis[i][cur] = 1;
		return d;
	}
	return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		for (int i=1; i<=n; i++) scanf("%d%d",p+i,t+i);
		
		t[0] = 0;
		p[0] = 0;
		
		for (int i=0; i<=n; i++) for (int k=0; k<5; k++) vis[i][k] = 0;
		
		for (int i=0; i<=n; i++) bad[i] = 1;
		
		int ans = solve(1,0);
		
		if (ans==-1) {
			int a;
			for (int i=1; i<=n; i++) if (bad[i]) {
				a = i;
				break;
			}
			cout<<"NG "<<a<<endl;
		}
		else cout<<"OK "<<ans<<endl;
	}

    return 0;

}

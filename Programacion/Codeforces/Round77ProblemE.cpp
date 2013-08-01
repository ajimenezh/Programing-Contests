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
int par[100010];
int dp[100010];
int sum[100010];
int tot[100010];

int get(int x) {
	return x==par[x]?par[x]:par[x]=get(par[x]);
}

bool islucky(int k) {
	while (k>0) {
		if (k%10!=4 && k%10!=7) return false;
		k /= 10;
	}
	return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) par[i] = i;
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		par[get(a)] = get(b);
	}
	for (int i=0; i<n; i++) tot[get(i)]++;
	for (int i=0; i<n; i++) sum[tot[i]]++;
	for (int i=0; i<=n; i++) dp[i] = 1000000000;
	dp[0] = 0;
	
	for (int i=1; i<=n; i++) if (sum[i]>0) {
		int k = sum[i];
		for (int p=1; k>0; p <<= 1) {
			p = min(p,k);
			k -= p;
			for (int j=n; j>=0; j--) if (j+p*i<=n) {
				dp[j+p*i] = min(dp[j+p*i], p + dp[j]);
			} 
		}
	}
	
	int ans = 1000000000;
	for (int i=1; i<=n; i++) if (islucky(i)) {
		ans = min(ans,dp[i]-1);
	}
	
	if (ans>=100000000) cout<<-1<<endl;
	else cout<<ans<<endl;

    return 0;

}

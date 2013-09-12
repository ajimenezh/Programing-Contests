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

#define mod 1000000007

int n;
int k1,k2;
int k;
int a[25];
long long dp[1<<24];
long long dist[1<<24];
int x;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	cin>>k;
	cin>>k1;
	if (k==2) cin>>k2;
	else k2 = k1;
	
	dp[0] = 1;
	dist[0] = 0;
	
	for (int i=0; i<(1<<n)-1; i++) if (dp[i]>0) {
		for (int j=0; j<n; j++) if (!((1<<j)&i)) {
			x = i^(1<<j);
			dist[x] = a[j] + dist[i];
			if (dist[x]==k2 || dist[x]==k1) dp[x] = 0;
			else {
				dp[x] = (dp[x] + dp[i]);
				if (dp[x]>mod) dp[x] -= mod;
			}
		}
		//cout<<i<<" "<<dp[i]<<endl;
	}
	
	cout<<dp[(1<<n)-1]<<endl;

    return 0;

}

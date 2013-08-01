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

#define mod 1000000007LL

long long sum[100010];
int par[100010];
int n;

int update(int v) {
	if (v==par[v]) return 0;
	sum[v] += update(par[v]);
	sum[v] %= mod;
	sum[v] = (sum[v]+mod)%mod;
	return sum[v];
}

int root(int v) {
	if (v==par[v]) return v;
	par[v] = root(par[v]);
	return par[v];
}

long long res;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) par[i] = i;
	for (int i=0; i<n; i++) {
		int k;
		scanf("%d",&k);
		for (int j=0; j<k; j++) {
			int v,p;
			scanf("%d%d",&v,&p); v--;
			long long tmp = update(v);
			int r = root(v);
			//cout<<r<<endl;
			sum[r] += (p+tmp)%mod;
			sum[r] = (sum[r]%mod+mod)%mod;
			par[r] = i;
			res = (res + sum[r])%mod;
			res = (res + mod)%mod;
			//cout<<i<<" "<<r<<" "<<sum[r]<<endl;
		}
	}

	cout<<res<<endl;

    return 0;

}

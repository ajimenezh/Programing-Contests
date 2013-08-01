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

int m;
long long n;
long long mod;

long long get(long long t, long long l, long long r, long long lt, long long rt, long long m, long long u) {
	if (r<lt || l>rt) return 0;
	if (l>=lt && r<=rt) {
		
		//cout<<l<<" "<<r<<" "<<m<<endl;
		if (m>u) return 0;
		
		long long tmp = (u-m)/t;
		if (tmp<0) tmp = 0;
		tmp = min(tmp, r-l);
		tmp %= mod;
		m %= mod;
		t %= mod;
		long long ans = (m*(tmp+1)%mod + (tmp*(tmp+1)/2)%mod*t)%mod;
		//cout<<ans<<endl;
		return ans;
	}
	
	long long h = (l+r)>>1LL;
	
	long long ans = get(2LL*t,l,h,lt,rt,m,u) + get(2LL*t,h+1,r,lt,rt,m+t,u);
	ans %= mod;
	
	return ans;
	
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m>>mod;
	
	for (int i=0; i<m; i++) {
		long long l,r,u,v;
		scanf("%I64d%I64d%I64d%I64d",&l,&r,&v,&u);
		
		long long tmp = get(1,1,n,l,r,1,u) - get(1,1,n,l,r,1,v-1);
		tmp = (tmp+mod)%mod;
		
		printf("%d\n",(int)tmp);
	}

    return 0;

}

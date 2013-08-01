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

#define MAXN 10000005

int f[MAXN], prime[MAXN];
long long cn[MAXN];
long long cnt[MAXN];

int k;
int a[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tot = 0;
	int tmp;
	for (int i=2; i<MAXN; i++) f[i] = i;
	for (int p=2; p<MAXN; p++) {
		if (f[p]==p) prime[tot++] = p;
		for (int i=0; i<tot && prime[i]<=f[p]; i++) {
			tmp = prime[i]*p;
			if (tmp<MAXN) {
				f[tmp] = prime[i];
			}
			else break;
		}
	}
	
	scanf("%d",&k);
	for (int i=0; i<k; i++) scanf("%d",a+i);
	//for (int i=0; i<k; i++) a[i] = 100000;
	int ma = 0;
	for (int i=0; i<k; i++) {
		ma = max(ma,a[i]);
		cn[a[i]]++;
	}
	for (int i=ma; i>=0; i--) cn[i] += cn[i+1];
	for (int i=2; i<=ma; i++) {
		int p = i;
		while (p!=1) {cnt[f[p]]+=cn[i]; p /= f[p];}
	}
	
	long long lo = 1;
	
	for (int i=0; i<tot; i++) if (prime[i]<=ma) {
		long long hi = 1LL<<60;
		
		//cout<<lo<<" "<<cnt[prime[i]]<<" "<<i<<" "<<prime[i]<<endl;
		
		while (lo<hi) {
			long long mi = (lo+hi)/2;
			
			long long p = prime[i];
			
			long long c = 0;
			
			while (true) {
				c += mi/p;
				if (p>mi/prime[i]) break;
				p*=(long long)prime[i];
				if (p>mi) break;
			}
			
			if (c<cnt[prime[i]]) lo = mi+1;
			else hi = mi;
		}
	}
	
	cout<<lo<<endl;

    return 0;

}

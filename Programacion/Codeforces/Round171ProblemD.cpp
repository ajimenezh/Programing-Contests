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

int cnt[1<<23];
bool vis[1<<23];
int n;
int a[24];
int id[24][24];
int c[1<<23];
int res;

int go(int mask) {
	if (mask==0) return 1000;
	if (mask==1) return 1;
	if (vis[mask]) return cnt[mask];
	
	int tmp = 1000;
	
	int p = -1;
	
	for (int i=n-1;;i--) {
		if (mask & (1<<i)) {
			p = i;
			break;
		}
	}
	mask -= (1<<p);

	for (int i=0; i<p; i++) if ((1<<i)&mask) {
		if (id[p][i]!=-1) {
			int j = id[p][i];
			if (j>=p) continue;
			if (!(i==p-1 || j==p-1 || (mask&(1<<(p-1))))) continue;
			if (mask&(1<<j)) {
				tmp = min(max(go(mask),c[mask]),tmp);
			}
			else {
				tmp = min(max(go(mask+(1<<j)),c[mask]+1),tmp);
			}
		}
	}
	for (int i=0; i<p; i++) if ((1<<i)&mask) {
		if (id[p][i]!=-1) {
			int j = id[p][i];
			if (mask&(1<<j)) {
				for (int t=max(p-2,0); t<p; t++) if (((1<<t)&mask)==0) {
					if (!(i==p-1 || j==p-1 || t==p-1 || (mask&(1<<(p-1))))) continue;
					//cout<<p<<" "<<i<<" "<<j<<" "<<t<<" "<<mask<<" "<<mask+(1<<p)<<endl;
					tmp = min(max(go(mask|(1<<t)),c[mask]+1),tmp);
				}
			}
		}
	}
	for (int i=0; i<p; i++) if (((1<<i)&mask)==0) {
		if (i!=p-1 && (mask&(1<<(p-1)))==0) continue;
		if (a[p]==2*a[i]) {
			tmp = min(max(go(mask+(1<<i)),c[mask]+1),tmp);
		}	
	}
	
	vis[mask+(1<<p)] = 1;
	cnt[mask+(1<<p)] = tmp;
	
	//cout<<mask<<" "<<p<<" "<<(mask|(1<<p))<<" "<<tmp<<endl;
	
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%d",&n);
	for (int i=0; i<n; i++) scanf("%d",a+i);
	
	if (n==1) {
		cout<<1<<endl;
		return 0;
	}
	
	res = 1000;
	
	for (int i=0; i<(1<<n); i++) c[i] = __builtin_popcount(i);
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) id[i][j] = -1;
	for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
		for (int k=0; k<n; k++) if (a[j]+a[k]==a[i]) {
			id[i][j] = k;
		}
	}
	
	for (int i=0; i<(1<<(n-1)); i++) {
		if (go(i|(1<<(n-1)))!=1000) {
			//cout<<i<<" "<<go(i|(1<<(n-1)))<<" "<<cnt[i|(1<<(n-1))]<<endl;
			res = min(res,max(cnt[i|(1<<(n-1))],c[i]));
		}
	}
	
	if (res==1000) cout<<-1<<endl;
	else cout<<res<<endl;

    return 0;

}

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

int n,s,w,q;
int v[100010];
int sum[100010];
map<int,int> all;
long long p[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d%d",&n,&s,&w,&q) && n!=0) {
		int g = s;
		for (int i=0; i<n; i++) {
			v[i] = (g/7)%10;
			if (g%2==0) g = g/2;
			else g = (g/2) ^ w;
		}
		all.clear();
		int ans = 0;
		if (v[n-1]%q==0 && v[n-1]!=0) ans++;
		sum[n-1] = v[n-1]%q;
		p[n-1] = 1;
		all[sum[n-1]]++;
		if (q!=2 && q!=5) all[0]++;
		for (int i=n-2; i>=0; i--) p[i] = (10*p[i+1])%q;
		for (int i=n-2; i>=0; i--) {
			if (q==2) {
				all[v[i]%2]++;
				if (v[i]!=0) ans += all[0];
			}
			else if (q==5) {
				all[v[i]%5]++;
				if (v[i]!=0) ans += all[0];
			}
			else {
				sum[i] = (sum[i+1] + (v[i]*p[i])%q)%q;
			
				if (v[i]!=0) ans += all[sum[i]];
			
				all[sum[i]]++;
			}
		}
		
		cout<<ans<<endl;
	}

    return 0;

}

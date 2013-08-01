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
int v[130];
int best[130];
int all[3000];
int sol[130];

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&m,&n) && n!=0) {
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			int t = 0;
			for (int j=0; j<m; j++) {
				t = 2*t + (s[j]=='1');
			}
			v[i] = t;
			best[i] = 100;
		}
		int ans = 0;
		for (int i=0; i<(1<<m); i++) all[i] = 0;
		for (int i=0; i<(1<<m); i++) {
			for (int j=0; j<n; j++) {
				int k = (v[j]&i);
				all[k]++;
			}
			int t = __builtin_popcount(i);
			for (int j=0; j<n; j++) {
				int k = (v[j]&i);
				if (all[k]==1) {
					if (best[j]>t) {
						best[j] = t;
						sol[j] = i;
					}
				}
			}
			for (int j=0; j<n; j++) {
				int k = (v[j]&i);
				all[k] = 0;
			}
		}
		for (int i=0; i<n; i++) {
			int t = sol[i];
			string s;
			while (t>0) {
				if (t&1) s += "1";
				else s += "0";
				t /= 2;
			}
			while (s.length()<m) s += "0";
			reverse(s.begin(),s.end());
			cout<<s;
			cout<<endl;
		}
		for (int i=0; i<n; i++) ans = max(best[i],ans);
		printf("%d\n",ans);
	}

    return 0;

}

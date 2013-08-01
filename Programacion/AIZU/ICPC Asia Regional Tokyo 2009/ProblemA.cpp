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
vector<int> vf;
vector<int> vs;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&m) && n!=0) {
		vf.clear();
		for (int i=0; i<n; i++) {
			int a;
			scanf("%d",&a);
			vf.push_back(a);
		}
		vs.clear();
		for (int i=0; i<m; i++) {
			int a;
			scanf("%d",&a);
			vs.push_back(a);
		}
		sort(vf.begin(),vf.end());
		sort(vs.begin(),vs.end());
		reverse(vf.begin(),vf.end());
		reverse(vs.begin(),vs.end());
		int i = 0, j = 0;
		int ans = 0;
		while (i<n || j<m) {
			if (i==n) {
				ans += vs[j++];
			}
			else if (j==m) {
				ans += vf[i++];
			}
			else {
				if (vf[i]==vs[j]) {
					ans += vs[j++];
					i++;
				}
				else if (vf[i]>vs[j]) {
					ans += vf[i++];
				}
				else if (vs[j]>vf[i]) {
					ans += vs[j++];
				}
			}
		}
		printf("%d\n",ans);
	}

    return 0;

}

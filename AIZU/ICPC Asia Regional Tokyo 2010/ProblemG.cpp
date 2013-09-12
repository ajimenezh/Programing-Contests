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

int n,m,c;
vector<int> e[110];
vector<int> w[110];
int best[110][110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d",&n,&m,&c) && n!=0) {
		for (int i=0; i<n; i++) e[i].clear();
		for (int i=0; i<n; i++) w[i].clear();
		for (int i=0; i<m; i++) {
			int a,b,t;
			scanf("%d%d%d",&a,&b,&t);
			a--; b--;
			e[a].push_back(b);
			w[a].push_back(t);
		}
		int lo = 0;
		int hi = n-1;
		while (lo<hi) {
			int mi = (lo+hi)>>1;
			for (int i=0; i<n; i++) for (int j=0; j<=mi; j++) best[i][j] = 1000000000;
			priority_queue<pair<pair<int,int>, int> > q;
			best[0][mi] = 0;
			q.push(make_pair(make_pair(0,mi),0));
			bool good = 0;
			while (!q.empty()) {
				int h = q.top().first.second;
				int p = q.top().second;
				int d = best[p][h];
				q.pop();
				//if (d<-q.top().first.first) continue;
				if (p==n-1) {
					good = 1;
					break;
				}
				for (int i=0; i<e[p].size(); i++) {
					int x = e[p][i];
					int t = w[p][i];
					
					if (best[x][h]>d+t && d+t<=c) {
						best[x][h] = d+t;
						q.push(make_pair(make_pair(-d-t,h),x));
					}
					if (h>0 && best[x][h-1]>d) {
						best[x][h-1] = d;
						q.push(make_pair(make_pair(-d,h-1),x));
					}
				}
			}
			if (good) {
				hi = mi;
			}
			else lo = mi+1;
		}
		cout<<lo<<endl;
	}

    return 0;

}

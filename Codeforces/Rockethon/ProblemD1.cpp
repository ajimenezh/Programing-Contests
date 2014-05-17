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
int xv[1010], y1v[1010], y2v[1010];
int yh[1010], x1h[1010], x2h[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        xv[i] = x;
        y1v[i] = y; y2v[i] = y+l;
    }

    for (int i=0; i<m; i++) {
        int x,y,l;
        scanf("%d%d%d",&x,&y,&l);
        yh[i] = y;
        x1h[i] = x; x2h[i] = x+l;
    }

    int res = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (xv[i]<=x1h[j] || xv[i]>=x2h[j]) continue;
            if (yh[j]<=y1v[i] || yh[j]>=y2v[i]) continue;

            int x = xv[i];
            int y = yh[j];

            int l = min(y2v[i]-y, y-y1v[i]);
            l = min(l, x2h[j] - x);
            l = min(l, x - x1h[j]);
            res = max(res, l);
        }
    }
    cout<<res<<endl;

    return 0;

}

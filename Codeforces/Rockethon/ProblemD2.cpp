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
int xv[50010], y1v[50010], y2v[50010];
int yh[50010], x1h[50010], x2h[50010];
vector<pair<int,int> > v;
int top[50010];

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
        v.push_back(make_pair(x2h[i],i));
    }
    sort(v.begin(),v.end());
    top[m-1] = x1h[v[m-1].second];
    for (int j=m-2; j>=0; j--) top[j] = min(top[j+1], x1h[v[j].second]);

    int res = 0;
    for (int i=0; i<n; i++) {

        vector<pair<int,int> >::iterator it = lower_bound(v.begin(),v.end(),make_pair(xv[i],-1));
        int lower = top[(*it).second];

        while (it!=v.end()) {
            int j = (*it).second;

            if (x1h[(*it).second]>top[(*it).second]) break;

            if (xv[i]<=x1h[j] || xv[i]>=x2h[j]) {
                it++;
                continue;
            }
            if (yh[j]<=y1v[i] || yh[j]>=y2v[i]) {
                it++;
                continue;
            }

            int x = xv[i];
            int y = yh[j];

            int l = min(y2v[i]-y, y-y1v[i]);
            l = min(l, x2h[j] - x);
            l = min(l, x - x1h[j]);
            res = max(res, l);

            it++;

        }
    }
    cout<<res<<endl;

    return 0;

}

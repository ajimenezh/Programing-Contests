#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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
int v[100100];
int a[100010];
int b[100010];
vector<int> sum[100010];
map<pair<int,int>,int > res;
map<int,int> id;
pair<pair<int,int>,int> queries[100010];

void update(int x, int k) {
    for(;x<=n+10; x+=x&-x) v[x] += k;
}

int get(int x) {
    int s = 0;
    for(;x>=1;x-=x&-x) s += v[x];
    return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        printf("Case %d:\n",t);

        cin>>n>>m;

        for (int i=0; i<n; i++) v[i] = 0;
        id.clear();
        res.clear();
        for (int i=0; i<n; i++) sum[i].clear();

        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b,b+n);

        int cnt = 1;
        for (int i=0; i<n; i++) {
            if (i==0 || b[i]!=b[i-1]) id[b[i]] = cnt++;
        }

        for (int i=0; i<n; i++) a[i] = id[a[i]];

        for (int i=0; i<m; i++) {
            int l,r,h;
            scanf("%d%d%d",&l,&r,&h);
            map<int,int>::iterator it = id.upper_bound(h);
            it--;
            h = (*it).second;
            if (l>0) sum[l-1].push_back(h);
            sum[r].push_back(h);
            queries[i] = make_pair(make_pair(l,r),h);
        }

        for (int i=0; i<n; i++) {
            update(a[i],1);
            for (int j=0; j<sum[i].size(); j++) {
                int tmp = get(sum[i][j]);
                res[make_pair(i,sum[i][j])] = tmp;
            }
        }

        for (int i=0; i<m; i++) {
            int l = queries[i].first.first;
            int r = queries[i].first.second;
            int h = queries[i].second;

            int ans = res[make_pair(r,h)];
            if (l>0) ans -= res[make_pair(l-1,h)];

            printf("%d\n",ans);
        }
    }

    return 0;

}

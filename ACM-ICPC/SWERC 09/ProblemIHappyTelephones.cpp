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
int v[68000];
set<int> x;
map<int,int> id;
pair<int,int> intv[10010];

void build(int cur, int l, int r) {
    if (l==r) {
        v[cur] = 0;
        return;
    }
    v[cur] = 0;
    int h = (l+r)>>1;
    build(2*cur, l, h);
    build(2*cur+1, h+1,r);
}

void doit(int cur, int l, int r,int k) {
    if (l==r) {
        v[cur] += k;
        return;
    }
    v[cur] += k;
    int h = (l+r)>>1;
    doit(2*cur, l, h, v[cur]);
    doit(2*cur+1, h+1,r, v[cur]);

    v[cur] = max(v[2*cur],v[2*cur+1]);

}

void update(int cur, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        v[cur]++;
        return;
    }
    int h = (l+r)>>1;
    update(2*cur, l, h, lt, rt);
    update(2*cur+1, h+1,r,lt,rt);
}

int get(int cur, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) {
        return v[cur];
    }
    int h = (l+r)>>1;
    int tmp = 0;
    tmp = get(2*cur, l, h, lt, rt);
    tmp = max(tmp, get(2*cur+1, h+1,r,lt,rt));
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>m && n!=0) {
        for (int i=0; i<n; i++) {
            int u,v,xx,yy;
            scanf("%d%d%d%d",&u,&v,&xx,&yy);
            intv[i] = make_pair(xx,xx+yy);
            x.insert(xx);
            x.insert(xx+yy);
        }
        int cnt = 0;
        rep(it,x) {
            id[*it] = ++cnt;
        }
        for (int i=0; i<n; i++) {
            intv[i].first = id[intv[i].first];
            intv[i].second = id[intv[i].second];
        }
        int h = 0;
        while ((1<<h)<cnt) h++;
        cnt = 1<<h;
        build(1,1,cnt);
        for (int i=0; i<n; i++) {
            update(1,1,cnt,intv[i].first,intv[i].second);
        }
        doit(1,1,cnt,0);

        for (int i=0; i<m; i++) {
            int xx,yy;
            scanf("%d%d",&xx,&yy);
            set<int>::iterator it = upper_bound(x.begin(),x.end(),xx);
            if (it==x.end()) {
                printf("0\n");
                continue;
            }
            xx = *it;
            it = lower_bound(x.begin(),x.end(),xx+yy);
            while (*it>=yy+xx) {
                if (it==x.begin()){
                    printf("0\n");
                    continue;
                }
                it--;
            }
            yy = *it;

            printf("%d\n",get(1,1,cnt,id[xx],id[yy]));
        }
    }

    return 0;

}

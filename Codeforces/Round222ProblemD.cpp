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

int n;
vector<pair<pair<int,int>,int> > l[3*100010];
vector<pair<int,int> > v[3*100010];
pair<int,int> w[1100000];
int R;
pair<int,int> help[1100000];

void update(int id, int l, int r, int ll, int rr, int val) {
    if (l>rr || r<ll) return;
    if (l>=ll && r<=rr) {
        help[id] = make_pair(l,r);
        w[id].first += val;
        w[id].second = w[id].first;
        if (l!=r)  {
            w[id].second += max(w[2*id].second, w[2*id+1].second);
            if (w[2*id].second>w[2*id+1].second) {
                help[id] = help[2*id];
            }
            else if (w[2*id].second<=w[2*id+1].second) {
                if (help[2*id+1]==make_pair(0,0)) update(2*id+1,(l+r)/2+1,r,(l+r)/2+1,r,0);
                help[id] = help[2*id+1];
            }
        }
        return;
    }
    int h = (l+r)/2;
    update(2*id, l, h, l, h, w[id].first);
    update(2*id+1, h+1, r, h+1, r, w[id].first);
    update(2*id, l, h, ll, rr, val);
    update(2*id+1, h+1, r, ll, rr, val);
    w[id].first = 0;
    w[id].second = max(w[2*id].second, w[2*id+1].second);
    if (w[2*id].second>w[2*id+1].second) {
        help[id] = help[2*id];
    }
    else {
        help[id] = help[2*id+1];
    }
}

bool intersection(pair<int,int> a, pair<int,int> b) {
    if (b.first>a.second || b.second<a.first) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int ans = 0;
    for (int i=0; i<n; i++) {
        int ll,vv,r;
        scanf("%d%d%d",&ll,&vv,&r);
        R = max(R, r);
        v[vv].push_back(make_pair(i,r));
        l[ll].push_back(make_pair(make_pair(vv,r),i));
    }

    int ll;
    pair<int,int> p;
    for (int i=1; i<=R; i++) {
        for (int j=0; j<l[i].size(); j++) {
            update(1,1,R,l[i][j].first.first, l[i][j].first.second, +1);
        }
        if (w[1].second>ans) {
            ans = w[1].second;
            ll = i;
            p = help[1];
        }
        //cout<<i<<" "<<w[1].second<<endl;
        for (int j=0; j<v[i].size(); j++) {
            update(1,1,R,i,v[i][j].second,-1);
        }
    }

    cout<<ans<<endl;
    //cout<<ll<<" "<<p.first<<" "<<p.second<<endl;
    for (int i=1; i<=R; i++) {
        for (int j=0; j<l[i].size(); j++) {
            if (i<=ll && l[i][j].first.first>=ll && intersection(make_pair(p.first,p.first), l[i][j].first)) cout<<l[i][j].second+1<<" ";
        }
    }

    return 0;

}

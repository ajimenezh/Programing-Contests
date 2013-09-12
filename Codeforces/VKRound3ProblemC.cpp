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

#define MAXN 4*100010

int n;
int a[100010];
pair<int,pair<int,int> > val[MAXN];
pair<int,int> intv[100010];

void update(int id, int l, int r, int pos, int v) {
    if (pos>r || pos<l) return;
    if (l==r && l==pos) {
        val[id] = mp(v,mp(pos,pos));
        return;
    }

    int m = (l+r)/2;
    update(2*id,l,m,pos,v);
    update(2*id+1,m+1,r,pos,v);

    if (val[2*id].first<val[2*id+1].first) {
        val[id] = val[2*id+1];
    }
    else if (val[2*id].first > val[2*id+1].first) {
        val[id] = val[2*id];
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.second+1==val[2*id+1].second.first) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
        //cout<<val[2*id].second.first<<" "<<val[2*id+1].second.second<<endl;
        //cout<<id<<endl;
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.first==val[2*id+1].second.first) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.second==val[2*id+1].second.second) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
    }
    else {
        val[id] = val[2*id];
    }
    return;

}

void update_interval(int id, int l, int r, int lt, int rt, int v) {
    if (r<lt || l>rt) return;
    if (l>= lt && r<=rt) {
        val[id] = mp(v,mp(lt,rt));
        return;
    }

    int m = (l+r)/2;
    update_interval(2*id,l,m,lt,rt,v);
    update_interval(2*id+1,m+1,r,lt,rt,v);

    //cout<<id<<" "<<val[2*id].first<<" "<<val[2*id+1].first<<endl;
    //cout<<val[2*id].second.first<<" "<<val[2*id].second.second<<endl;
    //cout<<val[2*id+1].second.first<<" "<<val[2*id+1].second.second<<endl;

    if (val[2*id].first<val[2*id+1].first) {
        val[id] = val[2*id+1];
    }
    else if (val[2*id].first > val[2*id+1].first) {
        val[id] = val[2*id];
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.second+1==val[2*id+1].second.first) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
        //cout<<val[2*id].second.first<<" "<<val[2*id+1].second.second<<endl;
        //cout<<id<<endl;
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.first==val[2*id+1].second.first) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
    }
    else if (val[2*id].first==val[2*id+1].first && val[2*id].second.second==val[2*id+1].second.second) {
        val[id] = mp(val[2*id].first,mp(val[2*id].second.first, val[2*id+1].second.second));
    }
    else {
        val[id] = val[2*id];
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int k = 0;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);

    for (int i=0; i<MAXN; i++) val[i] = make_pair(0,mp(-1,-1));

    for (int i=0; i<n; i++) {
        update(1,1,n,i+1,a[i]);
    }

    while (true) {
        pair<int,pair<int, int> > p = val[1];
        if (p.first==0) break;
        //cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
        //int ds; cin>>ds;

        int l = p.second.first, r = p.second.second;
        int dist = p.first;
        if (l>1) dist = min(dist,abs(p.first - a[l-2]));
        if (r<n) dist = min(dist,abs(p.first - a[r]));

        for (int i=0; i<dist; i++) {
            intv[k++] = mp(l,r);
        }

        //cout<<dist<<" "<<a[r]<<" "<<a[l-2]<<endl;
        update_interval(1,1,n,l,r,p.first-dist);
    }

    cout<<k<<endl;
    for (int i=0; i<k; i++) printf("%d %d\n",intv[i].first, intv[i].second);

    return 0;

}

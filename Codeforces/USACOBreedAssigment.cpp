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

int type[16];
int n,k;
vector<int> e[16];
vector<pair<int,int> > d;

int rec(int id, int f) {
    if (id == n) {
        for (int i=0; i<d.size(); i++) {
            if (type[d[i].first]==type[d[i].second]) return 0;
        }
        return 1;
    }
    //cout<<id<<" "<<f<<endl;
    type[id] = f;
    rep(it,e[id]) {
        if (type[*it]!=type[id] && !(type[*it]==-1 || type[id]==-1)) return 0;
        type[*it] = type[id];
    }
    if (f==-1) return 0;
    int t;
    for (int i=0; i<n; i++) {
        if (type[i]==-1) {
            t = 0;
            t += rec(i,f);
            rec(i,-1);
            t += rec(i,(1+f)%3 + 1);
            rec(i,-1);
            t += rec(i,(2+f)%3 + 2);
            rec(i,-1);
            return t;
        }
    }
    return rec(n,-1);
}

int main() {

    freopen("assign.in","r",stdin);
    freopen("assign.out","w",stdout);

    cin>>n>>k;
    for (int i=0; i<k; i++) {
        char c;
        cin>>c;
        if (c=='S') {
            int a,b;
            cin>>a>>b;
            a--; b--;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        else {
            int a,b;
            cin>>a>>b;
            a--; b--;
            d.push_back(make_pair(a,b));
        }
    }
    for (int i=0; i<n; i++) type[i] = -1;
    int res = rec(0,1);
    rec(0,-1);
    res += rec(0,2);
    rec(0,-1);
    res += rec(0,3);

    cout<<res;

    return 0;

}

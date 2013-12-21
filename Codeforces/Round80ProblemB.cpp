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
vector<int> e[110];
int par[110];
int rk[110];

int _find(int a) {
    if (a==par[a]) return a;
    par[a] = _find(par[a]);
    return par[a];
}

bool _merge(int a, int b) {
    a = _find(a);
    b = _find(b);
    if (a==b) return false;
    if (rk[a]>rk[b]) {
        rk[b]++;
        par[a] = b;
    }
    else {
        rk[a]++;
        par[b] = a;
    }
    return true;
}

vector<pair<int,int> > v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
        v.push_back(make_pair(x,y));
    }

    if (n<3) cout<<"NO";
    else {
        int k = 0;
        for (int i=0; i<n; i++) par[i] = i;
        for (int i=0; i<m; i++) {
            if (!_merge(v[i].first,v[i].second)) k++;
        }
        if (k==0 || k>1) cout<<"NO";
        else {
            set<int> all;
            for (int i=0; i<n; i++) all.insert(_find(i));
            if (all.size()>1) cout<<"NO";
            else {
                cout<<"FHTAGN!"<<endl;
            }
        }
    }

    return 0;

}

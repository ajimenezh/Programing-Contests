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

int n,k,m;
int par[10010];
int si[10010];
vector<int> bridges[10010];

int _find(int p) {
    if (par[p]==p) return p;
    par[p] = _find(par[p]);
    return par[p];
}
void _union(int a, int b) {
    a = _find(a);
    b = _find(b);
    if (a==b) return;
    if (si[a]>si[b]) {
        par[a] = b;
        si[b]++;
    }
    else {
        par[b] = a;
        si[a]++;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>m;
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<n; i++) si[i] = 0;
    for (int i=0; i<k; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        _union(a,b);
    }
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        if (_find(a)!=_find(b)) {
            bridges[a].push_back(b);
            bridges[b].push_back(a);
        }
    }

    int t = 0;
    for (int i=0; i<n; i++) if (par[i]==i) t++;
    cout<<(t-1)<<endl;

    return 0;

}

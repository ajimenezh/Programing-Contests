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
int par[205];
int rk[205];
vector<int> v;

int get(int a) {
    if (par[a]==a) return a;
    par[a] = get(par[a]);
    return par[a];
}

void connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return;
    if (rk[a]>rk[b]) {
        rk[b]++;
        par[a] = b;
    }
    else {
        rk[a]++;
        par[b] = a;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<2*n; i++) par[i] = i;
    for (int i=0; i<m; i++) {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        a--; b--;
        if (t==1) {
            connect(a,b);
            connect(a+n,b+n);
        }
        else {
            connect(a+n,b);
            connect(a,b+n);
        }
    }
    for (int i=0; i<n; i++) {
        if (get(i)==get(i+n)) {
            cout<<"Impossible";
            return 0;
        }
    }
    for (int i=0; i<n; i++) {
        if (get(i)!=get(0) && get(i+n)!=get(0)) {
            connect(0,i);
        }
    }
    for (int i=0; i<n; i++) if (get(i)==get(0)) v.push_back(i+1);
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";


    return 0;

}

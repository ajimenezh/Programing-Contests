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

int n,m,k;
int c[510][510];
int cc[510];
int sum[510];
int par[100010];
int rk[100010];

int find(int p) {
    if (par[p]==p) return p;
    par[p] = find(par[p]);
    return par[p];
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u==v) return;
    if (rk[u]>rk[v]) {
        par[u] = v;
        rk[v]++;
    }
    else {
        par[v] = u;
        rk[u]++;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<k; i++) scanf("%d", cc+i);
    sum[0] = cc[0];
    for (int i=1; i<k; i++) sum[i] = sum[i-1] + cc[i];
    vector<int> w;
    for (int i=0; i<k; i++) w.push_back(sum[i]);
    for (int i=0; i<k; i++) w[i]++;
    for (int i=0; i<k; i++) for (int j=0; j<k; j++) c[i][j] = 1000000000;
    for (int i=0; i<k; i++) if (cc[i]==1) c[i][i] = 0;
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<n; i++) rk[i] = 0;
    for (int i=0; i<m; i++) {
        int u, v ,x;
        scanf("%d%d%d", &u, &v, &x);
        int t1 = upper_bound(w.begin(), w.end(), u) - w.begin();
        int t2 = upper_bound(w.begin(), w.end(), v) - w.begin();
        c[t1][t2] = min(c[t1][t2], x);
        c[t2][t1] = c[t1][t2];
        if (x==0) merge(u-1,v-1);
    }

    for (int p=0; p<k; p++) {
        for (int i=0; i<k; i++) {
            for (int j=0; j<k; j++) {
                if (c[i][j]>c[i][p]+c[p][j]) {
                    c[i][j] = c[i][p]+c[p][j];
                }
            }
        }
    }

    bool bad = 0;
    for (int i=0; i<k; i++) {
        if (c[i][i]!=0) {
            bad = 1;
            break;
        }
    }
    if (bad) cout<<"No";
    else {
        int i = 0;
        int tot = 0;
        int j = 0;
        while (i<n && tot<cc[j] && j<k) {
            if (i!=0 && tot>0 && find(i)!=find(i-1)) {
                bad = 1;
                break;
            }
            i++;
            tot++;
            if (tot==cc[j]) {
                j++;
                tot = 0;
            }
        }
        //for (int i=0; i<n; i++) cout<<find(i)<<" "; cout<<endl;
        if (bad) cout<<"No\n";
        else {
            cout<<"Yes\n";
            for (int i=0; i<k; i++) {
                for (int j=0; j<k; j++) {
                    if (c[i][j]==1000000000) c[i][j] = -1;
                    cout<<c[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
    }

    return 0;

}

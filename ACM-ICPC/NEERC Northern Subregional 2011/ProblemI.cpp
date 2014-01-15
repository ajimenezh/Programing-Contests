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
int a[18][18];
int dp[1<<18][18], pre[1<<18][18];
int pre2[1<<18][18];
int dp2[1<<18][18];
int t[1<<18];
int p[18][18];
priority_queue<pair<int,pair<int,int> > > q;

bool check(int MAX) {
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) dp2[i][j] = 1000000000;
    }
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if (dp[i][j]!=-1 && dp[i][j]<=MAX) {
                dp2[i][0] = 0;
            }
        }
    }

    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if (dp2[i][j]>=1000000000 || ((1<<j)&i)==0) continue;
            if (i==(1<<n)-1 && dp2[i][j]<=MAX) return true;
            for (int k=0; k<n; k++) {
                if (dp2[i|(1<<k)][k] > dp2[i][j] + a[j][k] && dp2[i][j] + a[j][k]<=MAX) {
                    dp2[i|(1<<k)][k] = dp2[i][j] + a[j][k];
                    pre2[i|(1<<k)][k] = j;
                }
            }
        }
    }

    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j] = 100000000;
    for (int i=0; i<m; i++) {
        int u,v,z;
        scanf("%d%d%d",&u,&v,&z);
        u--; v--;
        a[u][v] = min(a[u][v],z);
        a[v][u] = a[u][v];
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i][j]>a[i][k]+a[k][j]) {
                    a[i][j] = a[i][k]+a[k][j];
                    p[i][j] = k;
                }
            }
        }
    }

    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) dp[i][j] = 1000000000;
    } cout<<"waiting"<<endl;

    dp[1][0] = 0;

    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if (dp[i][j]>=1000000000 || ((1<<j)&i)==0) continue;
            for (int k=0; k<n; k++) {
                if (a[j][k]>=100000000 || (1<<k)&i) continue;
                if (dp[i|(1<<k)][k] > dp[i][j] + a[j][k]) {
                    dp[i|(1<<k)][k] = dp[i][j] + a[j][k];
                    pre[i|(1<<k)][k] = j;
                }
            }
        }
    } cout<<"hecho"<<endl;


    int lo = 1;
    int hi = 20000;

    while (lo<hi) {
        int mi = (lo+hi)/2;

        if (!check(mi)) lo = mi+1;
        else hi = mi;
    }
    check(lo);
    cout<<lo<<endl;

    int p = -1;
    int best = 100000000;
    for (int i=0; i<n; i++) {
        if (best>dp2[(1<<n)-1][i]) {
            best = dp2[(1<<n)-1][i];
            p = i;
        }
    }

    vector<int> path;
    int mask = (1<<n)-1;
    int mask2 = 0;
    while (p!=0) {
        path.push_back(p);
        int tmp = p;
        p = pre2[mask][p];
        mask -= (1<<tmp);
        mask2 += (1<<tmp);
    }
    path.push_back(0);
    cout<<path.size()-1;
    reverse(path.begin(),path.end());
    for (int i=0; i<path.size(); i++) cout<<" "<<path[i]+1; cout<<endl;
    path.clear();

    p = -1;
    best = 1000000;
    for (int i=0; i<(1<<n); i++) {
        if ((i|mask2)==(1<<n)-1) { //cout<<i<<" "<<mask2<<endl;
            for (int j=0; j<n; j++) { //cout<<dp[i][j]<<endl;
                if (dp[i][j]!=-1 && dp[i][j]<best) {
                    p = j;
                    best = dp[i][j];
                    mask = i;

                    //cout<<p<<" "<<mask<<" "<<mask2<<" "<<best<<endl;
                }
            }
        }
    }

    while (p!=0) {
        path.push_back(p);
        int tmp = p;
        p = pre[mask][p];
        mask -= (1<<tmp);
    }
    path.push_back(0);
    cout<<path.size()-1;
    reverse(path.begin(),path.end());
    for (int i=0; i<path.size(); i++) cout<<" "<<path[i]+1; cout<<endl;
    path.clear();

    return 0;

}

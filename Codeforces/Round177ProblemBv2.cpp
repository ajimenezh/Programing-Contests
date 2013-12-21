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

int n,k;
const int mod = 1000000007;
int p[8];
bool vis[8];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    dfs(p[x]);
    return;
}

int f(int t) {
    if (t==0) {
        bool bad = 0;
        //if (p[0]==0) bad = 1;
        for (int i=0; i<k; i++) {
            for (int j=0; j<k; j++) vis[j] = 0;
            dfs(p[i]);
            if (!vis[0]) {
                bad = 1;
                break;
            }
        }
        if (!bad) return 1;
        else return 0;
    }

    int tmp = 0;
    for (int i=0; i<k; i++) {
        p[k-t] = i;
        tmp += f(t-1);
    }
    return tmp;
}

int v[] = {0,1,2,9,64,625,7776,117649,2097152};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    long long res = 1;
    for (int i=1; i<=(n-k); i++) res = (res*(long long)(n-k))%mod;

    res = (res*v[k])%mod;

    cout<<res<<endl;

    return 0;

}

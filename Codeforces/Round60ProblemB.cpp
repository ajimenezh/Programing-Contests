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

int vis[1010][2020];
int next[1010][2020];
int n;
int a[1010];
int v[] = {1,10,100,1000};

int dfs(int i, int last) {
    if (i==n) return 1;
    if (vis[i][last]>=0) return vis[i][last];

    vis[i][last] = 1;

    if (a[i]>=1000 && a[i]<=2011 && a[i]>=last) {
        int t = dfs(i+1, a[i]);
        if (t==1) {
            next[i][last] = a[i];
            return 1;
        }
    }

    for (int s=0; s<4; s++) {
        for (int j=0; j<10; j++) {
            int k = a[i];
            k = k - ((k/v[s])%10)*v[s];
            k = k + v[s]*j;
            if (k>=1000 && k<=2011 && k>=last) {
                int t = dfs(i+1, k);
                if (t==1) {
                    next[i][last] = k;
                    return 1;
                }
            }
        }
    }

    vis[i][last] = 2;
    return 2;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<=n; i++) for (int j=0; j<2015; j++) vis[i][j] = -1;

    dfs(0,0);

    if (vis[0][0]==2) cout<<"No solution";
    else {
        int p = 0;
        int last = 0;
        while (p<n) {
            cout<<next[p][last]<<endl;
            last = next[p][last];
            p++;
        }
    }

    return 0;

}

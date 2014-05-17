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

int t,n,m;
int a[101][101];
int b[101][101];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&a[i][j]);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) b[i][j] = 200;
        for (int i=0; i<n; i++) {
            int c = 0;
            for (int j=0; j<m; j++) c = max(c,a[i][j]);
            for (int j=0; j<m; j++) b[i][j] = min(b[i][j],c);
        }
        for (int i=0; i<m; i++) {
            int c = 0;
            for (int j=0; j<n; j++) c = max(c,a[j][i]);
            for (int j=0; j<n; j++) b[j][i] = min(b[j][i],c);
        }
        bool bad = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a[i][j]!=b[i][j]) {
                    bad = 1;
                }
            }
        }
        if (bad) printf("Case #%d: NO\n",tt+1);
        else printf("Case #%d: YES\n",tt+1);
    }

    return 0;

}

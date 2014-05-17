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

int n,m;
char buf[1010][1010];
int p[1010];
int cur[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%s", &buf[i]);
    bool bad = 0;
    for (int i=0; i<n; i++) {
        bool found = 0;
        for (int j=0; j<m; j++) {
            if (buf[i][j]=='G') {
                p[i] = j;
                found = 1;
            }
            if (buf[i][j]=='S') {
                if (!found) bad = 1;
                cur[i] = j;
            }
        }
    }
    if (bad) {
        cout<<-1;
    }
    else {
        int k = 0;
        while (true) {
            int tot = 1000000;
            for (int i=0; i<n; i++) if (cur[i]!=p[i]) {
                tot = min(tot, cur[i] - p[i]);
            }
            if (tot==1000000) break;
            k++;
            for (int i=0; i<n; i++) if (cur[i]!=p[i]) cur[i] -= tot;
        }
        cout<<k<<endl;
    }

    return 0;

}

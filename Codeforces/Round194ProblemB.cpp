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
int a[1010][1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x-1][y-1] = 1;
    }

    int t1 = 0, t2 = 0;
    bool flag1, flag2;
    for (int i=1; i<n-1; i++) {
        bool good = 1;
        for (int j=0; j<n; j++) {
            if (a[i][j]) {
                good = 0;
                break;
            }
        }
        if (good) t1++;
        if (i==n/2) flag1 = good;
    }
    for (int i=1; i<n-1; i++) {
        bool good = 1;
        for (int j=0; j<n; j++) {
            if (a[j][i]) {
                good = 0;
                break;
            }
        }
        if (good) t2++;
        if (i==n/2) flag2 = good;
    }

    int ans = t1+t2;
    if (n%2==1) {
        if (flag1 && flag2) ans--;
    }

    cout<<ans;

    return 0;

}

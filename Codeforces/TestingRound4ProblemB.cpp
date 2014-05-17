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
int d[10][301][301];
int f[10][301][301];

void mul(int a[301][301], int b[301][301], int c[301][301]) {
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j] = -10000000;
    for (int i=0; i<n; i++) a[i][i] = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                a[i][j] = max(a[i][j], b[i][k] + c[k][j]);
            }
        }
    }
}

bool check(int a[301][301]) {
    for (int i=0; i<n; i++) if (a[i][i]>0) return 1;
    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[0][i][j] = -10000000;
    for (int i=0; i<n; i++) d[0][i][i] = 0;
    for (int i=0; i<m; i++) {
        int a,b;
        int c1,c2;
        scanf("%d%d%d%d",&a,&b,&c1,&c2);
        a--; b--;
        d[0][a][b] = c1;
        d[0][b][a] = c2;
    }

    for (int i=1; i<=9; i++) {
        mul(d[i],d[i-1],d[i-1]);
    }

    if (!check(d[9])) {
        cout<<"0"<<endl;
        return 0;
    }

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) f[0][i][j] = -10000000;
    for (int i=0; i<n; i++) f[0][i][i] = 0;
    int k = 0;
    int ans = 0;
    for (int i=9; i>=0; i--) {
        mul(f[k+1],d[i],f[k]);
        if (!check(f[k+1])) {
            k++;
            ans += 1<<i;
        }
    }


    cout<<ans+1<<endl;

    return 0;

}

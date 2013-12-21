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

int n;
int a[201];
bool good;
bool vis[201];

void dfs(int m) {
    if (vis[m]) return;
    if (m==0) good = 1;
    vis[m] = 1;
    for (int i=1; i<=m; i++) {
        if (i>n || n-i+m>2*n-1) continue;
        else dfs((m-i)+(n-i));
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<(2*n-1); i++) cin>>a[i];
    int k = 0;
    for (int i=0; i<(2*n-1); i++) if (a[i]<0) k++;
    dfs(k);
    for (int i=0; i<(2*n-1); i++) a[i] = abs(a[i]);
    sort(a,a+2*n-1);
    if (!good) a[0] = -a[0];

    int sum = 0;
    for (int i=0; i<(2*n-1); i++) sum += a[i];
    cout<<sum<<endl;

    return 0;

}

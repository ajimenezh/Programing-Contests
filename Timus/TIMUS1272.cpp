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

int n,m,c;

int par[100010];

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

void connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return;
    par[a] = b;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>c;
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        connect(a-1,b-1);
    }
    int cnt = 0;
    for (int i=0; i<n; i++) if (par[i]==i) cnt++;
    for (int i=0; i<c; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
    }

    cout<<cnt-1;

    return 0;

}

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

int n;
int x[500010];
bool vis[1000010];
int m;
int all[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d", x+i);
        vis[x[i]] = 1;
    }

    int t = 0;
    for (int i=0; i<n; i++) {
        if (!vis[1000000-x[i]+1]) all[m++] = 1000000-x[i]+1;
        else t++;
    }
    t /= 2;
    for (int i=1; i<=1000000 && t>0; i++) {
        if (!vis[i] && !vis[1000000-i+1]) {
            t--;
            all[m++] = i;
            all[m++] = 1000000-i+1;
        }
    }

    printf("%d\n", m);
    for (int i=0; i<m; i++) printf("%d ", all[i]);

    return 0;

}

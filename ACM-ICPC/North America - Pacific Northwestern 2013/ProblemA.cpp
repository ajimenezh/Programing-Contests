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


int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        int n, d;
        scanf("%d%d",&n,&d);
        int ans = 0;
        for (int i=0; i<n; i++) {
            int v,f,c;
            scanf("%d%d%d",&v,&f,&c);
            if (d*c<=v*f) ans++;
        }
        cout<<ans<<"\n";
    }

    return 0;

}

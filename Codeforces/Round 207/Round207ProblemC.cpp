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
int last[300010];
int next[300010];
int ans[300010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<=n+1; i++) last[i] = i-1;
    for (int i=0; i<=n+1; i++) next[i] = i+1;

    for (int i=0; i<m; i++) {
        int l,r,x;
        cin>>l>>r>>x;
        for (int j=next[last[l]]; j<=r;) { cout<<j<<endl;
            if (j!=x && ans[j]==0) ans[j] = x;
            last[j] = last[l];
            int tmp = next[j];
            next[j] = next[r];
            j = tmp;
        }
    }

    for (int i=0; i<n; i++) cout<<ans[i+1]<<" ";

    return 0;

}

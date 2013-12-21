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

int a[100010];
int sum[100010];
int w[100010][450];
vector<int> v;
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) {
        if (a[i]<=n) sum[a[i]]++;
    }
    for (int i=1; i<=n; i++) {
        if (sum[i]>=i) v.push_back(i);
    }
    for (int i=0; i<v.size(); i++) {
        for (int j=1; j<=n; j++) {
            w[j][i] = w[j-1][i] + (a[j-1]==v[i]);
        }
    }
    for (int i=0; i<m; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        int cnt = 0;
        for (int j=0; j<v.size(); j++) {
            if (w[r][j] - w[l-1][j]==v[j]) cnt++;
        }
        printf("%d\n",cnt);
    }

    return 0;

}

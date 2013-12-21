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

#define tm T

int n,m;
int t[100010], tm[100010], x[100010], c[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d%d%d%d",t+i,tm+i,x+i,c+i);
    long long res = 0;
    for (int i=0; i<n; i++) {
        long long tmp = c[i];
        int tt = t[i]+m;
        if (tt>tm[i]) tmp += (long long )m*x[i];
        if (tt>tm[i]) {
            tt = tm[i]-t[i];
            if (tt<=0);
            else {
                int k = (m-1)/tt+1;
                tmp = min(tmp, (long long)k*c[i]);
            }
        }
        res += tmp;
    }

    cout<<res<<endl;

    return 0;

}

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

int n,k,p;
vector<int> e[100010];
int tot[100010];

int dfs(int p, int pre, int depth) {
    tot[depth]++;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=pre) dfs(e[p][i], p, depth+1);
}

long long sum[100010];
long long sumk[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>p;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0,-1,0);

    int res = 0;
    tot[0] = 0;

    for (int i=1; i<n; i++) {
        sum[i] = sum[i-1] + tot[i];
        sumk[i] = sumk[i-1] + (long long)tot[i]*(n-i);
    }

    for (int i=0; i<n; i++) {
        int kk = k;
        long long pp = p;
        int tmp = 0;

        //cout<<i<<" "<<tot[i]<<endl;

        int hi = i;
        int lo = 0;

        while (lo<hi) {
            int mi = (lo+hi)>>1;

            long long tmp = (sumk[i] - sumk[mi]) - (long long)(n-i)*(sum[i] - sum[mi]);

            if (tmp>p || (sum[i] - sum[mi])>k) lo = mi+1;
            else hi = mi;
        }

        //cout<<lo<<endl;

        tmp = (sum[i] - sum[lo]);

        pp -= (sumk[i] - sumk[lo]) - (long long)(n-i)*(sum[i] - sum[lo]);
        kk -= (sum[i] - sum[lo]);


        if (lo!=i) {
            long long a = min((long long)min(kk, tot[lo]), min(pp/(i-(lo)), (long long)tot[lo]));
            tmp = tmp+a;
        }
        else {
            int a = min(kk, tot[lo]);
            tmp = tmp+a;
        }

        res = max(res, tmp);

    }

    cout<<res<<endl;

    return 0;

}

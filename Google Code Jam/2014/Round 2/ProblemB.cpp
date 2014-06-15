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
int a[1010];
pair<int,int> b[1010];
int dp[1010][1010];

int solve(int i, int t) {
    if (i==n) return 0;
    if (dp[i][t]>=0) return dp[i][t];

    int tmp = min(solve(i+1,t+1) + abs(b[i].second-t), solve(i+1, t) + abs(b[i].second-(n-1-(i-t))));
    dp[i][t] = tmp;

    return tmp;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n;
        for (int i=0; i<n; i++) scanf("%d", &a[i]);

        for (int i=0; i<n; i++) b[i] = make_pair(a[i], i);
        sort(b, b+n);

        long long res2 = 0;

        int lo = 0, hi = n-1;
        for (int i=0; i<n; i++) {
            for (int j=lo; j<=hi; j++) b[j] = make_pair(a[j], j);
            sort(b+lo, b+hi+1);
            if (b[lo].second-lo<hi-b[lo].second) {
                for (int j=b[lo].second; j>lo; j--) {
                    swap(a[j],a[j-1]);
                    res2++;
                }
                lo++;
            }
            else {
                for (int j=b[lo].second; j<hi; j++) {
                    swap(a[j],a[j+1]);
                    res2++;
                }
                hi--;
            }
        }

        //for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;

        printf("Case #%d: %d\n", tt+1, res2);
        //cout<<res2/2<<endl;

    }


    return 0;

}

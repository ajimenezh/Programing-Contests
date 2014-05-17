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

const int mod = 1000000007;

int t;
int x[1000010];
int y[1000010];
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n-1; i++) scanf("%d", x+i);
        for (int i=0; i<m-1; i++) scanf("%d", y+i);

        long long sumx = 0;
        long long sumy = 0;
        sort(x,x+(n-1));
        reverse(x,x+(n-1));
        sort(y,y+(m-1));
        reverse(y,y+(m-1));
        for (int i=0; i<n-1; i++) sumx += x[i];
        for (int i=0; i<m-1; i++) sumy += y[i];

        int i=0, j=0;
        long long res = 0;
        while (i<n-1 || j<m-1) {
            if (i==n-1) {
                res += (y[j]*(i+1))%mod;
                if (res>=mod) res -= mod;
                j++;
                continue;
            }
            if (j==m-1) {
                res += (x[i]*(j+1))%mod;
                if (res>=mod) res -= mod;
                i++;
                continue;
            }
            if (x[i]>y[j]) {
                res += (x[i]*(j+1))%mod;
                sumx -= x[i];
                if (res>=mod) res -= mod;
                i++;
            }
            else {
                res += (y[j]*(i+1))%mod;
                sumy -= y[j];
                if (res>=mod) res -= mod;
                j++;
            }
        }
        cout<<res<<"\n";
    }

    return 0;

}

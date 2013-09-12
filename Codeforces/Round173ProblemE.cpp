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

long long x,y;
int n;
long long a[100010];
int next[8000010][2];
long long res;
int id;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d",a+i);
    for (int i=0; i<n; i++) x = x ^a[i];
    for (int i=0; i<=n; i++) {
        int r = 0;
        for (int j=61; j>=0; j--) {
            int t = ((1LL<<j) & y) == 1LL<<j;
            if (!next[r][t]) {
                next[r][t] = ++id;
                r = id;
            }
            else
            {
                r = next[r][t];
            }
        }
        long long m = 0;
        r = 0;
        for (int j=61; j>=0; j--) {
            int t = ((1LL<<j) & x) == 1LL<<j;
            //cout<<i<<" "<<t<<" "<<r<<" "<<x<<endl;
            if (!next[r][1-t]) {
                r = next[r][t];
            }
            else
            {
                r = next[r][1-t];
                m += 1LL<<j;
            }
            if (r==0) break;
        }
        //cout<<m<<endl;
        res = max(m,res);
        if (i==n) break;
        x = x^a[i];
        y = y^a[i];
    }

    cout<<res;

    return 0;

}

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

#define MAXN 100010

int k;
long long n;
long long a,b,c,r;
long long v[MAXN];
long long p[2*MAXN];
long long v2[MAXN];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for (int tt=0; tt<t; tt++) {
        scanf("%I64d%d",&n,&k);
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&r);

        v[0] = a;
        for (int i=1; i<k; i++) {
            v[i] = ( (b*v[i-1])%r + c)%r;
        }

        for (int i=0; i<=2*k; i++) p[i] = 0;
        for (int i=0; i<k; i++) if (v[i]<2*MAXN) p[v[i]]++;

        int m = 0;

        for (int i=0; i<=k; i++) {
            if (i>0 && i<k && v[i-1]<=2*k) {
                p[v[i-1]]--;
                if (v[i-1]<m && p[v[i-1]]==0) {
                    v2[i] = v[i-1];
                    p[v[i-1]] = 1;
                    continue;
                }
            }

            while (p[m]>0) m++;
            v2[i] = m;
            p[m++] = 1;
        }

        //for (int i=0; i<k; i++) cout<<v[i]<<" "; cout<<endl;
        //for (int i=0; i<=k; i++) cout<<v2[i]<<" "; cout<<endl;

        long long res;
        if (n<k) {
            res = v[n];
        }
        else {
            res = v2[int((n-(long long)k)%(long long)(k+1) )-1];
        }
        printf("Case #%d: %I64d\n",tt+1,res);
    }


    return 0;

}

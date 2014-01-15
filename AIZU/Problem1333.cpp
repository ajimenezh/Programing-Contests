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

int w,n;
int v[50100];
int f[50100];

bool check(int x) {
    for(int i=0; i<=n+1; i++) f[i] = 0;
    int l = 1, r = 1;
    int suml = v[0], sumr = v[0];
    f[0] = 1;
    f[1] = -1;

    for (int i=0; i<n; i++) {
        f[i+1] += f[i];
        if (f[i]>0) {
            while (l<n && suml<=w) {
                suml += 1 + v[l];
                l++;
            }
            while (r<n && sumr<w) {
                sumr += x + v[r];
                r++;
            }
            f[l]--;
            f[r]++;
            if (l==n && suml<=w) f[n]++;
        }
        suml -= 1+v[i];
        sumr -= x+v[i];
    }
    return f[n]>0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>w>>n && w!=0) {
        for (int i=0; i<n; i++) scanf("%d",v+i);

        int lo = 1;
        int hi = w;
        while (lo<hi) {
            int mi = (lo+hi)/2;
            if (check(mi)) hi = mi;
            else lo = mi+1;
        }

        cout<<lo<<"\n";
    }

    return 0;

}

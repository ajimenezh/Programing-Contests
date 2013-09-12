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

int n;
int a[100010];
int b[100010];
long long v[100010];
long long c1[100010];
int c2[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) b[i] = a[i];
    int k = 0;
    sort(b,b+n);
    for (int i=1; i<n; i++) if (b[i]!=b[k]) b[++k] = b[i];

    for (int i=0; i<n; i++) {
        int l = 0;
        int r = k;
        while (l<r) {
            int mi = (l+r)/2;
            if (a[i]<=b[mi]) r = mi;
            else l = mi+1;
        }
        a[i] = r+1;
    }


    for (int i=0; i<=k; i++) v[i] = 0;

    for (int i=n-1; i>=0; i--) {
        int idx = a[i]-1;
        int t = 0;
        while (idx>0) {
            t += v[idx];
            idx -= idx & -idx;
        }
        idx = a[i];
        while (idx<=k) {
            v[idx] += 1;
            idx += idx & -idx;
        }
        c1[i] = t;
    }

    for (int i=0; i<=k; i++) v[i] = 0;

    for (int i=0; i<n; i++) {
        int idx = a[i];
        idx = k - idx + 1;
        int t = 0;
        while (idx>0) {
            t += v[idx];
            idx -= idx & -idx;
        }
        idx = k - a[i] + 2;
        //cout<<idx<<" "<<a[i]<<endl;
        while (idx<=k) {
            v[idx] += 1;
            idx += idx & -idx;
        }
        c2[i] = t;
    }

    long long res = 0;

    for (int i=0; i<n; i++) res += c1[i]*c2[i];

    cout<<res<<endl;


    return 0;

}

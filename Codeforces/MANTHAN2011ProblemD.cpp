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

#define MAXN 1000010

int n;
int a[MAXN];
int m[MAXN];
int p[MAXN];
int l;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) m[a[i]] = i+1;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) a[i] = m[a[i]];

    l = 0;
    for (int i=0; i<n; i++) {
        int lo = 0;
        int hi = l-1;
        while (lo<hi-1) {
            int mi = (lo+hi)/2;
            if (a[i]<a[p[mi]]) lo = mi;
            else hi = mi;
        }
        while (lo<l && a[i]<a[p[lo+1]]) lo++;
        //cout<<lo<<" "<<l<<endl;
        //cout<<a[i]<<" "<<a[p[lo+1]]<<endl;
        if (lo==l || a[i]>a[p[lo+1]]) {
            l = max(l,lo+1);
            p[lo+1] = i;
        }
        //cout<<l<<endl;
        //for (int j=0; j<l; j++) cout<<p[j]<<" "; cout<<endl;
    }

    cout<<l<<endl;

    return 0;

}

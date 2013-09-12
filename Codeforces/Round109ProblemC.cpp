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

#define MAXN 1000005

long long p[MAXN];
int n;
int m;
long long e1[MAXN], e2[MAXN];

long long solve(long long *v) {
    long long tmp = 0;
    long long j;
    sort(v,v+n);
    for (long long i=0; i<n; i=j) {
        for (j=i; j<n && v[i]==v[j]; j++);
        tmp += (j-i)*(j-i-1LL)/2LL;
    }
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    p[0] = 29LL;
    for (int i=1; i<=n; i++) p[i] = p[i-1]*p[0];
    for (int i=0; i<=n; i++) e2[i] = p[i];

    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e1[a] += p[b]; e2[a] += p[b];
        e1[b] += p[a]; e2[b] += p[a];
    }

    long long res = 0;

    res += solve(e1);
    res += solve(e2);

    printf("%I64d",res);

    return 0;

}

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

int n,m,a;
int b[100010];
int p[100010];
long long sum;

bool check(int k) {
    int tmp = a;
    sum = 0;
    for (int i=n-k; i<n; i++) {
        int j = i-(n-k);
        if (j==m) return false;
        if (p[j]>b[i]) {
            if (tmp < p[j]-b[i]) return false;
            tmp -= p[j]-b[i];
        }
        sum += p[j];
    }
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>a;
    for (int i=0; i<n; i++) scanf("%d",b+i);
    for (int i=0; i<m; i++) scanf("%d",p+i);

    sort(p,p+m);
    sort(b,b+n);

    int lo = 0;
    int hi = n;
    while (lo<hi) {
        int mi = (lo+hi+1)/2;
        if (check(mi)) lo = mi;
        else hi = mi-1;
    }
    check(lo);
    cout<<lo<<" "<<max(sum-a, 0LL)<<endl;

    return 0;

}

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

int n,x;
long long a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>x;
    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

    x--;

    int c = 0;
    int k = 0;
    long long m = 10000000000LL;

    for (int i=0; i<n; i++) {
        if (a[(x-i+n)%n]<m) {
            m = a[(x-i+n)%n];
            k = (x-i+n)%n;
        }
    }

    for (int i=0; i<n; i++) a[i] -= m;

    for (int i=(k+1)%n; i!=x; i=(i+1)%n) {
        if (x==k) break;
        a[i]--;
        c++;
    }

    if (x!=k) {
        a[x]--;
        c++;
    }

    a[k] += (m)*(long long)n + (long long)c;

    //cout<<k<<" "<<x<<endl;

    for (int i=0; i<n; i++) printf("%I64d ",a[i]);
    cout<<endl;

    return 0;

}

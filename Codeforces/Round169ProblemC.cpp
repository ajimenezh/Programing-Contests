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

int n,q;
long long a[200010];
int b[200010];
long long res;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>q;
    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

    for (int i=0; i<=n; i++) b[i] = 0;
    for (int i=0; i<q; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        b[l]++;
        b[r+1]--;
    }
    for (int i=1; i<=n; i++) {
        b[i] = b[i] + b[i-1];
    }
    //for (int i=0; i<n; i++) cout<<b[i]<<" "; cout<<endl;
    sort(b,b+n);
    sort(a,a+n);
    res = 0;
    for (int i=0; i<n; i++) res += (long long)b[i]*a[i];
    cout<<res;

    return 0;

}

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

int n,m;
int a[100010];
int b[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=1; i<n; i++) {
        if (a[i]>=a[i-1]) b[i-1] = 1;
        else b[i-1] = -1;
    }
    int k=0;
    a[0] = k;
    for (int i=1; i<n-1; i++) {
        if (b[i]==b[i-1]) a[i] = k;
        else a[i] = ++k;
    }
    //for (int i=0; i<n-1; i++) cout<<a[i]<<endl;
    for (int i=0; i<m; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        l--; r--;
        if ((a[r-1]-a[l]==1 && b[l]==1) || (a[r-1]-a[l]==0) || l==r) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;

}

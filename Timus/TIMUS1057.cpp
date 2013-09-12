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

int x,y;
int k,b;
int a[33];
long long c[33][33];

int solve(int i, int n, int q) {
    if (n<0 || (n==0 && q>0)) return 0;
    if (n==0 && q==0) return 1;
    if (q==0 && n!=0) return 0;
    if (i<0) return 0;
    if (i==0) {
        return solve(i-1,n-a[i],q-1) + solve(i-1,n,q);
    }
        //cout<<a[i]<<" "<<n<<endl;
    return solve(i-1,n-a[i],q-1) + c[i-1][q] + solve(i-1,n,q);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x>>y;
    cin>>k>>b;

    c[0][0] = 1;
    for (int i=0; i<33; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j=1; j<i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    int cnt = 0;
    long long i = 1;
    while (i<=y) {
        a[cnt++] = i;
        i *= b;
    }

    int res = solve(cnt,y,k) - solve(cnt,x-1,k);

    cout<<res;

    return 0;

}

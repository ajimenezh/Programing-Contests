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

int v[] = {1,3,15,133,2025,37851,1030367,36362925};
int f[16];

const int mod = 1000000007;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    f[0] = 1;
    for (int i=1; i<=n; i++) f[i] = ((long long)i*f[i-1])%mod;
    if (n%2==0) cout<<0<<endl;
    else cout<<((long long)v[n/2]%mod*f[n]%mod)%mod;

    return 0;

}

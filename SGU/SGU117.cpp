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

int fpow(int a, int b, int mod) {
    if (b==0) return 1;
    int tmp = fpow(a,b/2,mod)%mod;
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;

    int cnt = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        if (fpow(a%k,m,k)==0) cnt++;
    }

    cout<<cnt;

    return 0;

}

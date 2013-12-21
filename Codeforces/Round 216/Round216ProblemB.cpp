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

int sc[1001];
int n,k,l,r,sall,sk;
int m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>l>>r>>sall>>sk;
    for (int i=0; i<n; i++) {
        sc[i] = l;
    }
    sall -= l*n;
    sk -= l*k;

    m = 1000000;
    int tot = sk / k;
    m = tot + l;
    for (int i=0; i<k; i++) {
        sk -= tot;
        sall -= tot;
        sc[i] += tot;
    }
    for (int i=0; i<(sk); i++) {
        sall -= 1;
        sc[i] += 1;
    }

    for (int i=k; i<n; i++) {
        if (sall>0) {
            int tmp = min(r-sc[i],sall);
            tmp = min(m, tmp);
            sall -= tmp;
            sc[i] += tmp;
        }
    }

    for (int i=0; i<n; i++) cout<<sc[i]<<" "; cout<<endl;

    return 0;

}

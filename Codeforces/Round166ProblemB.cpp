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

#define MAXN 100010

bool prime[100010];
int next[100010];

int n,m;
int ma[501][501];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<MAXN; i++) prime[i] = 1;
    for (int i=2; i*i<MAXN; i++) {
        if (prime[i]) {
            for (int j=i*i; j<MAXN; j+=i) prime[j] = 0;
        }
    }

    for (int i=0; i<MAXN; i++) next[i] = 0;

    int now = 0;

    for (int i=MAXN-1; i>=2; i--) {
        if (prime[i]) {
            now = 0;
        }
        else {
            next[i] = ++now;
        }
    }

    //for (int i=1; i<10; i++) cout<<i<<" "<<prime[i]<<" "<<next[i]<<endl;


    cin>>n>>m;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>ma[i][j];
        }
    }

    int res = 10000000;

    for (int i=0; i<n; i++) {
        int tmp = 0;
        for (int j=0; j<m; j++) tmp += next[ma[i][j]];
        res = min(res,tmp);
    }

    for (int i=0; i<m; i++) {
        int tmp = 0;
        for (int j=0; j<n; j++) {
            tmp += next[ma[j][i]];
        }
        res = min(res,tmp);
    }

    cout<<res<<endl;

    return 0;

}

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

int n,k;
int p[16];
int p2[15];
int e[16];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>p[i]>>e[i];

    int res = 100000000;

    for (int i=0; i<(1<<n); i++) {
        int tot = 0;
        int t = 0;
        for (int j=0; j<n; j++) {
            p2[j] = p[j];
            if (i&(1<<j)) {
                tot += e[j];
                t++;
            }
            else {
                p2[j]++;
            }
        }
        int s = 0;
        for (int j=0; j<n; j++) {
            if (t>p2[j]) s++;
            else if (t==p2[j] && (i&(1<<j))) s++;
        }
        if (s>=(n+1-k)) res = min(res, tot);
    }

    if (res==100000000) cout<<-1;
    else cout<<res<<endl;

    return 0;

}

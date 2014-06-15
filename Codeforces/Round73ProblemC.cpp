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

int n;
int gn[100010];
int pref[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    gn[0] = 1;
    pref[0] = 0;
    int res = -1;
    for (int i=1; i<=n; i++) {
        set<int> vis;
        for (int j=2; j*(j+1)/2<=i; j++) {
            int rest = i - j*(j+1)/2;
            if (rest%j!=0) continue;
            rest /= j;
            int tmp = pref[rest]^pref[rest+j];
            if (tmp==0 && i==n && res==-1) {
                res = j;
            }
            vis.insert(tmp);
        }
        for (int j=0; ; j++) if (vis.find(j)==vis.end()) {
            gn[i] = j;
            break;
        }
        pref[i] = gn[i]^pref[i-1];
    }

    cout<<res<<endl;

    return 0;

}

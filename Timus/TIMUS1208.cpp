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

int n;
set<string> all[19];
int ady[19][19];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        for (int j=0; j<3; j++) {
            cin>>s;
            all[i].insert(s);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            rep(it,all[i]) {
                if (all[j].find(*it)!=all[j].end()) {
                    ady[i][j] = 1;
                    ady[j][i] = 1;
                }
            }
        }
    }
    int ans = 1;
    for (int i=0; i<(1<<n); i++) {
        bool good = 1;
        for (int j=0; j<n; j++) if (i&(1<<j)){
            for (int k=j+1; k<n; k++) if (i&(1<<k)) {
                if (ady[j][k]) {
                    good = 0;
                    j = 50;
                    break;
                }
            }
        }
        if (good) ans = max(ans, __builtin_popcount(i));
    }
    cout<<ans<<endl;

    return 0;

}

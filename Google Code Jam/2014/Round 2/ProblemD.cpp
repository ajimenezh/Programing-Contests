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

int n,m;
string s[8];
int p[8];
int res, cnt;

set<string> v[4];

int solve(){
    for (int i=0; i<n; i++) v[i].clear();
    for (int i=0; i<n; i++) v[i].insert("");
    for (int i=0; i<m; i++) {
        for (int j=1; j<=s[i].length(); j++) {
            v[p[i]].insert(s[i].substr(0,j));
        }
    }
    int tot = 0;
    for (int i=0; i<n; i++) if (v[i].size()!=1) tot += v[i].size();
    return tot;
}

void rec(int i) {
    if (i==m) {
        //for (int i=0; i<m; i++) cout<<p[i]<<" "; cout<<endl;
        int tot = solve();
        if (tot>res) {
            res = tot;
            cnt = 1;
        }
        else if (tot==res) {
            cnt++;
        }
    }
    else {
        for (int j=0; j<n; j++) {
            p[i] = j;
            rec(i+1);
        }
    }
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    for (int tt=0; tt<t; tt++) {
        cin>>m>>n;

        for (int i=0; i<m; i++) cin>>s[i];

        res = 0;
        cnt = 1;

        rec(0);

        printf("Case #%d: %d %d\n", tt+1, res, cnt);
    }


    return 0;

}

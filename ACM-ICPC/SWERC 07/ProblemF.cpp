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

int na, nb;
int ta[1010], tb[1010];
map<string,int> id;
pair<long long,int> dp[1010][1010];
int va[1010], vb[1010];
int cnt;

pair<long long,int> solve(int a, int b) {
    if (a==na || b==nb) return make_pair(0,0);
    if (dp[a][b].first!=-1) return dp[a][b];

    long long val = 0;
    int num = 0;

    pair<long long, int> tmp = solve(a+1,b);
    val = tmp.first;
    num = tmp.second;
    tmp = solve(a,b+1);
    if (val<tmp.first) {
        val = tmp.first;
        num = tmp.second;
    }
    else if (val==tmp.first && num>tmp.second) {
        num = tmp.second;
    }

    if (ta[a]==tb[b]) {
        tmp = solve(a+1,b+1);
        tmp.first += va[a] + vb[b];
        tmp.second++;
        if (val<tmp.first) {
            val = tmp.first;
            num = tmp.second;
        }
        else if (val==tmp.first && num>tmp.second) {
            num = tmp.second;
        }
    }

    dp[a][b] = make_pair(val,num);
    return dp[a][b];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::ios_base::sync_with_stdio (false);

    int cas;
    cin>>cas;
    while (cas--) {
        cin>>na;
        id.clear();
        cnt = 0;
        for (int i=0; i<na; i++) {
            string tmp, s;
            int c;
            cin>>tmp>>s>>c;
            va[i] = c;
            if (id.find(s)==id.end()) id[s] = cnt++;
            ta[i] = id[s];
        }
        cin>>nb;
        for (int i=0; i<nb; i++) {
            string tmp, s;
            int c;
            cin>>tmp>>s>>c;
            vb[i] = c;
            if (id.find(s)==id.end()) id[s] = cnt++;
            tb[i] = id[s];
        }

        for (int i=0; i<na; i++) for (int j=0; j<nb; j++) dp[i][j] = make_pair(-1,0);

        pair<long long,int> ans = solve(0,0);

        cout<<ans.first<<" "<<ans.second<<"\n";
    }

    return 0;

}

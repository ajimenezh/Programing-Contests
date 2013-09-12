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

int t;
int n;
pair<int,int> v[1001];
pair<int,int> w[1001];
bool done1[1001];
bool done2[1001];
string s;
int p,j;
pair<int,int> dp[1010][610];

pair<int,int> solve(int a,int b) {
    if (a>=n) {
        if (s=="Petra") {
            if (b == ((n-1)-1)/2+1) return make_pair(0,0);
            else return make_pair(-1000000,100000);
        }
        else {
            if (b == ((n)-1)/2+1) return make_pair(0,0);
            else return make_pair(-1000000,100000);
        }
    }
    if (dp[a][b]!=make_pair(-1,-1)) return dp[a][b];

    pair<int,int> best;
    pair<int,int> tmp;

    best = solve(a+1,b);
    best.second += v[a].first;

    if (solve(a+2,b+1) >= make_pair(-10000,1000)) {
        tmp = solve(a+2,b+1);
        tmp.first += v[a].second;
        if (a+1<n) tmp.second += v[a+1].first;
    }
    else {
        tmp = solve(a+1,b+1);
        tmp.first += v[a].second;
    }

    //cout<<tmp.first<<" "<<tmp.second<<" "<<best.first<<" "<<best.second<<endl;

    if (tmp.first>best.first) best = tmp;
    else if (tmp.first==best.first && tmp.second>best.second) best = tmp;

    //cout<<a<<" "<<b<<" "<<best.first<<" "<<best.second<<endl;

    dp[a][b] = best;

    return best;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>n;
        cin>>s;

        for (int i=0; i<n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            v[i] = make_pair(a,b);
            w[i] = make_pair(b,a);
        }
        sort(v,v+n);
        reverse(v,v+n);

        p = 0;
        j = 0;

        for (int i=0; i<n; i++) for (int j=0; j<510; j++) dp[i][j] = make_pair(-1,-1);

        pair<int,int> res;

        if (s=="Petra") {
            p += v[0].first;
            if (n>1) res = solve(1,0);
            else res = make_pair(0,0);
            p += res.second;
            j += res.first;
        }
        else {
            pair<int,int> res = solve(0,0);
            p += res.second;
            j += res.first;
        }

        cout<<p<<" "<<j<<endl;
    }

    return 0;

}

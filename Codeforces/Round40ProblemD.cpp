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

int n,m,K;
int c[101][101];
int dp[101][101][12];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>K;
    K++;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<m; j++) c[i][j] = s[j]-'0';
    }

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<K; k++) dp[i][j][k] = -1;

    for (int i=0; i<m; i++) solve(n-1,i,0);

    int res = -1;
    for (int i=0; i<m; i++) {
        if (dp[n-1][i][0]>res) {
            res = dp[n-1][i][0];
            pos = i+1;
        };

    if (res<0) cout<<-1;
    else {
        cout<<res<<endl;
        cout<<pos<<endl;
        int p = pos;
        while (p>=0) {
            pre[i][p][k].first == -1 ? cout<<"L"; : cout<<"R";
            p = p + pre[i--][p.first][p.second];
        }
    }

    return 0;

}

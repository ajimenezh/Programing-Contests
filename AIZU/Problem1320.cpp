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

int con[15][15];
string v[15];
int dp[1<<15][15][15];
int n;
int len[15];

bool inside(int i, int j) {
    if (v[i].length()>v[j].length()) return false;
    if (v[i].length()==v[j].length()) return v[i]==v[j];
    for (int k=0; k<=v[j].length()-v[i].length(); k++) {
        if (v[j].substr(k,v[i].length())==v[i]) return true;
    }
    return false;
}

int solve(int mask, int l, int r) {
    if (mask==(1<<n)-1) return 0;
    if (dp[mask][l][r]>=0) return dp[mask][l][r];

    int tmp = 1000000;

    for (int i=0; i<n; i++) if (((1<<i)&mask)==0) {
        tmp = min(tmp, solve(mask|(1<<i),l,i+1) + len[i] - con[r][i+1]);
        tmp = min(tmp, solve(mask|(1<<i),i+1,r) + len[i] - con[i+1][l]);
    }
    dp[mask][l][r] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        for (int i=0; i<n; i++) cin>>v[i];
        for (int i=0; i<n; i++) len[i] = v[i].length();
        for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) con[i][j] = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (i!=j) {
                if (inside(i,j)) {
                    swap(v[i],v[n-1]);
                    n--;
                    i--;
                    break;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (j!=i) {
                for (int k=1; k<=min(v[i].length(),v[j].length()); k++) {
                    if (v[i].substr(v[i].length()-k,k)==v[j].substr(0,k)) {
                        con[i+1][j+1] = k;
                    }
                }
                //cout<<i<<" "<<j<<" "<<con[i+1][j+1]<<endl;
            }
        }

        for (int i=0; i<(1<<n); i++) for (int j=0; j<=n; j++) for (int k=0; k<=n; k++) {
            dp[i][j][k] = -1;
        }
        int ans = 1000000;
        for (int i=0; i<n; i++) ans = min(ans, solve(1<<i,i+1,i+1) + len[i]);
        printf("%d\n",ans);
    }

    return 0;

}

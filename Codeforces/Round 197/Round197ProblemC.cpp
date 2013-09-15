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

string s;
int n;
bool dp[1001][11][11];
bool vis[1001][11][11];
int next[1001][11][11];

bool solve(int i, int last, int dif) {
    if (i==n) return 1;
    if (vis[i][last][dif]) return dp[i][last][dif];

    bool good = 0;

    for (int j=1; j<11; j++) if (j!=last && s[j-1]=='1') {
        if (j-dif>0) {
            if (solve(i+1,j,j-dif)) {
                next[i][last][dif] = j;
                good = 1;
                break;
            }
        }
    }

    dp[i][last][dif] = good;
    vis[i][last][dif] = 1;

    return good;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<=10; j++) for (int k=0; k<=10; k++) vis[i][j][k] = 0;
    bool good = solve(0,0,0);

    if (good) {
        cout<<"YES"<<endl;
        int i = 0, last = 0, dif = 0;
        while (i!=n) {
            cout<<next[i][last][dif]<<" ";
            i++;
            int tmp = next[i-1][last][dif];
            dif = tmp-dif;
            last = tmp;
        }
    }
    else cout<<"NO"<<endl;

    return 0;

}

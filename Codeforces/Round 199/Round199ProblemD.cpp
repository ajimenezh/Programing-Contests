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

#define mod 1000000007

int n;
bool board[3][10010];
bool m[3][10010];
int x,y;
long long dp[10010][3][8];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

long long rec(int i, int j, int mask) {
    if (i==n && j==0 && mask==0) return 1;
    if (i==n) return 0;
    if (dp[i][j][mask]>=0) return dp[i][j][mask];

    long long tmp = 0;

    int i2 = i;
    int j2 = j+1;
    if (j2==3) {
        i2++;
        j2 = 0;
    }

    if (m[j][i]) {
        if ((mask&(1<<j))==0) tmp = rec(i2,j2,mask);
    }
    else {
        if (mask&(1<<j)) {
            tmp = rec(i2,j2,mask-(1<<j));
        }
        else {
            tmp = rec(i2,j2,mask+(1<<j));
            if (j+1<3 && (mask&(1<<j2))==0) tmp += rec(i2,j2,mask+(1<<j2));
        }
    }

    dp[i][j][mask] = tmp;
    return tmp;
}

long long solve(int mask) { //x change value, strange...

    int xx = x;
    int yy = y;

    for (int i=0; i<n; i++) for (int j=0; j<3; j++) m[i][j] = board[i][j];

    for (int i=0; i<4; i++) if (mask&(1<<i)) {
        int x1 = xx+dx[i];
        int y1 = yy+dy[i];
        int x2 = x1 + dx[i];
        int y2 = y1 + dy[i];
        if (x1>=0 && x1<n && y1>=0 && y1<3) {
            if (x2>=0 && x2<n && y2>=0 && y2<3) {
                if (board[y1][x1]&&board[y2][x2]) {
                    m[y1][x1] = 0;
                    m[y2][x2] = 0;
                }
                else {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) cout<<m[i][j]<<" "; cout<<endl;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) cout<<board[i][j]<<" "; cout<<endl;
    }

    for (int i=0; i<n; i++) for (int j=0; j<3; j++) for (int k=0; k<8; k++) dp[i][j][k] = -1;

    return rec(0,0,0);

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<3; i++) {
        string s;
        cin>>s;
        for (int j=0; j<n; j++) board[i][j] = (s[j]=='.');
        for (int j=0; j<n; j++) if (s[j] == 'O') {
            x = j;
            y = i;
        }
    }

    long long ans = 0;
    for (int i=1; i<(1<<4); i++) {
        long long tmp = solve(i);
        if (__builtin_popcount(i)%2==1) ans = (ans+tmp)%mod;
        else ans = (ans-tmp+mod)%mod;
    }

    cout<<ans<<endl;

    return 0;

}

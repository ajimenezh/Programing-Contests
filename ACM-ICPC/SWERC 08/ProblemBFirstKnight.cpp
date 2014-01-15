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

double p[41][41][4];
double dp[40][40][2];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>m && n!=0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                dp[i][j][1] = 0.0;
            }
        }
        dp[0][0][1] = 1.0;
        for (int k=0; k<4; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    scanf("%lf",&p[i][j][k]);
                }
            }
        }

        double e = 0.0;
        for (int iter = 0; iter<1000; iter++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    dp[i][j][iter%2] = 0.0;
                }
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    for (int k=0; k<4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x>=n || x<0 || y<0 || y>=m) continue;
                        dp[x][y][iter%2] += p[i][j][k]*dp[i][j][1-(iter%2)];
                    }
                }
            }
            e += dp[n-1][m-1][iter%2]*(iter+1);
            dp[n-1][m-1][iter%2] = 0.0;
        }

        printf("%.12lf\n",e);
    }

    return 0;

}

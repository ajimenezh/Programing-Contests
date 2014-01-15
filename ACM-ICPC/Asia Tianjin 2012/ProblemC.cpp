//WA

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

#define INF 1000000

int dp[1010][11][11];
int up[11][11];
int down[11][11];

string s1, s2;

int a[1010], b[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            up[i][j] = j>=i?j-i:10+(j-i);
            down[i][j] = j<=i?i-j:10+i-j;
        }
    }

    while (cin>>s1>>s2) {
        memset(dp,INF,sizeof(dp));

        int n = s1.length();

        for (int i=0; i<n; i++) a[i] = s1[i]-'0';
        for (int i=0; i<n; i++) b[i] = s2[i]-'0';

        a[n] = a[n+1] = 0;
        b[n] = b[n+1] = 0;
        dp[0][a[0]][a[1]] = 0;

        for(int i=1; i<=n; i++)
         {
             for(int j=0; j<=9; j++)
             {
                 for(int k=0; k<=9; k++)
                 {
                     int temp=up[j][b[i-1]];
                     for(int ii=0; ii<=temp; ii++)
                     {
                         for(int jj=0; jj<=ii; jj++)
                         {
                             dp[i][(k+ii)%10][(a[i+1]+jj)%10] = min(dp[i][(k+ii)%10][(a[i+1]+jj)%10],dp[i-1][j][k]+temp);
                         }
                     }

                     temp=down[j][b[i-1]];
                     for(int ii=0;ii<=temp;ii++)
                     {
                         for(int jj=0;jj<=ii;jj++)
                         {
                             dp[i][(k-ii+10)%10][(a[i+1]-jj+10)%10] = min(dp[i][(k-ii+10)%10][(a[i+1]-jj+10)%10],dp[i-1][j][k]+temp);
                         }
                     }
                 }
             }
         }
         printf("%d\n",dp[n][0][0]);
    }

    return 0;

}

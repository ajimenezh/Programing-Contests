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

int n,m,k;
long long a[301][301];
long long dp[301][301];

long long solve(int i, int c) {
    if (c<0) c = 0;
    if (i>=n && c==0) return 0;
    if (i>=n) return -1;
    if (dp[i][c]>=-1) return dp[i][c];

    long long tmp = -1;

    tmp = solve(i+1,c);

    for (int j=i; j<n; j++) if (a[i][j]!=-1) {
        long long t = solve(j+1,c-(j-i+1));
        if (t!=-1) {
            t += a[i][j];
            if (tmp==-1) tmp = t;
            else tmp = min(t,tmp);
        }
    }

    //cout<<i<<" "<<c<<" "<<tmp<<endl;

    //if (i==6 && c==3) cout<<tmp<<endl;

    dp[i][c] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j] = -1;

    for (int i=0; i<m; i++) {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        l--; r--;
        if (a[l][r]==-1) a[l][r] = c;
        else a[l][r] = min(a[l][r],(long long)c);
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            int last = -1;
            for (int j=n-1; j>=i; j--) {
                if (last==-1) {
                    if (a[i][j]!=-1) {
                        last = a[i][j];
                    }
                }
                else {
                    if (a[i][j]==-1) a[i][j] = last;
                    else if (a[i][j]<last) {
                        last = a[i][j];
                    }
                    else {
                        a[i][j] = last;
                    }
                }
            }
        }
        for (int j=0; j<n; j++) {
            int last = -1;
            for (int i=0; i<=j; i++) {
                if (last==-1) {
                    if (a[i][j]!=-1) {
                        last = a[i][j];
                    }
                }
                else {
                    if (a[i][j]==-1) a[i][j] = last;
                    else if (a[i][j]<last) {
                        last = a[i][j];
                    }
                    else {
                        a[i][j] = last;
                    }
                }
            }
        }
    }

//    for (int k=0; k<n-1; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
//        if ((a[i][k]+a[k+1][j]<a[i][j] || (a[i][j]==-1)) && a[i][k]!=-1 && a[k+1][j]!=-1) {
//            a[i][j] = a[i][k] + a[k+1][j];
//        }
//    }
//    for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
//        if ((a[i][k]+a[k][j]<a[i][j] || (a[i][j]==-1)) && a[i][k]!=-1 && a[k][j]!=-1) {
//            a[i][j] = a[i][k] + a[k][j];
//        }
//    }

//    for (int i=0; i<n; i++) {
//        for (int j=0; j<n; j++) cout<<a[i][j]<<" ";
//        cout<<endl;
//    }

    for (int i=0; i<n; i++) for (int j=0; j<=n; j++) dp[i][j] = -2;

    long long res = solve(0,k);

    cout<<res;

    return 0;

}

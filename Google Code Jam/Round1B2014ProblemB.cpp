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

int a,b,k;

long long dp[32][2][2];

long long solve(int j, int i, int t1, int t2) {
    if (j==0) {
        if (t1 && t2) return 4;
        else {
            if (t1) {
                return 2;
            }
            else {
                if (t2) return 2;
                else return 0;
            }
        }
    }
    if (dp[j][t1][t2]>=0) return dp[j][t1][t2];

    long long tot = 0;

    if (j>=i) {

        if (k&(1<<j)) {
            if (t1 && t2) {
                tot += solve(j-1,i,1,1);
            }
            else {
                if (t1==0 && ((1<<j)&a)) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 0,1);
                    }
                }
                else if (t1==1) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 1,0);
                    }
                }
            }
        }
        else {
            if (t1 && t2) {
                tot += 3LL*solve(j-1,i,1,1);
            }
            else {
                if (t1==0 && ((1<<j)&a)) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 1,1);
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                        tot += solve(j-1, i, 1,0);
                    }
                }
                else if (t1==1) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += 2*solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else {
                        tot += 2*solve(j-1, i, 1,0);
                    }
                }
                else {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                    }
                }
            }
        }
    }
    else if (j==i) {
        if (t1 && t2) {
                tot += 3LL*solve(j-1,i,1,1);
            }
            else {
                if (t1==0 && ((1<<j)&a)) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 1,1);
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                        tot += solve(j-1, i, 1,0);
                    }
                }
                else if (t1==1) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += 2*solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else {
                        tot += 2*solve(j-1, i, 1,0);
                    }
                }
                else {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                    }
                }
            }
    }
    else {
            if (t1 && t2) {
                tot += solve(j-1,i,1,1);
            }
            else {
                if (t1==0 && ((1<<j)&a)) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 0,1);
                    }
                }
                else if (t1==1) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 1,0);
                    }
                }
            }

            if (t1 && t2) {
                tot += 3LL*solve(j-1,i,1,1);
            }
            else {
                if (t1==0 && ((1<<j)&a)) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else if (t2==1) {
                        tot += solve(j-1, i, 1,1);
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                        tot += solve(j-1, i, 1,0);
                    }
                }
                else if (t1==1) {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += 2*solve(j-1, i, 1,1);
                        tot += solve(j-1, i, 1,0);
                    }
                    else {
                        tot += 2*solve(j-1, i, 1,0);
                    }
                }
                else {
                    if (t2==0 && ((1<<j)&b)) {
                        tot += solve(j-1, i, 0,1);
                        tot += solve(j-1, i, 0,0);
                    }
                    else if (t2==1) {
                        tot += 2*solve(j-1, i, 0,1);
                    }
                    else {
                        tot += solve(j-1, i, 0,0);
                    }
                }
            }

    }
    //cout<<j<<" "<<t1<<" "<<t2<<" "<<tot<<endl;
    dp[j][t1][t2] = tot;
    return tot;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cin>>a>>b>>k;

        long long tot = 0;

        for (int i=30; i>=0; i--) {
            if (k&(1<<i)) {

                for (int j=0; j<31; j++) for (int t1=0; t1<2; t1++) for (int t2=0; t2<2; t2++) dp[j][t1][t2] = -1;

                tot += solve(30, i, 0, 0);

            }
        }

        printf("Case #%d: %d\n", tt, tot);
    }

    return 0;

}

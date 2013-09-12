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

#define mod 1000000007

string s;
int n;
long long dp[800][800][3][3];
int next[800];

bool dfs(int p, int q) {
    if (s[p]==')') {
        next[p] = q;
        next[q] = p;
        return true;
    }

    for (int i=p+1; i<n; i++) {
        if (next[i]==-1 && dfs(i,p)) return false;
    }
}

long long solve(int in, int fn, int c1, int c2) {
    if (fn<in) return 1;
    if (next[in]==fn && fn==in+1) {
        if (c1==0) {
            if (c2==0) return 4;
            else return 3;
        }
        else {
            if (c2==0) return 3;
            else {
                return 2;
            }
        }
    }
    if (dp[in][fn][c1][c2]!=-1) return dp[in][fn][c1][c2];

    long long tmp = 0;
    if (c1==0) {
        if (next[in]!=fn) {
            tmp += solve(in+1,next[in]-1,1,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;
            tmp += solve(in+1,next[in]-1,2,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;

            tmp += solve(in+1,next[in]-1,0,1)*solve(next[in]+1,fn,1,c2)%mod;
            tmp = tmp%mod;
            tmp += solve(in+1,next[in]-1,0,2)*solve(next[in]+1,fn,2,c2)%mod;
            tmp = tmp%mod;
        }
        else {
            tmp += solve(in+1,next[in]-1,1,0)%mod;
            tmp = tmp%mod;
            tmp += solve(in+1,next[in]-1,2,0)%mod;
            tmp = tmp%mod;

            if (c2!=2) tmp += solve(in+1,next[in]-1,0,1)%mod;
            tmp = tmp%mod;
            if (c2!=1) tmp += solve(in+1,next[in]-1,0,2)%mod;
            tmp = tmp%mod;
        }
    }
    else {
        if (next[in]!=fn) {
            if (c1!=1) tmp += solve(in+1,next[in]-1,1,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;
            if (c1!=2) tmp += solve(in+1,next[in]-1,2,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;

            tmp += solve(in+1,next[in]-1,0,1)*solve(next[in]+1,fn,1,c2)%mod;
            tmp = tmp%mod;
            tmp += solve(in+1,next[in]-1,0,2)*solve(next[in]+1,fn,2,c2)%mod;
            tmp = tmp%mod;
        }
        else {
            if (c1!=1) tmp += solve(in+1,next[in]-1,1,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;
            if (c1!=2) tmp += solve(in+1,next[in]-1,2,0)*solve(next[in]+1,fn,0,c2)%mod;
            tmp = tmp%mod;

            if (c2!=2) tmp += solve(in+1,next[in]-1,0,1)*solve(next[in]+1,fn,1,c2)%mod;
            tmp = tmp%mod;
            if (c2!=1) tmp += solve(in+1,next[in]-1,0,2)*solve(next[in]+1,fn,2,c2)%mod;
            tmp = tmp%mod;
        }
    }

    tmp = tmp%mod;
    //cout<<in<<" "<<fn<<" "<<c1<<" "<<c2<<" "<<tmp<<endl;
    dp[in][fn][c1][c2] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<3; k++) for (int l=0; l<3; l++) dp[i][j][k][l] = -1;

    for (int i=0; i<n; i++) next[i] = -1;

    for (int i=0; i<n; i++) if (next[i]==-1) dfs(i,-1);

    long long res = 0;
    res = solve(0,n-1,0,0)%mod;

    cout<<res;

    return 0;

}

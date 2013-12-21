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

int lucky[10];
int n;

int dp[2][12][12];
vector<int> num;

int solve(int flag, int pos, int ln) {
    if (ln<0) return 0;
    if (pos==num.size()) {
        if (ln==0) return 1;
        else return 0;
    }
    if (dp[flag][pos][ln]>=0) return dp[flag][pos][ln];

    int tmp = 0;
    for (int i=0; i<10; i++) {
        if (flag) {
            if (i>num[pos]) continue;
            if (i==num[pos]) {
                if (i==4||i==7) tmp += solve(1,pos+1,ln-1);
                else tmp += solve(1,pos+1,ln);
            }
            else {
                if (i==4||i==7) tmp += solve(0,pos+1,ln-1);
                else tmp += solve(0,pos+1,ln);
            }
        }
        else {
            if (i==4||i==7) tmp += solve(0,pos+1,ln-1);
            else tmp += solve(0,pos+1,ln);
        }
    }

    dp[flag][pos][ln] = tmp;
    return tmp;
}

long long ret;

void dfs(int m, int p, long long c) {
    if (m>9) return;
    if (p==6) {
        for (int i=m+1; i<=10; i++) {
            ret = (ret + c*lucky[i]%mod)%mod;
        }
    }
    else {
        for (int i=0; i<=10; i++) {
            if (lucky[i]==0) continue;
            lucky[i]--;
            dfs(m+i,p+1,c*(lucky[i]+1)%mod);
            lucky[i]++;
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int tmp = n;

    while (tmp>0) {
        num.push_back(tmp%10);
        tmp/=10;
    }
    reverse(num.begin(),num.end());
    for (int i=0; i<12; i++) for (int j=0; j<12; j++) for (int k=0; k<2; k++) dp[k][i][j] = -1;

    for (int i=0; i<11; i++) {
        lucky[i] = solve(1,0,i);
        //cout<<i<<" "<<lucky[i]<<endl;
    }
    lucky[0]--;

    dfs(0,0,1);

    cout<<ret<<endl;

    return 0;

}

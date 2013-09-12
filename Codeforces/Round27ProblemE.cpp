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

#define MAX 1000000000000000000LL

int n;
long long dp[12][1005];
vector<int> d;
int p[11] = {2,3,5,7,11,13,17,19,23,29,31};

long long fast_pow(int a, int b) {
    if (b==0) return 1LL;
    if (b==1) return (long long) a;
    long long tmp = fast_pow(a,b/2);
    if (b%2==0) return tmp*tmp;
    return (long long)a*tmp*tmp;
}

long long solve(int i, int a) {
    if (a==1) return 1LL;
    if (i>10) return MAX + 1LL;
    if (dp[i][a]!=-1) return dp[i][a];

    long long tmp = solve(i+1,a);
    for (int j=0; j<d.size(); j++) {
        if (a%d[j]==0) {
            long long t = solve(i+1,a/d[j])*fast_pow(p[i],d[j]-1);
            //cout<<t<<endl;
            if (fast_pow(p[i],d[j]-1) > MAX/solve(i+1,a/d[j]) || solve(i+1,a/d[j])<0) continue;
            if (fast_pow(p[i],d[j]-1) > MAX || solve(i+1,a/d[j])>MAX) continue;
            if (t<=0) continue;
            tmp = min(t,tmp);
            if (tmp<=0) tmp = t;
        }
    }


    dp[i][a] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            d.push_back(i);
            d.push_back(n/i);
        }
    }
    d.push_back(n);
    for (int i=0; i<12; i++) for (int j=0; j<1005; j++) dp[i][j] = -1;

    cout<<solve(0,n);

    return 0;

}

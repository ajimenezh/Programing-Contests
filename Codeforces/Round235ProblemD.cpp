#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

long long n;
vector<int> d;
int m;
long long dp[280000][110];
long long pw[19];

long long fact(int t) {
    if (t<2) return 1;
    long long x = 1;
    for (int i=2; i<=t; i++) x *= i;
    return x;
}

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    while (n>0) {
        d.push_back(n%10);
        n /= 10;
    }

    n = 1<<d.size();

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) dp[i][j] = 0;
    dp[0][0] = 1;

    pw[0] = 1;
    for (int i=1; i<19; i++) pw[i] = (10*pw[i-1])%m;

    long long tmp;
    for (int i=0; i<n-1; i++) {
        int tot = __builtin_popcount(i);
        for (int j=0; j<m; j++) if (dp[i][j]>0) {
            for (int k=0; k<d.size(); k++) if (((1<<k)&i)==0){
                if (i==0 && d[k]==0) continue;

                tmp = j + (pw[d.size()-tot-1]*d[k])%m;
                tmp %= m;

                dp[i+(1<<k)][tmp] += dp[i][j];
            }
        }
        //for (int j=0; j<m; j++) cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
    }

    long long res = dp[n-1][0];

    int cnt[10];
    for (int i=0; i<10; i++) cnt[i] = 0;
    for (int i=0; i<d.size(); i++) cnt[d[i]]++;
    for (int i=0; i<10; i++) res /= fact(cnt[i]);

    cout<<res<<endl;

	return 0;
}

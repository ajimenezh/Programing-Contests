#line 2 "BigO.cpp"
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

int n,m,d;
int a[310], b[310], t[310];
long long dp[2][150010];

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>d;

    for (int i=0; i<m; i++) scanf("%d%d%d", a+i, b+i, t+i);

    int pt = 1;
    int p = 0;

    for (int i=1; i<=n; i++) dp[1][i] = 0;

    for (int i=0; i<m; i++) {

        long long interval = min((long long)n, (long long)d*(t[i]-pt));

        deque<int> q;

        for (int j=1; j<=interval; j++) {
            while (q.size() && dp[1-p][q[q.size()-1]] <= dp[1-p][j]) q.pop_back();
            q.push_back(j);
        }

        for (int j=1; j<=n; j++) {
            long long k = j+interval;

            if (k<=n) {
                while (q.size() && dp[1-p][q[q.size()-1]] < dp[1-p][k]) q.pop_back();
                q.push_back(k);
            }

            dp[p][j] = dp[1 - p][q[0]] + (long long)(b[i] - abs(a[i] - j));
            while (q.size() && q[0] <= (int)(j - interval)) q.pop_front();

        }

        pt = t[i];
        p = 1-p;

    }

    long long res = -1000000000000000LL;
    for (int i=1; i<=n; i++) {
        res = max(res, dp[1-p][i]);
    }

    cout<<res<<endl;

	return 0;
}

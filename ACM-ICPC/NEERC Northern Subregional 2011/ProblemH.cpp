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

int n;
string s[51000];
int h[1<<5][50010];
long long sum[1<<5];
long long ans[5];

int hash(char c) {
    if (c>='a' && c<='z') return c-'a';
    if (c>='A' && c<='Z') return c-'A'+26;
    if (c>='0' && c<='9') return c-'0'+52;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>s[i];
        for (int j=0; j<(1<<5); j++) {
            int t = 0;
            for (int k=0; k<5; k++) if (j&(1<<k)) {
                int hh = hash(s[i][k]);
                t = 62*t + hh;
            }
            h[j][i] = t;
        }
    }

    for (int i=0; i<(1<<5); i++) sort(h[i],h[i]+n);

    for (int i=0; i<(1<<5); i++) {
        int p = -1;
        for (int j=0; j<n; j++) {
            if (j==n-1 || h[i][j]!=h[i][j+1]) {
                int t = j - p;
                sum[i] += (long long)(t-1)*t/2;
                p = j;
            }
        }
    }

    for (int i=0; i<(1<<5); i++) { cout<<i<<" "<<sum[i]<<endl;
        for(int j=i; j>0;) {
            j = i&(j-1);
            sum[i] -= sum[j];
        }
        ans[__builtin_popcount(i)] += sum[i];
    }

    for (int i=0; i<=5; i++) cout<<ans[i]<<" "; cout<<endl;

    return 0;

}

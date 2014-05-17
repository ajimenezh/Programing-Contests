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

int n,m;
int a[5010];
set<int> b;
vector<int> p[5010];
int g[5010];

int gcd(int x, int y) {
    if (y>x) return gcd(y,x);
    if (!y) return x;
    return gcd(y, x%y);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<m; i++) {
        int tmp;
        scanf("%d",&tmp);
        b.insert(tmp);
    }

    for (int i=0; i<n; i++) {
        int k = a[i];
        for (int j=2; j*j<=k; j++) {
            while (k%j==0) {
                k /= j;
                p[i].push_back(j);
            }
        }
        if (k!=1) p[i].push_back(k);
    }

    g[0] = a[0];
    for (int i=1; i<n; i++) g[i] = gcd(a[i], g[i-1]);

    int best = -10000000;

    for (int i=n-1; i>=-1; i--) {
        int tot = 0;
        for (int j=0; j<n; j++) {
            int k;
            if (j<=i) k = g[i];
            else k = 1;
            for (int t=0; t<p[j].size(); t++) {
                if (k>1 && k%p[j][t]==0) k /= p[j][t];
                else {
                    if (b.find(p[j][t])!=b.end()) tot--;
                    else tot++;
                }
            }
        }
        best = max(tot, best);
    }

    cout<<best<<endl;

    return 0;

}

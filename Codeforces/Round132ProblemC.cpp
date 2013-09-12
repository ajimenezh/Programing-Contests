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

long long sum[501][501];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m,s;

    cin>>n>>m>>s;

    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=0; k<=n; k++) {
        int a = i+1;
        int b = j+1;
        int c = k+1;
        int t = s - a*b;
        if (a>c) {
            if (s%c==0) {
                int d = s/c;
                if (s!=c*d) continue;
                sum[max(a,c)][max(b,d)]++;
            }
            if (t%(a-c)==0 && t<0) {
                int d = t / (c-a);
                if (t==c*d - a*d) continue;
                sum[max(a,c)][max(b,d)]++;
            }
        }
        else if (a<c) {
            if (s==a*b) {
                sum[a][b]++;
            }
            if (c!=0 && t%(c)==0 && t>0) {
                int d = t / c + b;
                if (t!=c*d - c*b) continue;
                sum[max(a,c)][max(b,d)]++;
            }
        }
        else if (a==c && c!=0) {
            if (s%c==0) {
                int d = s/c;
                if (s!=c*d) continue;
                sum[max(a,c)][max(b,d)]++;
            }
            if (s==a*b) {
                sum[a][b]++;
            }
        }
    }

    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;

    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) {
        if (i>0) sum[i][j] += sum[i-1][j];
        if (j>0) sum[i][j] += sum[i][j-1];
        if (i>0 && j>0) sum[i][j] -= sum[i-1][j-1];
    }

    long long res = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        int a = min(i+1,n-i);
        int b = min(j+1,m-j);
        res += sum[a][b];
    }

    cout<<res;

    return 0;

}

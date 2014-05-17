#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstdio>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
int d[505][505];
int len[505][505];

int gcd(int a, int b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) scanf("%d",&d[i][j]);
        d[i][i] = 1000000;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) len[i][j] = 1;
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                double d1 = (double)d[i][j] / len[i][j];
                double d2 = (double)(d[i][k]+d[k][j]) / (len[i][k] + len[k][j]);
                if (d1>d2) {
                    d[i][j] = d[i][k]+d[k][j];
                    len[i][j] = len[i][k] + len[k][j];
                }
            }
        }
    }


    double m = 1000000.0;
    int p = 0;

    for (int i=0; i<n; i++) {
        double d1 = (double)d[i][i] / len[i][i];
        if (d1>m) {
            m = d1;
            p = i;
        }
    }


    int g = gcd(d[p][p], len[p][p]);

    cout<<d[p][p]/g<<"/"<<len[p][p]/g<<endl;

    return 0;

}



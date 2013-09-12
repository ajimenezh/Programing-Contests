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

int r[1001][1001];

long long sqr(long long a) {
    return a*a;
}

long long solve(int a, int b) {
    //cout<<a<<" "<<b<<endl;
    long long c = 0;

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        c += r[i][j]*(sqr(4*i+2 - (4*a)) + sqr(4*j+2 - (4*b)));
        //cout<<i<<" "<<j<<" "<<sqr(4*i+2 - (4*a))<<" "<<sqr(4*j+2 - (4*b))<<endl;
    }

    //cout<<c<<endl;
    return c;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        scanf("%d",&r[i][j]);
    }

    long long cx = 0;
    long long cy = 0;

    long long rar = 0;

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        rar += r[i][j];

        cx += r[i][j]*(i);
        cy += r[i][j]*(j);
    }

    if (rar==0) {
        cout<<0<<endl;
        cout<<0<<" "<<0<<endl;

        return 0;
    }

    long long px = cx/rar;
    long long py = cy/rar;

    //cout<<px<<" "<<py<<endl;

    int x = 0;
    int y = 0;

    long long m = 1LL<<62;

    for (int j=-1; j<2; j++) for (int i=-1; i<2; i++) {
        if (px+i>=n || px+i<0) continue;
        if (py+j>=m || py+i<0) continue;
        long long tmp = solve(px+i,py+j);
        if (tmp<m) {
            m = tmp;
            x = px+i;
            y = py+j;
        }
    }

    cout<<m<<endl;

    cout<<x<<" "<<y<<endl;

    return 0;

}

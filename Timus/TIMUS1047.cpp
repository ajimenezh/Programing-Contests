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

double m[3][3001];
double c[3001];
int n;
double a0,an;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>a0>>an;

    m[0][0] = 0.5;
    m[0][1] = -1;
    m[0][2] = 0.5;
    m[1][1] = 0.5;
    m[1][2] = -1;
    m[1][3] = 0.5;

    for (int i=0; i<n; i++) cin>>c[i+1];

    //for (int j=0; j<=n+1; j++) cout<<m[0][j]<<" "; cout<<endl;
    for (int i=1; i<n; i++) {
        double d = -m[0][i+1] / m[1][i+1];
        //cout<<d<<endl;
        for (int j=0; j<=n+1; j++) m[0][j] += m[1][j]*d;
        c[1] += d*c[i+1];
        m[2][i+1] = 0.5;
        m[2][i+2] = -1;
        m[2][i+3] = 0.5;
        d = -m[2][i+1] / m[1][i+1];
        for (int j=0; j<=n+1; j++) m[2][j] += m[1][j]*d;
        for (int j=0; j<=n+1; j++) {m[1][j] = m[2][j]; m[2][j] = 0;}
        c[i+2] += d*c[i+1];
        //for (int j=0; j<=n+1; j++) cout<<m[0][j]<<" "; cout<<endl;
        //for (int j=0; j<=n+1; j++) cout<<m[1][j]<<" "; cout<<endl;cout<<endl;
    }

    double a1 = (+c[1]-a0*m[0][0]-an*m[0][n+1])/m[0][1];

    printf("%.2f\n", a1);

    return 0;

}

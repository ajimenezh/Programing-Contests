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

int x[210],y[210];

int dot(int a, int b, int c, int d) {
    return  (a*c+b*d);
}
long long sqr(int a) {return (long long)a*(long long)a;}
long long sqr(long long a) {return a*a;}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>x[i]>>y[i];

    int res = 2;

    for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
        int ux = x[i]-x[j];
        int uy = y[i]-y[j];
        int t = 2;
        for (int k=j+1; k<n; k++) {
            if (sqr(abs(dot(ux,uy,x[i]-x[k],y[i]-y[k])))==(sqr(ux)+sqr(uy))*(sqr(x[i]-x[k])+sqr(y[i]-y[k]))) {
                t++;
            }
        }
        res = max(t,res);
    }
    cout<<res<<endl;

    return 0;

}

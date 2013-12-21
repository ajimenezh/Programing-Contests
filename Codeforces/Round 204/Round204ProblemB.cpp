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
double m[4600010];
double l[4600010];
double r[4600010];
double p[4600010];
double sol[4600010];
int a[3010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int k = (n-1)*n/2 + 1;
    for (int i=0; i<k; i++) p[i] = 2;
    p[0] = 0;
    p[1] = 1;
    for (int i=0; i<k; i++) m[i] = 0.5;
    m[1] = 1;
    m[0] = 1.0;
    for (int i=0; i<k; i++) l[i] = -0.5;
    l[0] = 0;
    l[1] = 0;

    for (int i=2; i<k; i++) {
        double tmp = -l[i]/m[i-2];
        l[i] = 0;
        p[i] = p[i-2]*tmp + p[i];
    }
    double tmp = -l[k-1]/m[k-2];
    p[k-1] = p[k-2]*tmp + p[k-1];

    sol[k-1] = p[k-1]/m[k-1];
    for (int i=k-2; i>=0; i--) {
        sol[i] = (p[i] - r[i]*sol[i+1])/m[i];
    }

    int cnt = 0;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) if (a[i]>a[j]) cnt++;
    }

    printf("%.8lf",sol[cnt]);

    return 0;

}

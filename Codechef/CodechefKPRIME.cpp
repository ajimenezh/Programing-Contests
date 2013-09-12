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

int is[100005][6];
int c[100005][6];

int doit(int a, int b) {
    int t = 0;
    for (int i=2; i*i<=a; i++) {
        if (a%i==0) {
            t++;
            if (t>b) return 1000;
            while (a>0 && a%i==0) a/=i;
        }
    }
    if (a!=1) t++;
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=1; i<=100000; i++) {
        int a = doit(i,5);
        if (a<=5) is[i][a] = 1;
    }
    for (int i=1; i<=100000; i++) for (int j=0; j<6; j++) {
        c[i][j] = c[i-1][j] + is[i][j];
    }

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        printf("%d\n",c[b][k]-c[a-1][k]);
    }

    return 0;

}

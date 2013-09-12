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

long long n,t;
long long c[62][62];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>t;

    if (t!=1 &&(t & (t-1))) {
        cout<<0;
        return 0;
    }


    c[0][0] = 1;
    for (int i=1; i<=60; i++) {
        c[i][0] = 1;
        for (int j=1; j<=i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }


    int p;
    for (p=0; (1LL<<p)<t; p++);
    p++;
    long long res = 0;
    n+=2;
    for (int i=60; i>=0; i--) {
        if ((1LL<<(i))&n) res += c[i][p];
        p -= ((1LL<<(i))&n)>0;
        //cout<<p<<endl;
        if (p<0) break;
    }

    if (t==1 && n==1) res++;
    if (t==1 && n!=1) res--;
    cout<<res<<endl;

    return 0;

}

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

int n;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    if (n==1) {cout<<0; return 0;}
    if (n==2) {
        if (a[0]==0 && a[1]!=0) cout<<1;
        else cout<<0;
        return 0;
    }
    bool good0 = 1, good1 = 1;
    bool maybe = 0;
    int c = 0;
    int last = 1;
    for (int i=2; i<n; i++) {
        if (a[last]*a[1]!=a[i]*a[0]) c++;
        if (c==1) {good0 = 0; last --;}
        if (c==2) {good1 = 0; break;}
        last++;
    }
    if (good0) {cout<<0; return 0;}
    maybe |= good1;
    good1 = 1;
    c = 0;
    for (int i=3; i<n; i++) {
        if (a[i-1]*a[2]!=a[i]*a[1]) c++;
        if (c==1) good1 = 0;
    }
    //cout<<c<<endl;
    maybe |= good1;
    good1 = 1;
    c = 0;
    for (int i=3; i<n; i++) {
        if (i==3 && a[0]*a[2]!=a[i]*a[0]) c++;
        else if (a[i-1]*a[2]!=a[i]*a[0]) c++;
        if (c==1) good1 = 0;
    }
    maybe |= good1;
    if (maybe) {cout<<1; return 0;}
    cout<<2;

    return 0;

}

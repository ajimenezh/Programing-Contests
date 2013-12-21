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

int gcd(int a, int b) {
    if (b>a) return  gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b;
    cin>>a>>b;
    int d = gcd(a,b);
    set<int> all;
    for (int i=1; i*i<=d; i++) if (d%i==0) {
        all.insert(-i);
        all.insert(-d/i);
    }
    int m;
    cin>>m;
    for (int i=0; i<m; i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        set<int>::iterator it = all.lower_bound(-r);
        if (it==all.end()) printf("-1\n");
        else {
            int k = (*it);
            if (k<=-l) printf("%d\n",-k);
            else printf("-1\n");
        }
    }

    return 0;

}

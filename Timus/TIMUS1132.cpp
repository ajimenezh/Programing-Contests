//Not finished

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

int fpow(int a, int b, int m) {
    if (b==0) return a;
    int tmp = fpow(a,b/2,m);
    tmp = (tmp*tmp)%m;
    if (b%2==0) return tmp;
    return (a*tmp)%m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int k;
    cin>>k;
    while (k--) {
        int a,n;
        scanf("%d%d",&a,&n);
        if (n%8==5) {
            int t = fpow(a,(n-1)/2,n);
            int v = fpow(2*a, (m-5)/8, m);
            int i = 2*a*fpow(v,2,m)%m;
            int r = a*v*(i-1)%m;
            int r2 = m - r;
        }
        else if (n%8==1) {
            int t = fpow(a,(n-1)/2,n);


        }
    }

    return 0;

}

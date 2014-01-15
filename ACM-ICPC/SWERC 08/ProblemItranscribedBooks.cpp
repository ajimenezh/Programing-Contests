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

long long gcd(long long a, long long b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        int n;
        cin>>n;
        long long sum;
        long long g = -1;
        bool done = 0;
        for (int i=0; i<n; i++) {
            sum = 0;
            for (int j=0; j<9; j++) {
                long long a;
                scanf("%I64d",&a);
                sum += a;
            }
            long long b;
            scanf("%I64d",&b);
            sum -= b;
            if (!done && sum!=0) {
                g = sum;
                done = 1;
            }
            else {
                if (sum!=0) g = gcd(sum,g);
            }
        }
        if (g==1 || g==-1) printf("Impossible\n");
        else printf("%I64d\n",g);
    }

    return 0;

}



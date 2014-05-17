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

long long a[12000100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n;
    cin>>n;

    if (n%3!=0) {
        cout<<0<<endl;
        return 0;
    }
    n /= 3;
    int m = 0;

    int ans = 0;

    for (int i=1; (long long)i*i<=n; i++) if (n%i==0) {
        a[m++] = i;
    }

    for (int i=0; a[i]*a[i]*a[i]<=n && i<m; i++) {
        for (int j=i; a[i]*a[j]*a[j]<=n && j<m; j++) {
            long long x = a[i];
            long long y = a[j];
            long long z = n/a[i]/a[j];
            if (z==0) continue;

            long long b = z + x - y;
            if (b%2!=0) continue;
            b /= 2;
            long long c = b - x + y;
            long long a = x - b;
            if (a>0 && b>0 && c>0) {
                if (a==b && a==c) ans++;
                else if (a!=b&&a!=c&&b!=c) ans += 6;
                else ans += 3;
            }
        }
    }

    cout<<ans<<endl;

    return 0;

}

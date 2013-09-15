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
int a[100010];

long long gcd(long long a, long long b) {
    if (b>a) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    long long sum = 0;
    long long tot = 0;
    sort(a,a+n);
    for (int i=0; i<n; i++) {
        tot += 2*((long long)(i)*a[i]-sum) + a[i];
        sum += a[i];
    }

    long long g = gcd(tot,n);
    tot /= g;
    n /= g;
    cout<<tot<<" "<<n<<endl;

    return 0;

}

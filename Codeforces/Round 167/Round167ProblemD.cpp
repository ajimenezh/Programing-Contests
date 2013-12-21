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

int n,m;
int a[100010];
int b[100010];
int v[200010];
int fact[200010];
int cnt;

long long fpow (long long a, long long b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%m;
    if (b%2==0) return tmp;
    return (a*tmp)%m;
}

long long fi(long long n)
{
    long long res = n;
    for (int i=2; (long long)i*i<=n; i++)
    {
        if (n%i==0) res -= res/i;
        while(n%i==0) n /= i;
    }
    if (n>1) res -= res/n;
    return res;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) scanf("%d",b+i);
    for (int i=0; i<n; i++) if (a[i]==b[i]) cnt++;
    cin>>m;


    for (int i=0; i<n; i++) v[i] = a[i];
    for (int i=0; i<n; i++) v[i+n] = b[i];
    n = 2*n;
    sort(v,v+n);

    long long ans = 1;
    for (int i=0; i<n; i++) {
        int k = i;
        int tot = 1;
        while (k+1<n && v[k+1]==v[i]) {
            k++;
            tot++;
        }
        long long f = 1;
        for (int i=1; i<=tot; i++) {
            f = (i*f);
            while (cnt>0 && f%2==0) {
                f /= 2;
                cnt--;
            }
            f %= m;
        }
        ans = (ans*f)%m;
        while (cnt>0 && ans%2==0) {
            ans /= 2;
            cnt--;
        }
        ans %= m;
        i = k;
    }
    if (cnt>0 && m%2!=0) {
        ans = (ans*fpow(fpow(2,cnt),fi(m)-1))%m;
        cnt = 0;
    }

    cout<<ans<<endl;

    return 0;

}

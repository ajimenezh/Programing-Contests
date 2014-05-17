#include <iostream>
#include <map>
using namespace std;

int n;
int a[510];
int mod = 1000000007;
map<int,int> cnt;
long long f[20000];

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

long long c(int a, int b) {
    long long tmp = f[a];
    long long den = (f[b]*f[a-b])%mod;
    tmp = (tmp*fpow(den, mod-2))%mod;
    return tmp;
}

int main() {

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    int tot = 0;
    for (int i=0; i<n; i++) {
        int x = a[i];
        for (int j=2; (long long)j*j<=x; j++) if (x%j==0) {
            while (x%j==0) {
                cnt[j]++;
                x /= j;
            }
        }
        if (x!=1) cnt[x]++;
    }

    f[0] = 1;
    for (int i=1; i<20000; i++) f[i] = (f[i-1]*i)%mod;

    long long res = 1;
    for (map<int,int>::iterator it = cnt.begin(); it!=cnt.end(); it++) {
        res = (res * c(n+(*it).second-1, (*it).second))%mod;
    }

    cout<<res<<endl;

    return 0;

}

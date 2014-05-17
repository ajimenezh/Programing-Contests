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

const int mod = 1000000007;

long long fpow(long long a, long long b) {
    if (b==0) return 1;
    long long tmp = fpow(a, b/2);
    tmp %= mod;
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    a %= mod;
    return (a*tmp)%mod;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        long long n, r;
        int k;
        scanf("%d%lld%lldd", &k, &n, &r);

        long long res = 0;

        vector<pair<long long, long long> > v(k+2, make_pair(0,0));

        v[1] = make_pair(1, 1);

        for (int i=1; i<=k; i++) {
            vector<pair<long long, long long> > w(k+2, make_pair(0,0));
            for (int j=1; j<=k; j++) if (v[j].first>0) {
                w[j].first += (v[j].first*(n%mod+j))%mod;

                w[j].first %= mod;

                w[j].second = v[j].second;

                w[j+1].first -= (v[j].first*v[j].second)%mod;

                w[j+1].first = (w[j+1].first + mod)%mod;

                w[j+1].second = v[j].second + 1;
            }

            v = w;

            //for (int j=1; j<=i+1; j++) cout<<v[j].first<<" "<<v[j].second<<endl;
            //cout<<"--------------"<<endl;
        }

        for (int j=1; j<=k+1; j++) if (v[j].first!=0) {

            long long tmp = 0;
            tmp = fpow(r, n+j);
            tmp = (tmp*v[j].first)%mod;
            tmp = (tmp*fpow(fpow((r%mod-1+mod)%mod, v[j].second), mod-2))%mod;

            res = (res + tmp)%mod;
            res = (res + mod)%mod;
        }

        v = vector<pair<long long, long long> >(k+2, make_pair(0,0));

        v[1] = make_pair(1, 1);

        for (int i=1; i<=k; i++) {
            vector<pair<long long, long long> > w(k+2, make_pair(0,0));
            for (int j=1; j<=k; j++) if (v[j].first!=0) {
                w[j].first += (v[j].first*(j))%mod;

                w[j].first %= mod;

                w[j].second = v[j].second;

                w[j+1].first -= (v[j].first*v[j].second)%mod;

                w[j+1].first = (w[j+1].first + mod)%mod;

                w[j+1].second = v[j].second + 1;
            }

            v = w;

            //for (int j=1; j<=i+1; j++) cout<<v[j].first<<" "<<v[j].second<<endl;
            //cout<<"--------------"<<endl;
        }

        for (int j=1; j<=k+1; j++) if (v[j].first!=0) {

            long long tmp = 0;
            tmp = fpow(r, j);
            tmp = (tmp*v[j].first)%mod;
            tmp = (tmp*fpow(fpow(r-1, v[j].second), mod-2))%mod;

            res = (res - tmp)%mod;
            res = (res + mod)%mod;
        }

        cout<<res<<endl;
    }

    return 0;

}

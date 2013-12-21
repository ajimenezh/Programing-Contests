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

#define mod 1000000007

int n,m,k;
int next[1000010];
int last[1000010];

long long fpow(long long a, long long b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    bool bad = 0;
    cin>>n>>m>>k;
    int t = 0;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a!=b-1) {
            if (b<a) bad = 1;
            if (b-a!=k+1) bad = 1;
            if (next[a]!=0) bad = 1;
            next[a] = b;
            last[b] = a;
            t++;
        }
    }

    if (bad) {
        cout<<0<<endl;
        return 0;
    }
    int in = -1;
    for (int i=1; i<=n; i++) {
        if (next[i]!=0) {
            for (int j=i+k+1; j<=n; j++) if (next[j]!=0) bad = 1;
            break;
        }
    }
    for (int i=1; i<=n; i++) if (next[i]!=0 && next[next[i]]!=0) bad = 1;
    if (bad) {
        cout<<0<<endl;
        return 0;
    }

    if (t==0) {
        long long t = 1;
        for (int i=1; i<=(n-k-1); i++) {
            t = (t + fpow(2, min(k, n-(i+k)-1)))%mod;
        }
        cout<<t<<endl;
    }
    else {
        for (int i=1; i<=n; i++) if (next[i]!=0) {
            if (next[i+k]) {
                int free = 0;
                for (int j=i+1; j<=i+k; j++) if (next[j]==0 && j+k<n) free++;
                long long t = 1;
                t = (t + fpow(2,free) - 1 + mod)%mod;
                cout<<t<<endl;
                break;
            }
            int free = 0;
            for (int j=i+1; j<=i+k; j++) if (next[j]==0) free++;
            long long t = 1;
            int free2 = 0;
            for (int j=i+k; j>=i; j++) {
                if (last[j]!=0) {
                    t = (t + fpow(2,free2)*fpow(2,free) - 1 + mod)%mod;
                    t = (t + fpow(2,free) - 1 + mod)%mod;
                    cout<<t<<endl;
                    break;
                }
                else {
                    free--;
                    if (j+k<n) t = (t + fpow(2,free) - 1 + mod)%mod;
                    if (j-k>1) free2++;
                }
            }
            break;
        }
    }

    return 0;

}

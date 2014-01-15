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
#include <bitset>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define rep(i,n) for (int i=0; i<n; i++)

int n,k;
bitset<10000080> is;

int dr(int a) {
    int c = a;
    while (a>0) {
        c += a%10;
        a /= 10;
    }
    return c;
}

int s[5010];
pair<int,int> v[5010];
int A[5010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<k; i++) scanf("%d",s+i);
    for (int i=0; i<k; i++) v[i] = make_pair(s[i],i);
    sort(v,v+k);
    int j = 0;
    int tot = 0;

    int cur = 0;

    int sum = 0;
    int sum1 = 0;
    int sum2 = 0;

    rep(a,10) {
        rep(b,10) {
            rep(c,10) {
                sum1 = a+b+c;
                rep(d,10) {
                    rep(e,10) {
                        sum2 = sum1 + d + e;
                        rep(f,10) {
                            rep(g,10) {
                                sum = sum2+f+g;
                                is[cur+sum] = 1;
                                cur++;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i=1; i<=n; i++) {
        if (!is[i]) {
            tot++;
            if (j<k && tot==v[j].first) {
                A[j++] = i;
            }
        }
    }

    cout<<tot<<endl;
    for (int i=0; i<k; i++) v[i] = make_pair(v[i].second,A[i]);
    sort(v,v+k);
    for (int i=0; i<k; i++) printf("%d ",v[i].second);

    return 0;

}

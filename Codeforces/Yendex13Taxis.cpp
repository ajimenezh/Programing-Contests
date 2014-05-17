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

long long m,d,n;
long long v[500100];
int main() {

    freopen("taxi.in","r",stdin);
    freopen("taxi.out","w",stdout);

    cin>>m>>d>>n;
    long long rest = m-d;
    for (int i=0; i<n; i++) scanf("%lld",v+i);
    sort(v,v+n);
    reverse(v,v+n);
    if (rest>=0) {
        int last = n-1;
        for (int i=0; i<n-1; i++) {
            if (v[i]>=rest && v[i+1]<rest) {
                last = i;
                break;
            }
        }
        if (v[last]<rest) {
            cout<<0;
            return 0;
        }

        int tot = 1;
        long long now = d;
        bool done = 0;
        for (int i=0; i<last; i++) {
            if (v[i]-now>=now) {
                tot++;
                done = 1;
                break;
            }
            else {
                long long tmp = v[i]-now;
                if (tmp<=0) break;
                now -= tmp;
                tot++;
                if (now<=0) {
                    done = 1;
                    break;
                }
            };
        }
        for (int i=last+1; i<n; i++) if (!done) {
            if (v[i]-now>=now) {
                tot++;
                done = 1;
                break;
            }
            else {
                long long tmp = v[i]-now;
                if (tmp<=0) break;
                now -= tmp;
                tot++;
                if (now<=0) {
                    done = 1;
                    break;
                }
            };
        }

        bool done2 = 0;
        int tot2 = 0;
        now = d;
        for (int i=0; i<n; i++) {
            if (v[i]-now-now>=rest) {
                tot2++;
                done2 = 1;
                break;
            }
            else {
                long long tmp = v[i]-now;
                if (tmp<=0) break;
                now -= tmp;
                tot2++;
            }
        }
        if (!done && !done2) cout<<0<<endl;
        else {
            if (!done) cout<<tot2;
            else if (!done2) cout<<tot;
            else cout<<min(tot,tot2);
        }
    }
    else {
        int tot = 0;
        long long now = m;
        bool done = 0;
        for (int i=0; i<n; i++) {
            if (now<=0) {
                done = 1;
                break;
            }
            else if (v[i]>=now+(d-(m-now))) {
                tot++;
                done = 1;
                break;
            }
            else {
                long long tmp = v[i]-(d-(m-now));
                if (tmp<=0) break;
                now -= tmp;
                tot++;
            }
        }
        if (done) cout<<tot;
        else cout<<0;
    }

    return 0;

}

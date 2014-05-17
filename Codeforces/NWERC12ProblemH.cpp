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

int l,r;

bool prime[5000];
vector<int> primes;
int cnt[5000];
set<pair<int,int> > s;
set<int> s2;

long long res;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>l>>r;

    for (int i=2; i<5000; i++) prime[i] = 1;

    res = 1LL<<62;

    for (int i=2; i*i<5000; i++) if (prime[i]) {
        for (int j=i*i; j<5000; j += i) {
            prime[j] = 0;
        }
    }

    for (int i=2; i<5000; i++) {
        if (prime[i] && i>=l && i<=r) primes.push_back(i);
    }

    if (r-l+1>=139) {
        for (int i=l; i<=r; i++) {
            if ((int)(sqrt(i))*(int)(sqrt(i))==i) {
                cout<<(int)(sqrt(i))<<endl;
                break;
            }
        }
    }
    else {
        for (int i=l; i<=r; i++) {
            int x = i;
            for (int j=0; j<primes.size(); j++) {
                while (x%primes[j]==0) {
                    cnt[primes[j]]++;
                    x /= primes[j];
                }
            }
        }

        for (int i=l; i<=r; i++) {
            int x = i;
            bool done = 0;
            for (int j=0; j<primes.size(); j++) {
                int c = 0;
                if (x%primes[j]==0 && (cnt[primes[j]]==1 || cnt[primes[j]]==2)) {
                    done = 1;
                    break;
                }
                while (x%primes[j]==0) {
                    x /= primes[j];
                    c++;
                }
                if (c%2!=0) x *= primes[j];
            }
            if (done) continue;
            if (s2.find(x)==s2.end()) {
                s.insert(make_pair(x,i));
                s2.insert(x);
            }
        }

        for (int i=0; i<primes.size(); i++) {
            if (cnt[primes[i]]==2) {
                int x = 1;
                for (int j=l; j<=r; j++) if (j%primes[i]==0) {
                    x *= j;
                }
                for (int j=0; j<primes.size(); j++) {
                    int c = 0;
                    while (x%primes[j]==0) {
                        x /= primes[j];
                        c++;
                    }
                    if (c%2!=0) x *= primes[j];
                }

                if (s2.find(x)==s2.end()) {
                    s.insert(make_pair(x,i));
                    s2.insert(x);
                }

            }
        }

        cout<<s.size();
    }


    return 0;

}

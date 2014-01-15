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

long long n;

int primes[1000];
bool isprime[1000000];
int k;
vector<unsigned long long> all;
vector<vector<int> > decom;
vector<unsigned long long> f;
map<unsigned long long, unsigned long long> best;

void doit(int i, int m, unsigned long long MAX,unsigned long long cur) {
    unsigned long long tmp = cur;

    all.push_back(cur);

    for (int j=1; j<=m; j++) {
        if (tmp<=MAX/primes[i]) {
            tmp *= primes[i];
            doit(i+1,j,MAX,tmp);
        }
    }

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<1000000; i++) isprime[i] = 1;

    for (int i=2; i*i<1000000; i++) if (isprime[i]) {
        for (int j=i*i; j<1000000; j+=i) isprime[j] = 0;
    }

    k = 0;
    for (int i=2; i<1000000&&k<1000; i++) if (isprime[i]) primes[k++] = i;

    doit(0,62,((unsigned long long)1<<63) - 1,1);

    decom.resize(all.size());

    for (int i=0; i<all.size(); i++) {
        int t = 0;
        unsigned long long a = all[i];
        while (a>0) {
            int cnt = 0;
            while (a>1 && a%primes[t]==0) {
                a /= primes[t];
                cnt++;
            }
            t++;
            if (cnt==0) break;
            decom[i].push_back(cnt);
        }
    }
    f.push_back(2);
    for (int i=1; i<all.size(); i++) {
        unsigned long long MAX = ((unsigned long long)1<<63) - 1;
        unsigned long long cur = 1;
        int s = decom[i][0]+1;
        for (int j=1; j<decom[i].size(); j++) {
            int r = 1;
            for (int t=1; t<=decom[i][j]; t++, s++) {
                while (r<=decom[i][j] && cur%r==0) {
                    cur /= r;
                    r++;
                }
                int pr = s;
                while (r<=decom[i][j] && pr%r==0) {
                    pr /= r;
                    r++;
                }
                if (cur<=MAX/pr)
                    cur *= pr;
                else {
                    cur = -1;
                    j = 10000;
                    break;
                }
                while (r<=decom[i][j] && cur%r==0) {
                    cur /= r;
                    r++;
                }
            }
        }
        f.push_back(cur);
    }


    for (int i=1; i<all.size(); i++) {
        if (best.find(f[i])==best.end()) best[f[i]] = all[i];
        best[f[i]] = min(best[f[i]],all[i]);
    }
    best[1] = 2;

    cout<<best.size()<<endl;

    while (scanf("%I64d",&n)!=EOF) {
        cout<<n<<" "<<best[n]<<endl;
    }

    return 0;

}

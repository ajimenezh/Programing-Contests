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

int pr[32000];
int c[32000];
int m;
int all[100000];
int cnt;

bool rec(int i, int k, int t) {
    if (i==m) return false;
    if (k==0) {all[cnt++] = t; return true;}
    if (c[i]>0) {
        bool done = rec(i+1,k-1,t*pr[i]);
        if (done) c[i]--;
        return done;
    }
    else return rec(i+1,k,t);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    m = 0;
    cnt = 0;

    for (int i=2; (long long)i*(long long)i<=n; i++) if (n%i==0) {
        int t = 0;
        while (n%i==0) {
            n /= i;
            t++;
        }
        pr[m] = i;
        c[m] = t;
        m++;
    }
    if (n!=1) {
        all[cnt++] = n;
    }
    for (int i=0; i<m; i++) {
        c[i]--;
        all[cnt++] = pr[i];
    }
    for (int i=0; i<m; i++) {
        int k = 1;
        while (c[i]>0) {
            if (rec(i+1,k,pr[i])) c[i]--;
            else break;
        }
    }
    for (int i=0; i<m; i++) if (c[i]>0) {
        c[i]++;
        int j = 1;
        int t = pr[i];
        while (true) {
            if (c[i]<j+j+1) {
                t = 1;
                for (int k=0; k<c[i]; k++) t *= pr[i];
                c[i] = 0;
                all[cnt++] = t;
            }
            else {
                cnt -= j;
                j++;
                all[cnt++] = t;
                t *= pr[i];
            }
        }
    }

    sort(all,all+cnt);
    cout<<cnt<<endl;
    for (int i=0; i<cnt; i++) cout<<all[i]<<" ";

    return 0;

}

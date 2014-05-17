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

int tt,n;
long long a[1001];
long long b[1001];
long long c[1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>tt;
    for (int t=0; t<tt; t++) {
        cin>>n;
        for (int i=0; i<n; i++) scanf("%I64d",a+i);
        for (int i=0; i<n; i++) b[i] = 0;
        long long m = 0;
        bool done = 0;
        for (int i=60; i>=0; i--) {
            bool bad = 0;
            for (int j=0; j<n; j++) {
                c[j] = b[j];
                if (((1LL<<i)&a[j])) c[j] += 1LL<<i;
                //cout<<c[j]<<" ";
            }
            //cout<<endl;
            bool pass = 0;
            for (int j=1; j<n; j++) {
                if (c[j]!=c[j-1]) pass = 1;
            }
            for (int j=1; j<n; j++) {
                if (c[j]<c[j-1]) {
                    bad = true;
                    break;
                }
            }
            if (!bad && pass) {
                for (int j=0; j<n; j++) {
                    if (((1LL<<i)&a[j])) b[j] += 1LL<<i;
                }
            }
            else {
                bad = 0;
                for (int j=0; j<n; j++) {
                    c[j] = b[j];
                    if (((1LL<<i)&a[j])==0) c[j] += 1LL<<i;
                    //cout<<c[j]<<" ";
                }
                //cout<<endl;
                pass = 0;
                for (int j=1; j<n; j++) {
                    if (c[j]!=c[j-1]) pass = 1;
                }
                for (int j=1; j<n; j++) {
                    if (c[j]<c[j-1]) {
                        bad = true;
                        break;
                    }
                }
                if (!bad && pass) {
                    m += 1LL<<i;
                    for (int j=0; j<n; j++) {
                        if (((1LL<<i)&a[j])==0) b[j] += 1LL<<i;
                    }
                }
                else {
                    for (int j=0; j<n; j++) {
                        if (((1LL<<i)&a[j])) b[j] += 1LL<<i;
                    }
                }
            }
            //cout<<"buena   "; for (int j=0; j<n; j++) cout<<b[j]<<" "; cout<<endl;
        }
        bool good = 1;
        for (int i=1; i<n; i++) {
            if (b[i]<=b[i-1]) {
                good = 0;
                break;
            }
        }
        if (good) printf("%I64d\n",m);
        else printf("-1\n");
    }

    return 0;

}

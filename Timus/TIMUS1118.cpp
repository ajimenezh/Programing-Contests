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

bool prime[1000100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int l,f;
    cin>>l>>f;
    for (int i=0; i<=f; i++) prime[i] = 1;
    for (int i=2; i*i<=f; i++) if (prime[i]) {
        for (int j=i*i; j<=f; j+=i) {
            prime[j] = 0;
        }
    }

    if (l<=1) {
        cout<<1<<endl;
    }

    for (int i=f; i>=l; i--) {
        if (prime[i]) {
            cout<<i<<endl;
            return 0;
        }
    }
    int num = 10000000;
    int den = 1;
    for (int i=l; i<=f; i++) {
        int sum = 0;
        int t = i;
        for (int j=2; j*j<=t; j++) {
            if (t%j==0) {
                sum += j;
                if (j!=t/j) sum += t/j;
            }
        }
        sum++;
        if ((long long)sum*den<(long long)num*t) {
            num = sum;
            den = t;
        }
    }

    cout<<den<<endl;

    return 0;

}

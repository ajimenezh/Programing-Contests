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

bool check(long long n) {
    if (n<=1) return true;
    long long f1 = 1;
    long long f2 = 1;
    while (f1<n) {
        long long tmp = f1;
        f1 = f1+f2;
        f2 = tmp;
    }
    return f1==n;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        long long n;
        scanf("%lld", &n);
        if (check(n)) {
            printf("IsFibo\n");
        }
        else {
            printf("IsNotFibo\n");
        }
    }

    return 0;

}

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

int n;
int a[100010];

bool check(int k) {
    int l = n/k;
    if (l<3) return false;
    for (int i=0; i<k; i++) {
        bool good = 1;
        for (int j=i; j<n; j+=k) if (!a[j]) {
            good = 0;
            break;
        }
        if (good) return 1;
    }
    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    bool done = 0;
    for (int i=1; i*i<=n; i++) if (n%i==0) {
        if (check(i) || check(n/i)) {
            cout<<"YES"<<endl;
            done = 1;
            break;
        }
    }
    if (!done) cout<<"NO";

    return 0;

}

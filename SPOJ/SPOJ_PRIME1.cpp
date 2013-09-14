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
bool prime[100000];
bool prime2[100000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<100000; i++) prime[i] = 1;
    for (int i=2; i*i<100000; i++) if (prime[i]) {
        for (int j=i*i; j<100000; j+=i) prime[j] = 0;
    }
    while (n--) {
        int l,r;
        scanf("%d%d",&l,&r);
        for (int i=0; i<=(r-l); i++) prime2[i] = 1;
        for (int i=2; i<100000; i++) if (prime[i]) {
            int t = ((l-1)/i+1)*i;
            if (t>r) continue;
            if (t==i) t += i;
            for (int j=t; j<=r; j+=i) prime2[j-l] = 0;
        }
        for (int i=max(l,2); i<=r; i++) if (prime2[i-l]) printf("%d\n",i);
    }

    return 0;

}

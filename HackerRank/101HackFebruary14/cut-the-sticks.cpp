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

int a[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);

    for (int i=0; i<n; i++) {
        int k = 0;
        int m = 10000;
        for (int j=0; j<n; j++) if (a[j]!=0) m = min(a[j], m);
        for (int j=0; j<n; j++) {
            if (a[j]>=m) {
                a[j] -= m;
                k++;
            }
        }
        if (!k) break;
        printf("%d\n", k);
    }

    return 0;

}

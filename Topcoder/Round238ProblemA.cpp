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

int n;
bool a[1010][1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) scanf("%d", &a[i][j]);
    }

    int t = 0;
    for (int i=0; i<n; i++) {
        int tmp = 0;
        for (int j=0; j<n; j++) {
            tmp += a[i][j]*a[j][i];
        }
        t += (tmp%2);
        t %= 2;
    }

    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int p;
        scanf("%d", &p);
        if (p==3) printf("%d", t);
        else {
            int a;
            scanf("%d", &a);
            t = 1-t;
        }
    }

    return 0;

}

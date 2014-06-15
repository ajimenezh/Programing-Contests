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

int n,x;
int s[100010];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%d%d", &n, &x);
        for (int i=0; i<n; i++) scanf("%d", &s[i]);
        sort(s, s+n);
        int tot = 0;
        for (int i=0, j=n-1; i<=j; j--) {
            if (i==j) tot++;
            else {
                if (s[i]+s[j]<=x) {
                    tot++;
                    i++;
                }
                else {
                    tot++;
                }
            }
        }

        printf("Case #%d: %d\n", tt+1, tot);
    }


    return 0;

}

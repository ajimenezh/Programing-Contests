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

int res[101];
int m, n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        for (int j=0; j<n; j++) {
            int tmp = 0;
            int x,y;
            scanf("%d%d",&x,&y);
            if (x>y && a>b) tmp += 2;
            if (x<y && a<b) tmp += 2;
            if (x==y && a==b) tmp += 2;
            if (x-y==a-b) tmp += 3;
            if (x==a) tmp ++;
            if (y==b) tmp++;

            res[j] += tmp;
        }
    }

    for (int i=0; i<n; i++) {
        if (i!=0) cout<<" ";
        cout<<res[i];
    }

    return 0;

}

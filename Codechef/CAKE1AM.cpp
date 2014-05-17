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

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int x1,y1,x2,y2;
        int x3,y3,x4,y4;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
        int xm = min(min(x1,x2), min(x3,x4));
        int xM = max(max(x1,x2), max(x3,x4));
        int ym = min(min(y1,y2), min(y3,y4));
        int yM = max(max(y1,y2), max(y3,y4));

        int tot = 0;
        for (int i=xm; i<xM; i++) {
            if ((i>=x1 && i<x2) || (i>=x3 && i<x4)) {
                for (int j=ym; j<yM; j++) {
                    if ((j>=y1 && j<y2 && i>=x1 && i<x2) || (j>=y3 && j<y4 && i>=x3 && i<x4)) {
                        tot++;
                    }
                }
            }
        }
        printf("%d\n", tot);
    }

    return 0;

}

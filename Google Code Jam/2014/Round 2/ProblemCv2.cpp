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

int h,w, m;
int X0[1010], X1[1010], Y0[1010], Y1[1010];
int dist[1010][1010];
int c[1010];

int calc(int a, int b, int c, int d) {
    if (c>=a && c<=b) return 0;
    if (d>=a && d<=b) return 0;
    if (c<=a && d>=b) return 0;

    if (c>=b) return c-b;
    else return a-d;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>w>>h>>m;

        for (int i=0; i<m; i++) {
            int x0,y0,x1,y1;
            scanf("%d%d%d%d", &X0[i], &Y0[i], &X1[i], &Y1[i]);
            X1[i]++;
            Y1[i]++;
            dist[m][i] = X0[i];
            dist[i][m+1] = w - X1[i];
        }

        dist[m][m+1] = w;

        for (int i=0; i<m; i++) {
            for (int j=0; j<m; j++) {
                if (i==j) {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = max(calc(X0[i],X1[i],X0[j],X1[j]), calc(Y0[i],Y1[i],Y0[j],Y1[j]));
            }
        }

        for (int i=0; i<m+2; i++) c[i] = w+1;

        c[m] = 0;

        priority_queue<pair<int,int> > q;

        q.push(make_pair(0, m));

        while (!q.empty()) {
            int p = q.top().second;
            q.pop();
            if (p==m+1) break;

            //cout<<p<<endl;

            for (int i=0; i<m+2; i++) {
                //cout<<i<<" "<<c[i]<<" "<<p<<" "<<c[p]<<" "<<c[p]+dist[p][i]<<endl;
                if (c[i]>c[p] + dist[p][i]) {
                    c[i] = c[p] + dist[p][i];
                    q.push(make_pair(-c[i], i));
                }
            }
        }


        printf("Case #%d: %d\n", tt+1, c[m+1]);
    }

    return 0;

}

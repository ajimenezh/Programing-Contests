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

int n,m,k;
int pre[55][55];
int dist[55][55];
int q[55*55];
int in,fn;
pair<int,int> a[55*55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) dist[i][j] = -1;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) pre[i][j] = -1;
    dist[0][0] = 1;
    q[fn++] = 0;
    while (in<fn) {
        int p = q[in++];
        int x = p/m;
        int y = p%m;
        for (int i=0; i<4; i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if (dist[xx][yy]==-1) {
                dist[xx][yy] = dist[x][y] + 1;
                pre[xx][yy] = x*m+y;
                q[fn++] = xx*m+yy;
            }
        }
    }

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) a[i*m+j] = make_pair(dist[i][j], i*m+j);
    sort(a,a+n*m);

    int sum = 0;
    for (int i=k-1; i>=0; i--) sum += a[i].first;
    cout<<sum<<"\n";
    for (int i=k-1; i>=0; i--) {
        int p = a[i].second;
        vector<int> v;
        while (p!=-1) {
            v.push_back(p);
            p = pre[p/m][p%m];
        }
        reverse(v.begin(),v.end());
        for (int j=0; j<v.size(); j++) {
            printf("(%d,%d)",(v[j]/m)+1,(v[j]%m)+1);
            if (j!=v.size()-1) printf(" ");
            else printf("\n");
        }
    }

    return 0;

}

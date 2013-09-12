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

#define INF 1000000000LL

int dist[101][101][2];
vector<int> path[101][101][2];
int n, m;

vector<int> sum(vector<int> a, vector<int> b) {
    for (int i=0; i<b.size(); i++) a.push_back(b[i]);
    return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (true) {
        cin>>n;
        if (n==-1) break;
        cin>>m;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j][0] = INF;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j][1] = INF;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) path[i][j][0].clear();
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) path[i][j][1].clear();

        for (int i=0; i<m; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--; b--;
            if (dist[a][b][0]>c) {
                dist[a][b][1] = dist[a][b][0];
                dist[a][b][0] = c;
                dist[b][a][0] = dist[a][b][0];
                dist[b][a][1] = dist[a][b][1];
            }
            else if (dist[a][b][1]>c) {
                dist[a][b][1] = c;
                dist[b][a][0] = dist[a][b][0];
                dist[b][a][1] = dist[a][b][1];
            }
        }

    }


    return 0;

}

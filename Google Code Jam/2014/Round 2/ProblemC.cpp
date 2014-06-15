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

const int VM=101000;
const int EM=2000100;
const int INF=0x3f3f3f3f;

struct Edge{
    int to,nxt;
    int cap;
}edge[EM<<1];

int N,F,D,cnt,head[VM],src,des;
int dep[VM];

void init(int _n, int _src, int _dest) {
    N = _n;
    src = _src;
    des = _dest;
    for (int i=0; i<N; i++) head[i] = -1;
    cnt = 0;
}

void add_edge(int cu,int cv,int cw){
    edge[cnt].to=cv;    edge[cnt].cap=cw;   edge[cnt].nxt=head[cu];
    head[cu]=cnt++;
    edge[cnt].to=cu;    edge[cnt].cap=0;    edge[cnt].nxt=head[cv];
    head[cv]=cnt++;
}

int BFS(){
    queue<int> q;
    while(!q.empty())
        q.pop();
    memset(dep,-1,sizeof(dep));
    dep[src]=0;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].to;
            if(edge[i].cap>0 && dep[v]==-1){
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[des]!=-1;
}

int DFS(int u,int minx){
    if(u==des)
        return minx;
    int tmp;
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].to;
        if(edge[i].cap>0 && dep[v]==dep[u]+1 && (tmp=DFS(v,min(minx,edge[i].cap)))){
            edge[i].cap-=tmp;
            edge[i^1].cap+=tmp;
            return tmp;
        }
    }
    dep[u]=-1;
    return 0;
}

int Dinic(){
    int ans=0,tmp;
    while(BFS()){
        while(1){
            tmp=DFS(src,INF);
            if(tmp==0)
                break;
            ans+=tmp;
        }
    }
    return ans;
}


bool b[110][510];
int h,w, m;
int dx[] = {1,0,-1, 0};
int dy[] = {0,1,0, -1};

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>w>>h>>m;
        for (int i=0; i<w; i++) for (int j=0; j<h; j++) b[i][j] = 0;
        for (int i=0; i<m; i++) {
            int x0,y0,x1,y1;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            for (int x=x0; x<=x1; x++) {
                for (int y=y0; y<=y1; y++) {
                    b[x][y] = 1;
                }
            }
        }

        init(2*w*h+2, 2*w*h, 2*w*h+1);
        for (int i=0; i<w; i++) if (!b[i][0]) add_edge(src, i, 1);
        for (int i=0; i<w; i++) if (!b[i][h-1]) add_edge(h*w + (h-1)*w+i, des, 1);
        for (int i=0; i<w; i++) for (int j=0; j<h; j++) if (!b[i][j]) add_edge(j*w+i, w*h+j*w+i, 1);
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (!b[i][j]) {
                    for (int k=0; k<4; k++) {
                        int ii = i + dx[k];
                        int jj = j + dy[k];
                        if (ii<0 || ii>=w) continue;
                        if (jj<0 || jj>=h) continue;
                        if (b[ii][jj])  continue;
                        add_edge(h*w + j*w+i, jj*w+ii, 1);
                    }
                }
            }
        }

        int f = Dinic();

        printf("Case #%d: %d\n", tt+1, f);
    }

    return 0;

}

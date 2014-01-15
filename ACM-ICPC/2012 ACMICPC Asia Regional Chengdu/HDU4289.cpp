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

const int VM=1010;
const int EM=200010;
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

void addedge(int cu,int cv,int cw){
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

int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&m)!=EOF) {
        init(2*n+2,2*n,2*n+1);
        int s,t;
        scanf("%d%d",&s,&t);
        s--; t--;
        addedge(src,s,INF);
        addedge(t+n,des,INF);
        for (int i=0; i<n; i++) {
            int w;
            scanf("%d",&w);
            addedge(i,i+n,w);
        }
        for (int i=0; i<m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            u--; v--;
            addedge(u+n,v,INF);
            addedge(v+n,u,INF);
        }
        cout<<Dinic()<<endl;
    }

    return 0;

}

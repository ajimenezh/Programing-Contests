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

vector<pair<int,int> > e[200010];
int f[200010];
int n,m;
int q[1000000];
bool vis[200010];
map<pair<int,int>, int > sent;
pair<int,int> v[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        e[a].push_back(make_pair(b,c));
        e[b].push_back(make_pair(a,c));
        v[i] = make_pair(a,b);
    }

    for (int i=0; i<n; i++) {
        int c = 0;
        rep(it,e[i]) {
            c += (*it).second;
        }
        f[i] = c/2;
        if (i==n-1) f[i] = c;
    }

    //for (int i=0; i<n; i++) cout<<f[i]<<" "; cout<<endl;

    int in = 0, fn = 0;
    q[fn++] = 0;
    vis[0] = 1;

    while (in!=fn) {
        int p = q[in++];
        vis[p] = 1;
        //cout<<p+1<<endl;
        rep(it,e[p]) {
            if (!vis[(*it).first]) {
                f[(*it).first] -= (*it).second;
                if (f[(*it).first]==0) {
                    q[fn++] = (*it).first;
                }
                sent[make_pair(p,(*it).first)] = 1;
            }
        }
    }

    for (int i=0; i<m; i++) {
        if (sent.find(v[i])!=sent.end()) {
            printf("%d\n",0);
        }
        else {
            printf("%d\n",1);
        }
    }


    return 0;

}

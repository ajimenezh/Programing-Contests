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

int gcd(int a,int b) {if (b==0) return a; return gcd(b,a%b);}

struct edge {
    int in, fn, lcm, gcd;
    edge() {
        in = 0, fn = 0;
        lcm = 0, gcd = 0;
    }
    edge (int f, int b, int c, int d) {
        in  = f; fn = b; gcd = c; lcm = d;
    }
};

int n,m;
map<int,edge> e[101];
bool vis[101];
bool now[101];
vector<int> v;
int a[101];

void dfs(int p) {
    vis[p] = 1;
    v.push_back(p);
    rep(it,e[p]) if (!vis[(*it).first]) {
        dfs((*it).first);
    }
    return;
}


void solve(int i) {
    rep(it,e[i]) {
        if (a[(*it).first]==-1) {
            long long t = (long long)(*it).second.lcm*(long long)(*it).second.gcd;
            if (t%a[i]!=0) return;
            if (gcd(a[i],t/a[i])!=(*it).second.gcd ) return;
            t = t / a[i];
            a[(*it).first] = t;
            solve((*it).first);
        }
        if (a[(*it).first]!= -1 && gcd(a[i],a[(*it).first])!=(*it).second.gcd) {
            a[i] = -1;
            return;
        }
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int f,b,c,d;
        scanf("%d%d%d%d",&f,&b,&c,&d);
        f--; b--;
        e[f][b] = (edge(f,b,c,d));
        e[b][f] = (edge(b,f,c,d));
    }

    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) a[i] = -1;
    for (int i=0; i<n; i++) if (!vis[i]) {
        v.clear();
        dfs(i);
//        for (int ii=0; ii<v.size(); ii++) {
//            for (int jj=ii+1; jj<v.size(); jj++) {
//                for (int kk=jj+1; kk<v.size(); kk++) {
//                    if (connected(v[ii],v[jj],v[kk]) && a[v[ii]]==-1) {
//                        doit(v[ii],v[jj],v[kk]);
//                        solve(v[ii]);
//                        break;
//                    }
//                }
//            }
//        }

        if (v.size()==1) {
            a[v[0]] = 1;
        }
        else {
            for (int ii=0; ii<v.size(); ii++) if (a[v[ii]]==-1) {
                for (int jj=0; jj<v.size(); jj++) if (jj!=ii && e[v[ii]].find(v[jj])!=e[v[ii]].end()) {
                    long long t = (long long)e[v[ii]][v[jj]].lcm*(long long)e[v[ii]][v[jj]].gcd;
                    for (long long j = 1; j*j<=t; j++) if (gcd(j,t/j)==e[v[ii]][v[jj]].gcd) {
                        a[v[ii]] = j;
                        solve(v[ii]);
                        bool done = true;
                        for (int kk=0; kk<v.size(); kk++) if (a[v[kk]]==-1 || (kk==jj && a[v[jj]]!=t/j)) {
                            done = false;
                            for (int k=0; k<v.size(); k++) {
                                a[v[k]] = -1;
                            }
                            break;
                        }
                        if (done) break;

                        a[v[ii]] = t/j;
                        solve(v[ii]);
                        done = true;
                        for (int kk=0; kk<v.size(); kk++) if (a[v[kk]]==-1 || ((kk==jj && a[v[jj]]!=j))) {
                            done = false;
                            for (int k=0; k<v.size(); k++) {
                                a[v[k]] = -1;
                            }
                            break;
                        }
                        if (done) break;
                    }
                }
            }
        }
    }

    //for (int i=0; i<n; i++) cout<<a[i]<<endl;
    for (int i=0; i<n; i++) if (a[i]==-1) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for (int i=0; i<n; i++) printf("%d ",a[i]);


    return 0;

}

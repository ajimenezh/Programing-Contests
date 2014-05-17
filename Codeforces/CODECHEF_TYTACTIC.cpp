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

int n,m;
vector<int> e[100010];
int w[100010];
bool vis[100010];
int sum[100010];
int cnt;
int fr[100010];
int pre[100010];
int depth[100010];

int dfs(int p, int q=0) {
    vis[p] = 0;
    depth[p] = 1 + depth[q];
    sum[p] = w[p];
    for (int i=0; i<e[p].size(); i++) {
        dfs(e[p][i],p);
        sum[p] += sum[e[p][i]];
    }
    if (e[p].size()==1) fr[p] = cnt;
    else fr[p] = cnt++;
    return 0;
}

struct BIT{
    vector<pair<int,int> > v;
    map<int,int> ma;
    vector<int> val;
    int n;
    BIT(){
    };
    void add(int i) {
        v.push_back(make_pair(depth[i],i));
    }
    int getval(int x) {
        return get(ma[x]);
    }
    int get(int x) {
        int s = 0;
        for (int i=x; i>0; i -= i & -i) s += val[i-1];
        return s;
    }
    int update2(int x, int k) {
        update(ma[x],k);
        return v[n-1].second;
    }
    void update(int x, int k) {
        for (int i=x; i<=n; i+= i & -i) val[i-1] += k;
    }
    void make() {
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        n = v.size();
        for (int i=0; i<n; i++) ma[v[i].second] = i+1;
        val = vector<int> (n,0);
        for (int i=0; i<n; i++) update(i+1,sum[v[i].second]);
        cout<<n<<endl;
        for (int i=0; i<n; i++) cout<<val[i]<<" "; cout<<endl;
    }
};
vector<BIT> vb;
bool done[100010];
map<int,int> ind;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin>>n>>m;
    for (int i=0; i<n; i++) e[i].clear();
    for (int i=0; i<n; i++) scanf("%d",w+i);
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
    }
    for (int i=0; i<n; i++) vis[i] = 0;
    cnt = 0;
    dfs(0);
    for (int i=0; i<n; i++) cout<<fr[i]<<" "; cout<<endl;
    for (int i=0; i<n; i++) cout<<sum[i]<<" "; cout<<endl;
    for (int i=0; i<n; i++) cout<<depth[i]<<" "; cout<<endl;

    cnt = 0;
    for (int i=0; i<n; i++) {
        if (!done[fr[i]]) {
            done[i] = 1;
            ind[fr[i]] = cnt++;
            vb.push_back(BIT());
            vb[ind[fr[i]]].add(i);
        }
        else {
            vb[ind[fr[i]]].add(i);
        }
    }
    for (int i=0; i<cnt; i++) vb[i].make();

    for (int k=0; k<m; k++) {
        char c;
        scanf("%s",&c);
        if (c=='Q') {
            int a;
            scanf("%d",&a);
            a--;
            int ans = vb[ind[fr[a]]].getval(a);
            printf("%d\n",ans);
        }
        else {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b = b - w[a];
            int t = vb[ind[fr[a]]].update2(a,b);
            while (t!=0) {
                cout<<t<<endl;
                a = pre[t];
                t = vb[ind[fr[a]]].update2(a,b);
            }
        }
    }

    return 0;

}

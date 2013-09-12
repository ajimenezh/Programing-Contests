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
map<string,int> idx;
int val[100010];
string s;
int cnt;
int a;
int d[100010];
int last[100010];
int w[100010];
int w2[100010];
vector<int> nodes[100010];

int dfs(int p, int de) {
    d[p] = de;
    w[p] = cnt++;
    w2[cnt-1] = p;
    last[p] = cnt-1;
    rep(it,e[p]) {
        last[p] = dfs(*it,de+1);
    }
    return last[p];
}

struct ST{
    int N;
    vector<int> u;
    vector<vector<int> > v;
    ST(int _n,vector<int> _w) {
        N = _n;
        v = vector<vector<int> > (4*_n,vector<int> (0,0));
        u = _w;
        update(1,1,N);
    }
    ST() {
    }
    void update(int id, int l, int r) {
        if (l==r) {
            v[id].push_back(u[l-1]);
            return;
        }

        int h = (l+r)/2;
        update(2*id,l,h);
        update(2*id+1,h+1,r);
        for (int i=0; i<v[2*id].size(); i++) v[id].push_back(v[2*id][i]);
        for (int i=0; i<v[2*id+1].size(); i++) v[id].push_back(v[2*id+1][i]);
        sort(v[id].begin(),v[id].end());
    }
    int query(int l, int r, int ma) {
        //for (int i=0; i<v[1].size(); i++) cout<<v[1][i]<<" "; cout<<endl;
        return QUERY(1,1,N,l,r,ma);
    }
    int QUERY(int id, int l, int r, int lt, int rt, int ma) {
        if (l>rt || r<lt) return 0;
        if (l>=lt && r<=rt) {
            int s = upper_bound(v[id].begin(),v[id].end(),ma) - v[id].begin();
//            cout<<"DEBUG..."<<endl;
//            cout<<ma<<endl;
//            cout<<l<<" "<<lt<<" "<<rt<<" "<<r<<endl;
//            for (int i=0; i<v[id].size(); i++) cout<<v[id][i]<<" "; cout<<endl;
//            cout<<s<<" "<<v[id].size()<<endl;
//            cout<<"END...."<<endl;
            return (r-l+1) - s;
        }

        int h = (l+r)/2;
        int t = 0;
        t += QUERY(2*id,l,h,lt,rt,ma);
        t += QUERY(2*id+1,h+1,r,lt,rt,ma);
        return t;
    }
};
vector<ST> st;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>s>>a;
        if (!idx[s]) idx[s] = ++cnt;
        val[i+1] = idx[s];
        e[a].push_back(i+1);
    }

    cnt = 0;
    dfs(0,0);
    //for (int i=0; i<=n; i++) cout<<i<<" "<<w[i]<<" "<<last[i]<<endl;

    for (int i=0; i<=n; i++) {
        nodes[d[i]].push_back(w[i]);
    }
    for (int i=0; i<=n; i++) sort(nodes[i].begin(),nodes[i].end());
    for (int i=0; i<=n; i++) {
        if (nodes[i].size()==0) continue;
        vector<int> next;
        for (int j=0; j<nodes[i].size();j++) {
            next.push_back(nodes[i].size()+2);
        }
        vector<pair<int,int> > tmp;
        for (int j=0; j<nodes[i].size(); j++) tmp.push_back(make_pair(val[w2[nodes[i][j]]],j));
        sort(tmp.begin(),tmp.end());
        for (int j=0; j<tmp.size()-1; j++) {
            if (tmp[j+1].first==tmp[j].first) {
                next[tmp[j].second] = tmp[j+1].second;
            }
        }
        st.push_back(ST(next.size(),next));
    }

    int q;
    cin>>q;

    for (int qq=0; qq<q; qq++) {
        int v,k;
        scanf("%d%d",&v,&k);
        int dep = d[v] + k;
        if (dep>n) {
            printf("0\n");
            continue;
        }
        int l,r;
        l = lower_bound(nodes[dep].begin(),nodes[dep].end(),w[v]) - nodes[dep].begin();
        r = lower_bound(nodes[dep].begin(),nodes[dep].end(),last[v]) - nodes[dep].begin();

        //cout<<l<<" "<<r<<" "<<w[v]<<" "<<last[v]<<endl;
        //for (int i=0; i<nodes[dep].size(); i++) cout<<nodes[dep][i]<<" "; cout<<endl;


        if (r>=nodes[dep].size() || nodes[dep][r]>last[v]) r--;
        if (r<l) {
            printf("0\n");
        }
        else {
            int res = st[dep].query(l+1,r+1,r);
            //cout<<"SOLUCION:  "<<endl;
            printf("%d\n",res);
        }
    }

    return 0;

}

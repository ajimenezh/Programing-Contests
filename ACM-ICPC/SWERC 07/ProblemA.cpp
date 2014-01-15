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

int n;
struct node{
    int l, r;
    bool leaf;
    bool val;
    node() {
        leaf = 0;
        val = 0;
        l = -1;
        r = -1;
    }
};
struct tree{
    vector<node> v;
    int cnt;
    tree() {
        cnt = 1;
        v.clear();
        v.push_back(node());
    }
}tr[2];

void print(int t, int nd) {
    if (tr[t].v[nd].leaf) {
        cout<<nd<<"   "<<tr[t].v[nd].val<<endl;
    }
    else {
        cout<<nd<<"   "<<tr[t].v[nd].l<<" "<<tr[t].v[nd].r<<endl;
        print(t,tr[t].v[nd].l );
        print(t,tr[t].v[nd].r );
    }
}

int rec(int t, int nd) {
    if (tr[t].v[nd].leaf) {
        return tr[t].v[nd].val;
    }
    else {
        int t1 = rec(t,tr[t].v[nd].l );
        int t2 = rec(t,tr[t].v[nd].r );
        if (t1==-1 || t2==-1) return -1;
        if (t1!=t2) return -1;
        tr[t].v[nd].leaf = 1;
        tr[t].v[nd].val = t1;
        return t1;
    }
}


bool cmp[100010];
int next[100010];
int pass[100010];
int ret[100010];
map<int,int> id;
vector<int> ins;

int get(int p) {
    if (cmp[p] || ret[p]!=0) return p;
    next[p] = get(next[p]);
    return next[p];
}

void doit(int c, int t, int nd) {
    if (cmp[c]) {
        tr[t].v.push_back(node());
        tr[t].v.push_back(node());
        tr[t].v[nd].l = tr[t].cnt++;
        tr[t].v[nd].r = tr[t].cnt++;
        doit(next[c],t,tr[t].v[nd].l);
        doit(pass[c],t,tr[t].v[nd].r);
    }
    else if (ret[c]!=0) {
        tr[t].v[nd].leaf = 1;
        tr[t].v[nd].val = ret[c]-1;
    }
    else {
        doit(next[c],t,nd);
    }
}

bool same(int nd1, int nd2) {
    if (tr[0].v[nd1].leaf!=tr[1].v[nd1].leaf) return false;
    if (tr[0].v[nd1].leaf==1) {
        if (tr[0].v[nd1].val!=tr[1].v[nd1].val) return false;
        return true;
    }
    if (!same(tr[0].v[nd1].l,tr[1].v[nd2].l)) return false;
    return same(tr[0].v[nd1].r,tr[1].v[nd2].r);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::ios_base::sync_with_stdio (false);

    int cas;
    cin>>cas;
    while (cas--) {
        int tt;
        cin>>tt;
        while (tt--) {
            cin>>n;
            string s;
            tr[0] = tree();
            int last = -1;
            int cnt = 0;
            getline(cin,s);
            id.clear();
            ins.clear();
            while (getline(cin,s)&&s!="END") {
                int a,b;
                stringstream ss(s);
                ss>>a>>s;
                if (id.find(a)==id.end()) id[a] = cnt++;
                a = id[a];
                if (ss>>b) {
                    if (id.find(b)==id.end()) id[b] = cnt++;
                    b = id[b];
                }
                if (last!=-1) {
                    pass[last] = a;
                }
                last = a;
                if (s[0]=='B') {
                    next[a] = b;
                    cmp[a] = 1;
                    ret[a] = 0;
                }
                else if(s[0]=='J') {
                    next[a] = b;
                    cmp[a] = 0;
                    ret[a] = 0;
                }
                else {
                    ret[a] = 1 + s[3]-'0';
                    cmp[a] = 0;
                }
                ins.push_back(a);
            }
            for (int i=0; i<ins.size(); i++) {
                if (ret[ins[i]]==0) get(ins[i]);
            }
            doit(ins[0],0, 0);

            rec(0,0);
            //print(0,0);

            tr[1] = tree();
            last = -1;
            cnt = 0;
            id.clear();
            ins.clear();
            while (getline(cin,s)&&s!="END") {
                int a,b;
                stringstream ss(s);
                ss>>a>>s;
                if (id.find(a)==id.end()) id[a] = cnt++;
                a = id[a];
                if (ss>>b) {
                    if (id.find(b)==id.end()) id[b] = cnt++;
                    b = id[b];
                }
                if (last!=-1) {
                    pass[last] = a;
                }
                last = a;
                if (s[0]=='B') {
                    next[a] = b;
                    cmp[a] = 1;
                    ret[a] = 0;
                }
                else if(s[0]=='J') {
                    next[a] = b;
                    cmp[a] = 0;
                    ret[a] = 0;
                }
                else {
                    ret[a] = 1 + s[3]-'0';
                    cmp[a] = 0;
                }
                ins.push_back(a);
            }
            for (int i=0; i<ins.size(); i++) {
                if (ret[ins[i]]==0) get(ins[i]);
            }
            doit(ins[0],1, 0);

            rec(1,0);
            //print(1,0);

            if (same(0,0)) {
                cout<<"1\n";
            }
            else cout<<"0\n";
        }
        if (cas!=0) cout<<"\n";
    }

    return 0;

}

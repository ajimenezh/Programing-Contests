#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n,m;
vector<int> e[200010];
int a[200010];
vector<int> v1, v2;
int type[200010];
int ind[200010];
int l1[200010];
int r1[200010];
int l2[200010];
int r2[200010];
vector<int> st1, st2;

void dfs(int p, int q, int t) {
    if (t==0) {
        v1.push_back(a[p]);
        type[p] = 0;
        ind[p] = v1.size();
        l2[p] = v2.size()+1;
    }
    else {
        v2.push_back(a[p]);
        type[p] = 1;
        ind[p] = v2.size();
        l1[p] = v1.size()+1;
    }

    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) {
        dfs(e[p][i], p, 1-t);
    }

    if (t==0) {
        l1[p] = ind[p];
        r1[p] = v1.size();
        r2[p] = v2.size();
    }
    else {
        r1[p] = v1.size();
        l2[p] = ind[p];
        r2[p] = v2.size();
    }
}

void make_tree(vector<int> &st, int id, int l, int r, vector<int> &v) {
    if (l==r) {
        st[id] = v[l-1];
        return;
    }
    if (r<l) return;
    st[id] = 0;
    int h = (l+r)>>1;
    make_tree(st, 2*id, l, h, v);
    make_tree(st, 2*id+1, h+1, r, v);
}

void update(vector<int> &st, int id, int lt, int rt, int l, int r, int val) {
    if (rt<lt) return;
    if (l>rt || r<lt) return;
    if (l>r) return;
    if (l>=lt && r<=rt) {
        st[id] += val;
        return;
    }
    int h = (l+r)>>1;
    update(st, 2*id, lt, rt, l, h, val);
    update(st, 2*id+1, lt, rt, h+1, r, val);
}

int query(vector<int> &st, int id, int lt, int rt, int l, int r) {
    if (rt<lt) return 0;
    if (l>rt || r<lt) return 0;
    if (l>r) return 0;
    if (l>=lt && r<=rt) {
        return st[id];
    }
    int h = (l+r)>>1;
    return st[id] + query(st, 2*id, lt, rt, l, h) + query(st, 2*id+1, lt, rt, h+1, r);
}

void print_tree(vector<int> &st, int id, int l, int r) {
    if (l>r) return;
    cout<<id<<" "<<st[id]<<endl;
    if (l==r) return;
    int h = (l+r)>>1;
    print_tree(st, 2*id, l, h);
    print_tree(st, 2*id+1, h+1, r);
}

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%d", a+i);
    for (int i=0; i<n-1; i++) {
        int x,y;
        scanf("%d%d", &x, &y);
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(0, -1, 0);

    st1.resize(4*v1.size());
    st2.resize(4*v2.size());
    make_tree(st1, 1, 1, v1.size(), v1);
    make_tree(st2, 1, 1, v2.size(), v2);

    for (int i=0; i<m; i++) {
        int t;
        scanf("%d", &t);
        if (t==1) {
            int x, val;
            scanf("%d%d", &x, &val);
            x--;
            //cout<<x<<" "<<type[x]<<endl;
            if (type[x]==0) {
                update(st1, 1, l1[x], r1[x], 1, v1.size(), val);
                update(st2, 1, l2[x], r2[x], 1, v2.size(), -val);
            }
            else {
                //cout<<"hola"<<endl;
                update(st1, 1, l1[x], r1[x], 1, v1.size(), -val);
                //cout<<x<<" "<<l1[x]<<" "<<r1[x]<<endl;
                update(st2, 1, l2[x], r2[x], 1, v2.size(), val);
            }
            //cout<<"---"<<endl;
            //print_tree(st1, 1, 1, v1.size());
            //cout<<"--"<<endl;
        }
        else {
            int x;
            scanf("%d", &x);
            x--;
            int tot = 0;
            if (type[x]==0) {
                tot = query(st1, 1, ind[x], ind[x], 1, v1.size());
            }
            else {
                tot = query(st2, 1, ind[x], ind[x], 1, v2.size());
            }
            printf("%d\n", tot);
        }
    }

	return 0;
}

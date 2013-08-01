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

int n;
int v[50010];
int k[50010];
map<pii,int> mapa;
int le[50010], ri[50010], par[50010];

struct node {
	int val, key;
	node *l, *r;
	node() {}
	node (int val, int key): val(val), key(key), l(NULL), r(NULL) {}
};
typedef node * Node;

vector<Node> all;

class CartesianTree {
	public:
	
	void split(Node t, int val, Node &l, Node &r) {
		if (!t) {
			l = NULL;
			r = NULL;
		}
		else if (val < t->val) {
			split(t->l, val, l, t->l);
			r = t;
		}
		else {
			split(t->r, val, t->r, r);
			l = t;
		}
	}
	void insert(Node &t, Node &nd) {
		if (!t) t = nd;
		else if (nd->key > t->key) {
			split(t, nd->val, nd->l, nd->r);
			t = nd;
		}
		else {
			insert((nd->val < t->val) ? t->l : t->r, nd);
		}
	}
	void merge(Node &t, Node l, Node r) {
		if (!l || !r) t = (l ? l : r);
		else if (l->key > r->key) {
			merge(l->r, l->r, r);
			t = l;
		}
		else {
			merge(r->l, l, r->l);
			t = r;
		}
	}
	void erase(Node &t, int val) {
		if (t->val == val) merge(t, t->l, t->r);
		else erase((val<t->val)?t->l:t->r, val);
	}
	Node unite(Node l, Node r) {
		if (!l || !r) return (l?l:r);
		if (l->key<r->key) swap(l,r);
		Node lt,rt;
		split(r, l->val, lt, rt);
		l->l = unite(l->l, lt);
		l->r = unite(l->r, rt);
		return l;
	}
	void print(Node &t) {
		if (t) {
			print(t->l);
			print(t->r);
			
			if (t->l) {
				le[mapa[mp(t->val,t->key)]] = mapa[mp(t->l->val,t->l->key)];
				par[mapa[mp(t->l->val,t->l->key)]] = mapa[mp(t->val,t->key)];
			}
			if (t->r) {
				ri[mapa[mp(t->val,t->key)]] = mapa[mp(t->r->val,t->r->key)];
				par[mapa[mp(t->r->val,t->r->key)]] = mapa[mp(t->val,t->key)];
			}
		}
	}
}ct;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	Node root = new node(0,10000000);
	all.push_back(root);
	for (int i=0; i<n; i++) {
		scanf("%d%d",v+i,k+i);
		Node tmp = new node(v[i],-k[i]);
		//all.push_back(tmp);
		ct.insert(root, tmp);
		mapa[mp(v[i],-k[i])] = i+1;
	}

	ct.print(root);
	
	cout<<"YES"<<endl;
	for (int i=1; i<=n; i++) {
		cout<<par[i]<<" "<<le[i]<<" "<<ri[i]<<endl;
	}

    return 0;

}

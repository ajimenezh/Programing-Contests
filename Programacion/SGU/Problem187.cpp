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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define INF 1000000000

typedef struct node * pnode;
struct node {
	int prior, key, cnt;
	int sum,maxr,maxl,maxm;
	bool rev;
	int f;
	pnode l, r;
	node(int pr, int v, int c, pnode _l, pnode _r)
	{
	    prior = pr;
	    key = v;
	    f = -INF;
	    cnt = c;
	    l = _l;
	    r = _r;

	    sum = 0;
	    maxm = -INF;
	    maxl = -INF;
	    maxr = -INF;
	}
};

int cnt (pnode it) {
	return it ? it->cnt : 0;
}

int f (pnode it) {
	return it ? it->f : (-INF);
}

int sum (pnode it) {
	return it ? it->sum : 0;
}

int maxm (pnode it) {
	return it ? it->maxm : (-INF);
}

int maxr (pnode it) {
	return it ? it->maxr : (-INF);
}

int maxl (pnode it) {
	return it ? it->maxl : (-INF);
}

void upd (pnode it) {
	if (it)
	{
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
		it->f = max( f(it->l), f(it->r));
		if (it->f == -INF) it->f = it->key;

		it->sum = it->sum + sum(it->r) + sum(it->l);

		it->maxr = max(sum(it->r) + it->key + max(maxr(it->l),0), maxr(it->r));
		it->maxl = max(sum(it->l) + it->key + max(maxl(it->r),0), maxl(it->l));

		it->maxm = max(maxm(it->l), maxm(it->r));
		it->maxm = max(it->maxm, it->key + max(maxr(it->l) + maxl(it->r), 0));
		it->maxm = max(it->maxm, it->key + max(max(maxr(it->l), maxl(it->r)), 0));

	}
}

void push (pnode it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l)  it->l->rev ^= true;
		if (it->r)  it->r->rev ^= true;
	}
}

void merge (pnode & t, pnode l, pnode r) {

	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd(t);
	push(t);
}

void split (pnode t, pnode & l, pnode & r, int key, int add = 0) {
	if (!t)
        return void(l = r = 0);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd(t);
	push(t);
}

void insert(int pos, int val, pnode & root)
{
    pnode t = new node(rand(), val, 1, NULL, NULL);
    node *l, *r;

    split(root, l, r, pos, 0);

    merge(l, l, t);
    merge(root, l, r);

}

void erase_node(int pos, pnode & t, int add = 0)
{
	int cur_key = add + cnt( t->l );

	if (cur_key == pos)
		merge (t, t->l, t->r);
	else if (pos < cur_key)
		erase_node (pos,t->l,add);
	else
		erase_node (pos,t->r,cur_key+1);
}

int query(int a, int b, pnode root)
{
    pnode l, r, t;

    split(root, l, r, a, 0);
    split(r, r, t, b-a+1,0);

    int val = r->maxm;

    merge(root,l,r);
    merge(root,root,t);

    return val;
}


void reverse (pnode t, int l, int r) {
	pnode t1, t2, t3;
	split (t, t1, t2, l-1);
	split (t2, t2, t3, r-l+2);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void output (pnode t) {
	if (!t)  return;
	output (t->l);
	printf ("%d ", t->key);
	output (t->r);
}


void erase (pnode & t, int key) {
	if (t->key == key)
		merge (t, t->l, t->r);
	else
		erase (key < t->key ? t->l : t->r, key);
}

pnode unite (pnode l, pnode r) {
	if (!l || !r)  return l ? l : r;
	if (l->prior < r->prior)  swap (l, r);
	pnode lt, rt;
	split (r, lt, rt, l->key);
	l->l = unite (l->l, lt);
	l->r = unite (l->r, rt);
	return l;
}

void print(pnode & root, int pos)
{
    //cout << pos << endl;

    pnode l, r, mid;
    split(root, l, r, pos + 1, 0);
    split(l, l, mid, pos, 0);

    cout << mid->key ;

    merge(root, l, mid);
    merge(root, root, r);
}

int n;
int q;

int main() {

    cin>>n>>q;

    pnode root = new node(rand(), 0, 0, NULL, NULL);;
    
    for (int i=0; i<n; i++) insert(i+1,i+1,root);
    
    for (int i=0; i<q; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		reverse(root,a,b); 
		for (int j=0; j<n; j++) {print(root,j+1); cout<<" ";}
		cout<<endl;
	}

	return 0;

}

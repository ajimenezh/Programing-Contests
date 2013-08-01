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

#define MAXN 300010

int n;
int a[MAXN];
int id[MAXN];
int tree[4*MAXN];
int last[4*MAXN];
int first[4*MAXN];

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void init(int ind, int l, int r) {
	if (l==r) {
		tree[ind] = 0;
		first[ind] = id[l]; 
		last[ind] = id[l];
		return;
	}
	int h = (l+r)/2;
	init(2*ind,l,h);
	init(2*ind+1,h+1,r);
	
	tree[ind] = tree[2*ind] + tree[2*ind+1];
	first[ind] = first[2*ind];
	last[ind] = last[2*ind+1]; 
	if (first[2*ind+1]<last[2*ind]) tree[ind]++;
}

void update(int ind, int l, int r, int t, int v) {
	if (l>t || r<t) return;
	if (l==r && l==t) {
		first[ind] = v;
		last[ind] = v;
		return;
	}

	int h = (l+r)/2;
	
	update(2*ind,l,h,t,v);
	update(2*ind+1,h+1,r,t,v); 
	tree[ind] = tree[2*ind] + tree[2*ind+1];
	first[ind] = first[2*ind];
	last[ind] = last[2*ind+1];
	if (first[2*ind+1]<last[2*ind]) tree[ind]++;
	
	//cout<<ind<<" "<<tree[ind]<<endl;

}
		
int get(int ind, int l, int r, int x, int y) {
	if (l>y || r<x) return 0;
	if (l>=x && r<=y) return tree[ind];
	
	int tmp = 0;
	int h = (l+r)/2;
	tmp += get(2*ind,l,h,x,y);
	tmp += get(2*ind+1,h+1,r,x,y);
	
	if (h>=x && (h+1)<=y &&  first[2*ind+1]<last[2*ind]) tmp++;
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n; i++) id[a[i]] = i+1;
	init(1,1,n);
	int q;
	cin>>q;
	
	for (int i=0; i<q; i++) {
		int t;
		scanf("%d",&t);
		if (t==2) {
			int u,v;
			scanf("%d%d",&u,&v);
			u--; v--;
			int tmp = id[a[u]];
			update(1,1,n,a[u],id[a[v]]); 
			id[a[u]] = id[a[v]];
			update(1,1,n,a[v],tmp); 
			id[a[v]] = tmp;
			swap(a[u],a[v]);
		}
		else {
			int x,y;
			scanf("%d%d",&x,&y);
			int tot = 0;
			tot = get(1,1,n,x,y)+1;
			printf("%d\n",tot);
		}
	}

    return 0;

}

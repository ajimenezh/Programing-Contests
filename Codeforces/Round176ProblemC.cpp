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
int p[1000010];
int v[1000010];
int cnt;
map<int,int> m;
int vis[1000010];
int last[1000010];
int next[1000010];
int l[1000010];
int r[1000010];
int beg[1000010];
int ind[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",p+i);
	for (int i=0; i<n; i++) v[i] = p[i];
	sort(v,v+n);
	for (int i=0; i<n; i++) {
		if (i==0) {ind[cnt] = v[i];m[v[i]] = cnt++;}
		else {
			if (v[i]!=v[i-1]) {ind[cnt] = v[i];m[v[i]] = cnt++;}
		}
	}
	for (int i=0; i<n; i++) p[i] = m[p[i]];
	
	for (int i=0; i<cnt; i++) vis[i] = -1;
	for (int i=0; i<n; i++) next[i] = -1;
	for (int i=0; i<n; i++) last[i] = -1;
	
	for (int i=0; i<n; i++) {
		if (vis[p[i]] == -1) {
			vis[p[i]] = i;
			last[i] = -1;
			beg[p[i]] = i;
		}
		else {
			int tmp = vis[p[i]];
			last[i] = tmp;
			next[tmp] = i;
			vis[p[i]] = i;
		}
	} 
	
	for (int i=0; i<n; i++) v[i] = 1;
	
	int t; cin>>t;
	for (int i=0; i<t; i++) {
		int a;
		scanf("%d",&a);
		v[a-1] = -v[a-1];
	}
		
	
	for (int i=0; i<cnt; i++) {
		int j = beg[i];
		int end;
		int c = 1;
		while (next[j]!=-1) {
			c++;
			j = next[j];
		}
		end = j;
		for (int k=0; k<c; k++) l[i] = 0;
		for (int k=0; k<c; k++) r[i] = 0;
	
		j = beg[i];
		int k = 0;
		while (j!=-1) {
			if (k>0) l[k] = l[k-1] + v[j];
			else l[k] = v[j];
			if (l[k]<0) {
				cout<<"NO"<<endl;
				return 0;
			}
			j = next[j];
			k++;
		}
		j = end;
		k = 0;
		while (j!=-1) {
			if (k==0) {
				r[k] = v[j];
				if (v[j]<0) {
					if (l[c-1]!=0) {
						cout<<"NO"<<endl;
						return 0;
					}
				}
				else {
					if (l[c-1]!=2) {
						cout<<"NO"<<endl;
						return 0;
					}
					else {
						v[j] = -1;
						l[c-1]--;
						r[k] = v[j];
					}
				}
			}
			else {
				if (v[j]<0) {
					if (l[c-1-k]+r[k-1]!=0) {
						cout<<"NO"<<endl;
						return 0;
					}
				}
				else {
					if (l[c-1-k]+r[k-1]==0) {
						;
					}
					else if (l[c-1-k]+r[k-1]!=2) {
						cout<<"NO"<<endl;
						return 0;
					}
					else {
						v[j] = -1;
						l[c-1]--;
					}
				}
				r[k] = r[k-1] + v[j];
			}
			j = last[j];
			k++;
		}
	}
	
	cout<<"YES"<<endl;
	for (int i=0; i<n; i++) printf("%d ",v[i]*ind[p[i]]);

    return 0;

}

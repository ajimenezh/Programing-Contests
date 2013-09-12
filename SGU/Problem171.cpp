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

int k;
int n;
int num[110];
int p[110];
int q[16010];
int w[16010];
int id[16010];
vector<pii> v;
int ind[16010];

bool cmp(int i, int j) {
	return w[i]>w[j];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>k;
	for (int i=0; i<k; i++) scanf("%d",num+i);
	for (int i=0; i<k; i++) scanf("%d",p+i);
	for (int i=0; i<k; i++) n += num[i];
	for (int i=0; i<n; i++) scanf("%d",q+i);
	for (int i=0; i<n; i++) scanf("%d",w+i);
	
	for (int i=0; i<n; i++) id[i] = i;
	sort(id,id+n,cmp);
	
	for (int i=0; i<k; i++) v.push_back(make_pair(p[i],i));
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	for (int i=0; i<n; i++) {
		bool ok = 0;
		for (int j=0; j<k; j++) {
			if (num[v[j].second]>0 && q[id[i]]>v[j].first) {
				ok = 1;
				num[v[j].second]--;
				ind[id[i]] = v[j].second;
				break;
			}
		}
		if (!ok) {
			for (int j=0; j<k; j++) {
				if (num[v[j].second]>0) {
					num[v[j].second]--;
					ind[id[i]] = v[j].second;
					break;
				}
			}
		}
	}
	
	for (int i=0; i<n; i++) cout<<ind[i]+1<<" ";

    return 0;

}

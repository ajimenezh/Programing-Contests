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

int n;
int h[100010];
int beg[100010];
int end[100010];

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

   	cin>>n;
   	for (int i=0; i<n; i++) scanf("%d",&h[i]);

   	for (int i=0; i<100005; i++) beg[i] = 0;

   	for (int i=0; i<(n+1)/2; i++) if (h[i]-i>0) beg[h[i]-i]++;
   	for (int i=(n+1)/2; i<n; i++) if (h[i]-(n-1-i)>0) end[h[i]-(n-1-i)]++;

   	int res = 0;
   	for (int i=0; i<100005; i++) res = max(res,beg[i]+end[i]);

   	cout<<n-res;


	return 0;

}

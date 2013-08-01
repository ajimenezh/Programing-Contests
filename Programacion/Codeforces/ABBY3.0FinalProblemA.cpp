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
map<int,int> last;
long long sum[MAXN];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	
	int p = -1;
	long long best = -1LL<<60;
	for (int i=0; i<n; i++) {
		if (last.find(a[i])==last.end()) last[a[i]] = i;
		else {
			long long t = sum[i-1] - (last[a[i]]>0?sum[last[a[i]]-1]:0) + (long long)a[i];
			if (a[i]<0) t += a[i];
			if (t>best) {
				best = t;
				p = i;
			}
		}
		sum[i] = (i>0?sum[i-1]:0) + (long long)max(a[i],0);
	}
	
	cout<<best;
	int k = 0;
	for (int i=last[a[p]]+1; i<p; i++) if (a[i]<0) k++;
	k += last[a[p]];
	k += (n-p-1);
	cout<<" "<<k<<endl;
	for (int i=0; i<last[a[p]]; i++) cout<<(i+1)<<" ";
	for (int i=last[a[p]]+1; i<p; i++) if (a[i]<0) cout<<i+1<<" ";
	for (int i=p+1; i<n; i++) cout<<(i+1)<<endl;

    return 0;

}

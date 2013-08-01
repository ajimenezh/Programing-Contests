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

int k,b,n;
int a[100010];
long long res;
map<int,int> cnt;
int sum[100010];

int dr(int a, int b) {
	if (a<0) a += (k-1);
	if (a==0) return 0;
	a = a%(b-1);
	if (a==0) a = k-1;
	return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>k>>b>>n;
	for (int i=1; i<=n; i++) scanf("%d",a+i);
	
	long long zer = 0;
	int now = 0;
	for (int i=1; i<=n; i++) sum[i] = (sum[i-1]+a[i])%(k-1);
	cnt[0]++;
	for (int i=1; i<=n; i++) {;

		int t = sum[i] - b + (k-1);
		t %= k-1;
		res += cnt[t];
		
		cnt[sum[i]]++;
		
		if (a[i]==0) zer += ++now;
		else now = 0;
	}
	
	if (b==0) cout<<zer<<endl;
	else if (b==k-1) cout<<(res-zer)<<endl;
	else cout<<res<<endl;

    return 0;

}

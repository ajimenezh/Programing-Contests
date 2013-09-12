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

bool isprime[1000010];
int cnt;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=2; i<=n; i++) isprime[i] = 1;
	for (int i=2; i*i<=n; i++) if (isprime[i]) {
		for (int j=i*i; j<=n; j += i) isprime[j] = 0;
	}

	int t = 0;
	for (int i=0; i<=n; i++) if (isprime[i]) {
		if (i+2<=n && isprime[i+2]) {
			t++;
		}
	}
	cout<<t<<endl;
	for (int i=0; i<=n; i++) if (isprime[i]) {
		if (i+2<=n && isprime[i+2]) {
			printf("%d %d\n",2,i);
		}
	}

    return 0;

}

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

long long n;
long long t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	long long ans = 1;
	
	cin>>n;
	
	t = 1;
	
	while (t<=n/3) {
		t *= 3;
		if (n%t!=0) {
			ans = n/t + 1;
			break;
		}
	}
	
	cout<<ans<<endl;

    return 0;

}

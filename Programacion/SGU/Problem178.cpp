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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	long long n;
	cin>>n;
	if (n==1) {
		cout<<0<<endl;
		return 0;
	}
	long long t = 1;
	long long c = 0;
	while (n>=2*t-1) {
		c++;
		n -= 2*(t)-1;
		t += 2*(t)-1;
	}
	
	cout<<c<<endl;

    return 0;

}

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
bool good[10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t = 0;
	cin>>n;
	for (int i=1; i<=9; i++) {
		long long p = 0;
		for (int k=0; k<n-1; k++) p = (p*10 + 1)%i;
		p = (10*p + i)%i;
		if (p==0) good[i] = 1;
	}
	for (int i=1; i<9; i++) if (good[i] && good[i+1]) t++;
	
	cout<<t<<endl;

    return 0;

}

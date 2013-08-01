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

unsigned int v[10000000];
int l,r;
int c;
int cnt;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>l>>r;
	
	for (int i=3; i*i<=r; i+=2) if ((v[i>>5]&(1<<(i&31)))==0) {
		for (int j=i*i; j<=r; j+=i) {
			v[j>>5] |= (1<<(j&31));
		}
	}
	if (l%2==0) l++;
	for (int i=max(l,3); i<=r; i+=2) if ((v[i>>5]&(1<<(i&31)))==0) {
		if ((i&3)==1) cnt++;
	}
	if (l<=2 && r>=2) cnt++;
	cout<<cnt;

    return 0;

}

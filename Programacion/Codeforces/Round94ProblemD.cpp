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
int a[100010];
map<int,int> c;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n; i++) {
		if (c.find(a[i])==c.end()) c[a[i]] = 1;
		else c[a[i]]++;
	}
	
	int m = 1000000000;
	for (int i=0; i<n; i++) m = min(a[i],m);
	
	int p = m;
	int q = p;
	int k = 1;
	c[p]--;
	while (k<n) {
		if (c[p+1]>0) {
			p++;
			c[p]--;
			k++;
		}
		else {
			if (p!=0 && c[p-1]>0) {
				p--;
				c[p]--;
				k++;
			}
			else break;
		}
	}
	
	if (k==n && abs(p-q)==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 

    return 0;

}

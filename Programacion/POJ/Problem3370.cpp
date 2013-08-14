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

int n,m;
int a[100010];
int last[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n>>m && n!=0) {
		for (int i=0; i<m; i++) scanf("%d",a+i);
		for (int i=0; i<m; i++) a[i] %= n;
		for (int i=0; i<n; i++) last[i] = -1;
		
		int sum = 0;
		bool done = 0;
		for (int i=0; i<m; i++) {
			sum = (sum+a[i])%n;
			if (last[sum]!=-1) {
				for (int j=last[sum]+1; j<=i; j++) {
					cout<<j+1<<" ";
				}
				cout<<endl;
				done = 1;
				break;
			}
			if (sum==0) {
				for (int j=0; j<=i; j++) {
					cout<<j+1<<" ";
				}
				cout<<endl;
				done = 1;
				break;
			}
			last[sum] = i;
		}
		
		if (!done) cout<<"no sweets"<<endl;
	}
	
    return 0;

}

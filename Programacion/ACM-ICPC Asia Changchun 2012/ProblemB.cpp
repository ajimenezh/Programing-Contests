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
int a[5];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n) {
		for (int i=0; i<n; i++) scanf("%d",a+i);
		
		int res = 0;
		
		for (int i=0; i<min(1<<n); i++) {
			int c = 0;
			if (__builtin_popcount(i)>3) continue;
			if (__builtin_popcount(i)<3) {
				;
			}
			else {
				int sum = 0;
				for (int j=0; j<n; j++) if ((1<<j)&i) sum += a[j];
				//cout<<i<<" "<<sum<<endl;
				if (sum==0 || sum%1024!=0) continue;
			}
			int sum2 = 0;
			int k = 2;
			
			for (int j=0; j<n; j++) if (((1<<j)&i)==0) {
				sum2 += a[j];
				k--;
			}
			if (k<0) continue;
			
			//cout<<i<<" "<<k<<" "<<c<<" "<<sum2<<endl;
		
			if (k!=0) {
				res = max(res,1024);
			}
			else {
				if (sum2==0) continue;
				sum2 %= 1024;
				if (sum2==0) sum2 = 1024;
				res = max(res,sum2);
			}
		}
		
		printf("%d\n", res);
	}

    return 0;

}

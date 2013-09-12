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
int cnt[10];

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n) {
		for (int i=0; i<10; i++) cnt[i] = 0;
		
		long long t = 0;
		
		int k = 1;
		while (true) {
			t += n;
			long long tmp = t;
			while (tmp>0) {
				cnt[tmp%10]++;
				tmp /= 10;
			}
			bool ok = 1;
			for (int i=0; i<10; i++) if (cnt[i]==0) {
				ok = 0;
				break;
			}
			if (ok) {
				cout<<k<<endl;
				break;
			}
			k++;
		}
	}
	
    return 0;

}

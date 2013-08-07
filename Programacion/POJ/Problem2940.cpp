//Ulm Local 2006
//Problem: Wine Trading in Gergovia
//
// Solution: Greedy with a stack which have houses with ai<0 left of
//			current house

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
vector<int> st;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n) {
		for (int i=0; i<n; i++) scanf("%d",a+i);
		
		st.clear();
		
		long long cost = 0;
		for (int i=0; i<n; i++) {
			if (a[i]<0) {
				st.push_back(i);
			}
			else if (a[i]>0) {
				while (a[i]>0) {
					if (st.size()>0) { 
						int tmp = min(a[i], -a[st.back()]);
						cost += (long long)tmp*(i - st.back());
						a[i] -= tmp;
						a[st.back()] += tmp;
						if (a[st.back()]==0) st.pop_back();
					}
					else {
						a[i+1] += a[i];
						cost += a[i];
						a[i] = 0;
					}
				}
			}
		}
		
		cout<<cost<<endl;
	}
						
						
		
	
    return 0;

}

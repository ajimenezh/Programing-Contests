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
int a[10010];
bool inc[10010];
int v[10010];
long long sum;
long long sum2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int c = 0;
	cin>>n; 
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n; i++) sum += a[i];
	for (int i=0; i<n; i++) {
		v[i] = (a[i]*100)/sum;
		sum2 += v[i];
		if ((a[i]*100)%sum!=0) {
			c++;
			inc[i] = 1;
		}
	}
	
	if (sum2+c<sum) cout<<"No solution"<<endl;
	
	for (int i=0; i<n; i++) {
		if (c==0) break;
		if (inc[i] && v[i]!=99) {
			v[i]++;
			c--;
		}
	}
	
	for (int i=0; i<n; i++) {
		printf("%d",v[i]);
		if (i!=n-1) printf(" ");
	}

    return 0;

}

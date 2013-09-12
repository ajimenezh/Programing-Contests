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
#include <bitset>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int x[3010];
int y[3010];
int n;
pair<int,int> v[5000000];
bitset<3000> bs[3000];

int dist(int a, int b) {
	return a*a + b*b;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
	int k = 0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			v[k++] = make_pair((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]),i*n+j);
		}
	}
	sort(v,v+k);

	for (int i=k-1; i>=0; i--) {
		if ((bs[v[i].second/n]&bs[v[i].second%n])!=0) {
			printf("%.16lf",0.5*sqrt((double)v[i].first));
			return 0;
		}
		bs[v[i].second/n][v[i].second%n] = 1;
		bs[v[i].second%n][v[i].second/n] = 1;
	}
	
	cout<<0.0<<endl;
	
    return 0;

}

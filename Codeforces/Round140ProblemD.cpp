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
int t[110][110];
int t1[110][110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&t[i][j]);
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) t1[i][j] = t[i][j];
	
	vector<int> v;
	
	for (int i=0; i<n; i++) {
		int s = 0;
		for (int j=0; j<m; j++) s += t1[i][j];
		if (s<0) {
			for (int j=0; j<m; j++) t1[i][j] = -t1[i][j];
			v.push_back(i+1);
		}
	}
	bool good = 1;
	for (int j=0; j<m; j++) {
		int s = 0;
		for (int i=0; i<n; i++) s += t1[i][j];
		if (s<0) good = 0;
	}
	if (good) {
		cout<<v.size()<<" ";
		for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";
		cout<<endl;
		cout<<0<<endl;
		return 0;
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) t1[i][j] = t[i][j];
	
	v.clear();
	
	for (int i=0; i<m; i++) {
		int s = 0;
		for (int j=0; j<n; j++) s += t1[j][i];
		if (s<0) {
			for (int j=0; j<n; j++) t1[j][i] = -t1[j][i];
			v.push_back(i+1);
		}
	}
	good = 1;
	for (int j=0; j<n; j++) {
		int s = 0;
		for (int i=0; i<m; i++) s += t1[j][i];
		if (s<0) good = 0;
	}
	if (good) {
		cout<<v.size()<<" ";
		for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";
		cout<<endl;
		cout<<0<<endl;
		return 0;
	}
	
	cout<<0<<endl<<0<<endl;

    return 0;

}

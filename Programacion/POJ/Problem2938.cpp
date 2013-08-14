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
int t[1010];
int parse(string s) {
	int m = (s[0]-'0')*10 + (s[1]-'0');
	int d = (s[3]-'0')*10 + (s[4]-'0');
	int h = (s[6]-'0')*10 + (s[7]-'0');
	int min = (s[9]-'0')*10 + (s[10]-'0');
	
	return m*31*24*60 + d*24*60 + h*60 + m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n && n) {
		for (int i=0; i<n; i++)
	
    return 0;

}

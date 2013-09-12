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

int z[260000];

void compute_prefix_function(string pattern) {
    int k = -1;
    int i = 1;
    z[0] = k;
    for (i=1;i<pattern.length(); i++) {
        while (k > -1 && pattern[k+1] != pattern[i])
			k = z[k];
		if (pattern[i] == pattern[k+1])
			k++;
		z[i] = k;
    }
}

int kmp(string target, string pattern) {
    int i;
    compute_prefix_function(pattern);
    int k = -1;
    for (i = 0; i < target.length(); i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = z[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == pattern.length() - 1) {
			return i-k;
		}
	}
	return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    string s, t;
    cin>>n;
    cin>>s>>t;
    t = t+t;

    int i = kmp(t,s);

    cout<<i<<endl;

    return 0;

}

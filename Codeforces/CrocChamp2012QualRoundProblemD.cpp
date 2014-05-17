#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

int a,n,m;
int top[10000010];

int main() {

    cin>>a>>n;
    m = a+n+1;

    //for(int i=0; i<pr.size(); i++) cout<<pr[i]<<" "; cout<<endl;

    for (int i=1; i*i<=m; i++) {
        for (int j=1; j*i*i<=m; j++) top[j*i*i] = i*i;
    }
    long long tot = 0;
    for (int i=a; i<a+n; i++) {
        tot += i/top[i];
    }
    cout<<tot<<endl;

	return 0;

}


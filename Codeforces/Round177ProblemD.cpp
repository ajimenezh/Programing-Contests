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

int lo[80010];
int hi[80010];
int n;
vector<int> e[80010];
long long res;
int k;
int si[80010];

int dfs(int p, int q) {

    si[p] = 1;

    rep(it,e[p]) if (*it!=q) {
        si[p] +=dfs(*it,p);
    }

    k++;
    res = res + (long long)(n-k)*(long long)(n-1-k)*(long long)(si[p]-1);
    //cout<<(n-k-1)<<" "<<(k-1)<<" "<<res<<endl;
    return si[p];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int a,b;
    for (int i=0; i<n-1; i++) {
        scanf("%d%d",&a,&b);
        a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(0,-1);

    cout<<res;

    return 0;

}

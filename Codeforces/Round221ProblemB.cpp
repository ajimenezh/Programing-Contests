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

int n,m;
char a[5010][5010];
int next[5010][5010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%s", a[i]);

    for (int i=0; i<n; i++) {
        next[i][m] = m;
        for (int j=m-1; j>=0; j--) {
            if (a[i][j]=='0') next[i][j] = j;
            else next[i][j] = next[i][j+1];
        }
    }

    int res = 0;
    for (int i=0; i<m; i++) {
        vector<int> v;
        for (int j=0; j<n; j++) {
            if (next[j][i]!=i) v.push_back(next[j][i]-i);
        }
        sort(v.begin(),v.end());
        for (int j=0; j<v.size(); j++) res = max(res, v[j]*((int)v.size()-j));
    }

    cout<<res<<endl;

    return 0;

}

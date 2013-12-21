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

int n;
vector<int> v[100010];
vector<int> w[100010];
vector<int> sol;
int ans;

int dfs(int p, int pre, int k) {
    int sum = 0;
    for (int i=0; i<v[p].size(); i++) {
        if (v[p][i]==pre) continue;
        sum += dfs(v[p][i], p, i);
    }
    if (pre==-1) return 0;
    if (sum==0 && w[pre][k]==2) {
        ans++;
        sol.push_back(p+1);
        return sum+1;
    }
    if (w[pre][k]==2) return sum+1;
    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        a--; b--;
        v[a].push_back(b);
        w[a].push_back(t);
        v[b].push_back(a);
        w[b].push_back(t);
    }

    dfs(0,-1, -1);

    cout<<ans<<endl;
    for (int i=0; i<ans; i++) cout<<sol[i]<<" ";

    return 0;

}

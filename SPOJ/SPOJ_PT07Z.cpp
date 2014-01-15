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
vector<int> e[10010];
int ans;

int dfs(int a, int pre) {
    int t1 = -1, t2 = -1;
    for(int i=0; i<e[a].size(); i++) if (e[a][i]!=pre) {
        int tmp = dfs(e[a][i],a);
        if (t1==-1) t1 = tmp+1;
        else {
            if (tmp+1>t1) {
                if (t2==-1 || t2<t1) t2 = t1;
                t1 = tmp + 1;
            }
            else if (t2==-1 || t2<tmp+1) t2 = tmp+1;
        }
    }
    if (t1==-1) t1 = 0;
    if (t2==-1) t2 = 0;
    ans = max(ans, t1+t2);
    return t1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    ans = max(ans, dfs(0,-1));

    cout<<ans<<endl;

    return 0;

}


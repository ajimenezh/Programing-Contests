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
int x;
int a[1001];
int last[1001];
int next[1001];
vector<int> v;
bool dp[1001][1001];

int sol[1001];

void solve(int i, int p) {
    if (i==v.size()) {
        sol[p] = 1;
        return;
    }
    if (dp[i][p]) return;

    solve(i+1,p);
    solve(i+1,p+v[i]);

    sol[p] = 1;
    sol[p+v[i]] = 1;

    dp[i][p] = 1;
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>x;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    for (int i=0; i<n; i++) last[i] = i;

    for (int j=0; j<n; j++) {
        if (a[j]==0) {
            next[j] = j;
        }
        else {
            next[j] = a[j]-1;
            last[a[j]-1] = j;
        }
    }
    //for (int i=0; i<n; i++) cout<<last[i]<<" "; cout<<endl;
    //for (int i=0; i<n; i++) cout<<next[i]<<" "; cout<<endl;

    int pos;

    for (int i=0; i<n; i++) if (last[i] == i) {
        int p = 0;
        int t = -1;
        int now = i;
        //cout<<now<<endl;
        while (true) {
            if (now==x-1) {
                t = p + 1;
            }
            p++;
            if (next[now]==now) break;
            now = next[now];
        }
        //cout<<p<<" "<<t<<endl;
        if (t==-1) v.push_back(p);
        else {
            pos = p - t;
        }
    }

    sort(v.begin(),v.end());

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[i][j] = 0;

    for (int i=0; i<n; i++) sol[i] = 0;

    solve(0,pos);

    for (int i=0; i<n; i++) if (sol[i]) printf("%d\n",i+1);

    return 0;

}

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

int n,k;
int a[5001];
pair<int,int> v[15000010];
int next[15000010];
int start[1000001];
int fin[1000001];
bool vis[5001];
int q[5001];
int cnt;

int dfs(int i, int b) {
        if (b<0) return -1;
        for (int j=i; j<=1000001; j+=i) {
            if (start[j]>=0) {
                int p = start[j];
                while (p!=-1) {
                    if (!vis[v[p].first]&&!vis[v[p].second]) {
                        vis[v[p].second] = 1;

                        if (dfs(i,b-1)>0) return 1;

                        vis[v[p].second] = 0;
                        vis[v[p].first] = 1;

                        if (dfs(i,b-1)>0) return 1;
                        vis[v[p].first] = 0;

                        return -1;

                    }
                    p = next[p];
                }
            }
        }
        return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&k);
    for (int i=0; i<n; i++) scanf("%d",a+i);
    sort(a,a+n);

    if (n<=k+1) {
        cout<<1;
        return 0;
    }

    for (int i=0; i<=1000001; i++) start[i] = -1;
    for (int i=0; i<=1000001; i++) next[i] = -1;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int dif = a[j]-a[i];
            if (start[dif]==-1) {
                start[dif] = cnt;
                v[cnt] = make_pair(j,i);
                fin[dif] = cnt;
                cnt++;
            }
            else {
                next[fin[dif]] = cnt;
                v[cnt] = make_pair(j,i);
                fin[dif] = cnt;
                cnt++;
            }
        }
    }

    for (int i=1; i<=1000001; i++) {
        if (dfs(i,k)!=-1) {
            cout<<i;
            break;
        }
    }

    return 0;

}

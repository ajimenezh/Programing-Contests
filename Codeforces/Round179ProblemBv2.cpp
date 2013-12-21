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
int c[505][505];
int v[505];
long long dist[505][505];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        scanf("%d",&c[i][j]);
    }
    for (int i=0; i<n; i++) {
        int k;
        cin>>k;
        v[i] = k-1;
    }
    vector<long long> ans;

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j] = 1000000000000000LL;
    for (int i=0; i<n; i++) dist[i][i] = 0;

    ans.push_back(0);
    for (int i=n-2; i>=0; i--) {
        for (int j=n-1; j>i; j--) {
            dist[v[i]][v[j]] = c[v[i]][v[j]];
            dist[v[j]][v[i]] = c[v[j]][v[i]];
            for (int k=n-1; k>i; k--) {
                dist[v[i]][v[j]] = min(dist[v[i]][v[k]] + dist[v[k]][v[j]], dist[v[i]][v[j]]);
                dist[v[j]][v[i]] = min(dist[v[j]][v[k]] + dist[v[k]][v[i]], dist[v[j]][v[i]]);
            }
        }
        for (int j=n-1; j>i; j--) {
            for (int k=n-1; k>i; k--) {
                dist[v[i]][v[j]] = min(dist[v[i]][v[k]] + dist[v[k]][v[j]], dist[v[i]][v[j]]);
                dist[v[j]][v[i]] = min(dist[v[j]][v[k]] + dist[v[k]][v[i]], dist[v[j]][v[i]]);
            }
        }
        for (int j=n-1; j>i; j--) {
            for (int k=n-1; k>i; k--) {
                dist[v[j]][v[k]] = min(dist[v[j]][v[i]] + dist[v[i]][v[k]], dist[v[j]][v[k]]);
                dist[v[k]][v[j]] = min(dist[v[k]][v[i]] + dist[v[i]][v[j]], dist[v[k]][v[j]]);
            }
        }
        long long sum = 0;
        for (int j=n-1; j>=i; j--) {
            for (int k=n-1; k>=i; k--) {
                //cout<<v[j]<<" "<<v[k]<<" "<<dist[v[j]][v[k]]<<endl;
                sum += dist[v[j]][v[k]];
            }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" "; cout<<endl;

    return 0;

}

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
#include <stack>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n, m;

const int NN = 100000;

int teller, vlowlink[NN], vlink[NN];
stack<int> S;
int situatie[NN]; // 0 = not seen yet, 1 = in stack, 2 = processed
vector<int> adj[NN];
int sccnr[NN], cur;

void sccrec (int v) {
    vlink[v] = vlowlink[v] = teller++;
    S.push(v);
    situatie[v] = 1;
    int j, buur;
    for (j = adj[v].size()-1; j >= 0; j--)
        if (situatie[buur = adj[v][j]] < 2) {
            if (situatie[buur] == 0)
                sccrec(buur);
        vlowlink[v] = min(vlowlink[v], vlowlink[buur]);
    }
    if (vlowlink[v] == vlink[v]) {
        int w;
        do {
            sccnr[w = S.top()] = cur;
            situatie[w] = 2;
            S.pop();
        }
        while (w != v);
        cur++;
    }
}

void strongly_connected_components (int n) {
    for (int i=0; i<n; i++) situatie[i] = 0;
    teller = cur = 0;
    for (int i = 0; i < n; i++)
        if (situatie[i] < 2)
            sccrec(i);
}

int c[100010];
int best[100010];
int cnt[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", c+i);
    cin>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--; b--;
        adj[a].push_back(b);
    }

    strongly_connected_components(n);

    for (int i=0; i<n; i++) best[i] = -1;

    int all = 0;
    for (int i=0; i<n; i++) {
        if (best[sccnr[i]]==-1) {
            all++;
            best[sccnr[i]] =c[i];
            cnt[sccnr[i]] = 1;
        }
        else {
            if (c[i] < best[sccnr[i]]) {
                best[sccnr[i]] =c[i];
                cnt[sccnr[i]] = 1;
            }
            else if (c[i]==best[sccnr[i]]) cnt[sccnr[i]]++;
        }
    }

    long long cost = 0;
    long long ways = 1;
    //for (int i=0; i<all; i++) cout<<i<<" "<<best[i]<<" "<<cnt[i]<<endl;
    for (int i=0; i<all; i++) {
        cost += best[i];
        ways = (ways*cnt[i])%1000000007;
    }

    cout<<cost<<" "<<ways<<endl;

    return 0;

}

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


int par[100];
int siz[100];
int n;

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}
bool connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (siz[a]>siz[b]) {
        par[a] = b;
        siz[b]++;
    }
    else {
        par[b] = a;
        siz[a]++;
    }
    return true;
}

string ady[110];
bool vis[110];
bool done[110];

void dfs(int i, int p, int pre) {
    vis[i] = 1;
    done[p] = 1;
    for (int j=0; j<n; j++) if (ady[i][j]=='1') {
        if (j==pre) continue;
        if (vis[j]) {
            ady[i][j] = 'd';
            ady[j][i] = 'd';
        }
        else dfs(j,p,i);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int a,d;
    scanf("%d%d",&d,&a);

    for (int i=0; i<n; i++) par[i] = i;
    for (int j=0; j<n; j++) siz[j] = 0;
    for (int i=0; i<n; i++) {
        cin>>ady[i];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ady[i][j]=='1') connect(i,j);
        }
    }

    for (int i=0; i<n; i++) if (!vis[i]) {
        dfs(i, par[i], -1);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (connect(i,j)) {
                ady[i][j] = 'a';
                ady[j][i] = 'a';
            }
        }
    }

    long long tot = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (ady[i][j]=='d') tot+=(long long)d;
            else if (ady[i][j]=='a') tot+=(long long)a;
            else ady[i][j] = '0';
        }
    }
    cout<<tot/2<<endl;
    for (int i=0; i<n; i++) cout<<ady[i]<<endl;

    return 0;

}

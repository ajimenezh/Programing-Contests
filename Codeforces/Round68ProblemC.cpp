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

#define MAXN 1000010

int n,m;
bool up[MAXN], down[MAXN], _left[MAXN], _right[MAXN];

void dfs(int p, int t) {
    if (t==0 && up[p]) return;
    if (t==1 && down[p]) return;
    if (t==2 && _left[p]) return;
    if (t==3 && _right[p]) return;


    if (t==0) up[p] = 1;
    if (t==1) down[p] = 1;
    if (t==2) _left[p] = 1;
    if (t==3) _right[p] = 1;

    if (t==0) {
        if (p+m >= n) {
            dfs(p+m-n,3);
        }
        else {
            dfs(p+m,1);
        }
        if (p-m < 0) {
            dfs(m+(p-m),2);
        }
        else {
            dfs(p-m,1);
        }
    }
    if (t==1) {
        if (p+m >= n) {
            dfs(p+m-n,3);
        }
        else {
            dfs(p+m,0);
        }
        if (p-m < 0) {
            dfs(m+(p-m),2);
        }
        else {
            dfs(p-m,0);
        }
    }
    if (t==2) {
        if (p+n >= m) {
            dfs(p+n-m,1);
        }
        else {
            dfs(p+m,3);
        }
        if (p-n < 0) {
            dfs(n+(p-n),0);
        }
        else {
            dfs(p-m,3);
        }
    }
    if (t==3) {
        if (p+n >= m) {
            dfs(p+n-m,1);
        }
        else {
            dfs(p+m,2);
        }
        if (p-n < 0) {
            dfs(n+(p-n),0);
        }
        else {
            dfs(p-m,2);
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for (int i=0; i<n; i++) {
        up[i] = 0;
        down[i] = 0;
    }
    for (int i=0; i<m; i++) {
        _left[i] = 0;
        _right[i] = 0;
    }

    int k = 0;
    for (int i=0; i<n; i++) {
        if (!up[i]) {dfs(i,0); k++;}
        if (!down[i]) {dfs(i,1); k++;}
    }
    for (int i=0; i<m; i++) {
        if (!_left[i]) {dfs(i,2); k++;}
        if (!_right[i]) {dfs(i,3); k++;}
    }

    cout<<k<<endl;

    return 0;

}

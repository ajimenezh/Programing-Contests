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
int m[1001][1001];
int vis[10001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) m[i][i] = 0;
    for (int i=0; i<n-2; i++) {
        int k = i+1;
        int f;
        if (2*i+1<n) f = 2*i+1;
        else f = (2*i+1)%n + 1;
        for (int j=f; j<n; j++) {
            if (j<i) break;
            m[i][k] = j;
            m[k][i] = m[i][k];
            k++;
        }
        for (int j=0; j<n; j++) vis[j] = 0;
        for (int j=0; j<k; j++) vis[m[i][j]] = 1;
        for (int j=f;; j=(j+1)%n) {
            //cout<<i<<" "<<k<<" "<<j<<" "<<vis[j]<<endl;
            if (!vis[j]) {
                m[i][k] = j;
                m[k][i] = j;
                k++;
            }
            if (k>=n) break;
        }
    }
    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) vis[m[n-2][i]] = 1;
    for (int i=0; i<n; i++) if (!vis[i]) {
        m[n-2][n-1] = i;
        m[n-1][n-2] = i;
        break;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }

    return 0;

}

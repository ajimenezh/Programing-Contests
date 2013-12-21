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
int m[310][310];
int p[310];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&m[i][j]);
            m[i][j]--;
        }
    }
    for (int i=0; i<n; i++) {
        int k;
        cin>>k;
        p[k-1] = i;
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (m[i][j]==i) continue;
            bool good = 1;
            for (int k=j+1; k<n; k++) {
                if (m[i][j]<m[i][k] || p[m[i][j]]<p[m[i][k]] || m[i][k]==i) continue;
                good = 0;
                break;
            }
            if (good) {
                cout<<m[i][j]+1<<" ";
                break;
            }
        }
    }

    return 0;

}

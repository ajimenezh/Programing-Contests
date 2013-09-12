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

int n,m;
int k;
int a[10][10];
int b[10][10];

set<int> s[10][10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    if (k<n+m-1) {
        int tmp;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&tmp);
        cout<<0;
        return 0;
    }

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&a[i][j]);

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i==0&&j==0) {
                s[i][j].insert(a[i][j]);
            }
            else if (i==0) {
                rep(it,s[i][j-1]) s[i][j].insert(*it);
                if (a[i][j]!=0 && s[i][j].find(a[i][j])!=s[i][j].end()) {
                    cout<<0<<endl;
                    return 0;
                }
                s[i][j].insert(a[i][j]);
            }
            else if (j==0) {
                rep(it,s[i-1][j]) s[i][j].insert(*it);
                if (a[i][j]!=0 && s[i][j].find(a[i][j])!=s[i][j].end()) {
                    cout<<0<<endl;
                    return 0;
                }
                s[i][j].insert(a[i][j]);
            }
            else {
                rep(it,s[i][j-1]) s[i][j].insert(*it);
                rep(it,s[i-1][j]) s[i][j].insert(*it);
                if (a[i][j]!=0 && s[i][j].find(a[i][j])!=s[i][j].end()) {
                    cout<<0<<endl;
                    return 0;
                }
                s[i][j].insert(a[i][j]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i==0&&j==0) b[i][j] = k;
            else if (j==0) b[i][j] = k-i;
            else if (i==n-1) {
                b[i][j] = k - (n-1) - (j);
            }
            else {
                b[i][j] = k - (m);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    long long res = 1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j]==0) {
                res = (res*(long long)b[i][j])%1000000007LL;
            }
        }
    }

    cout<<res;

    return 0;

}

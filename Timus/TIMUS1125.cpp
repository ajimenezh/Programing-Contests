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
char s[51][51];
int a[51][51],b[51][51];
set<int> p;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%s",&s[i]);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d",&a[i][j]);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) a[i][j] = a[i][j]%2;

    for (int i=0; i<72; i++) p.insert(i*i);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        for (int ii=0; ii<n; ii++) for (int jj=0; jj<m; jj++) {
            int t = (ii-i)*(ii-i) + (jj-j)*(jj-j);
            if (p.find(t)!=p.end()) b[ii][jj] = (b[ii][jj] + a[i][j])%2;
        }
    }

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (b[i][j]==1) {
        s[i][j]=='B'?s[i][j]='W':s[i][j]='B';
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout<<s[i][j];
        }
        cout<<endl;
    }

    return 0;

}

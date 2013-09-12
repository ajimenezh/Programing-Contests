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

pair<int,int> p[90100];
int n,m;
char a[301][301];
int k,s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        cin>>a[i][j];
        if (a[i][j]=='*') p[s++] = mp(i,j);
    }
    sort(p,p+n);

    //for (int i=0; i<n; i++) {for (int j=0; j<m; j++) cout<<a[i][j]; cout<<endl;}

    for (int i=1; i<max(n,m); i++) {
        for (int j=0; j<s; j++) {
            if (p[j].first+i>=n || p[j].first-i<0) continue;
            if (p[j].second+i>=m || p[j].second-i<0) continue;
            //cout<<p[j].first<<" "<<p[j].second<<endl;
            if (a[p[j].first+i][p[j].second]!='*' || a[p[j].first-i][p[j].second]!='*') continue;
            if (a[p[j].first][p[j].second+i]!='*' || a[p[j].first][p[j].second-i]!='*') continue;
            k--;
            if (k==0) {
                cout<<p[j].first+1<<" "<<p[j].second+1<<endl;
                cout<<p[j].first+1-i<<" "<<p[j].second+1<<endl;
                cout<<p[j].first+1+i<<" "<<p[j].second+1<<endl;
                cout<<p[j].first+1<<" "<<p[j].second+1-i<<endl;
                cout<<p[j].first+1<<" "<<p[j].second+1+i<<endl;
                return 0;
            }
        }
    }

    cout<<-1;

    return 0;

}

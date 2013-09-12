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

int x, y, d, n;
pair<int,int> v[21];
int gn[500][500];
bool vis[500][500];
bool use[500][500];
const int m = 250;
int grundy(int a, int b) {
    cout<<a<<" "<<b<<endl;
    if (vis[a+m][b+m]) return gn[a+m][b+m];
    if (a*a+b*b>d*d) {
        return 0;
    }
    set<int> s;
    s.clear();
    int ret = 0;
    for (int i=0; i<n; i++) {
        s.insert(grundy(a+v[i].first,b+v[i].second));
    }
    rep(it,s) {
        if (ret==*it) ret++;
        else break;
    }
    vis[a+m][b+m] = 1;
    gn[a+m][b+m] = ret;
    return ret;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x>>y>>n>>d;
    for (int i=0; i<n; i++) scanf("%d%d",&v[i].first,&v[i].second);
    for (int i=0; i<500; i++) for (int j=0; j<500; j++) for (int k=0; k<2; k++) vis[i][j] = 0;
    int t = grundy(x,y);
    for (int i=0; i<10; i++) {for (int j=0; j<10; j++) cout<<gn[i+m][j+m]<<" "; cout<<endl;}
    if (t!=0) cout<<"Dasha";
    else cout<<"Anton";

    return 0;

}

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
pair<int,int> v[10010];
int root[20010][501];
int r[20010][501];

int _find(int a, int t) {
    if (a==root[t][a]) return a;
    root[t][a] = _find(root[t][a],t);
    return root[t][a];
}
void _merge(int a,int b, int t) {
    if (root[t][a]==root[t][b]) return;
    a = _find(a,t);
    b = _find(b,t);
    if (r[t][a]<r[t][b]) {
        root[t][b] = a;
        r[t][a]++;
    }
    else {
        root[t][a] = b;
        r[t][b]++;
    }
    return;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        v[i] = make_pair(a,b);
    }

    for (int i=0; i<n; i++) for (int j=0; j<2*m+2; j++) root[j][i] = i;
    for (int i=0; i<n; i++) for (int j=0; j<2*m+2; j++) r[j][i] = 0;

    for (int i=0; i<m; i++) {
        if (i!=0) for (int j=0; j<n; j++) root[i][j] = root[i-1][j];
        if (i!=0) for (int j=0; j<n; j++) r[i][j] = r[i-1][j];
        _merge(v[i].first,v[i].second,i);
    }


    for (int i=m-1; i>=0; i--) {
        if (i!=m-1) for (int j=0; j<n; j++) root[m+i+1][j] = root[m+1+i+1][j];
        if (i!=m-1) for (int j=0; j<n; j++) r[m+i+1][j] = r[m+1+i+1][j];
        _merge(v[i].first,v[i].second,m+i+1);
    }

    int k;
    cin>>k;

    for (int i=0; i<k; i++) {
        int le,ri;
        scanf("%d%d",&le,&ri);

        le--;
        ri--;

        for (int j=0; j<n; j++) root[m][j] = j;
        for (int j=0; j<n; j++) r[m][j] = 0;

        if (le==0 && ri==m-1) {
            cout<<n<<endl;
            continue;
        }
        if (le==0) {
            int c = n;
            //for (int j=0; j<n; j++) cout<<root[ri+m+2][j]<<" "; cout<<endl;
            for (int j=0; j<n; j++) if (root[ri+m+2][j]!=j) c--;
            cout<<c<<endl;
            continue;
        }
        if (ri==m-1) {
            int c = n;
            //for (int j=0; j<n; j++) cout<<root[le-1][j]<<" "; cout<<endl;
            for (int j=0; j<n; j++) if (root[le-1][j]!=j) c--;
            cout<<c<<endl;
            continue;
        }

        for (int j=0; j<n; j++) root[m][j] = root[le-1][j];
        for (int j=0; j<n; j++) r[m][j] = r[le-1][j];
        for (int j=0; j<n; j++) if (root[ri+m+2][j]!=j) _merge(j,root[ri+m+2][j],m);
        //for (int j=0; j<n; j++) cout<<root[m][j]<<" "; cout<<endl;

        int c = n;
        for (int j=0; j<n; j++) if (root[m][j]!=j) c--;

        cout<<c<<endl;

    }

    return 0;

}

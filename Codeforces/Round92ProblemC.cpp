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
int prio[101][101];
int l;
long long k;
long long c[201];
pair<int,int> q[10001];
int cnt;
int le[201],ri[201];
int s[201];
int now;
long long total[201][201];

#define MAX 1000000000000000005

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    cin>>k;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>prio[i][j];

    l = n+m-1;

    c[0] = 1;

    for (int i=1; i<n; i++) {
        c[i] = 0;
        for (int j=0; j<=i-1; j++) c[i] += c[i-1-j]*c[j];
    }

    now = c[l/2-1];

    cnt = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        q[cnt++] = make_pair(prio[i][j],i+j);
    }
    sort(q,q+cnt);

    for (int i=0; i<l; i++) s[i] = 0;
    s[0] = 1;
    s[l-1] = -1;

    for (int i=0; i<cnt; i++) {
        if (s[q[i].second]!=0) continue;
        int pos = q[i].second;

        s[pos] = 1;

        total[0][0] = 1;
        for (int p=1; p<=l; p++) for (int r=0; r<l; r++) {
            total[p][r] = 0;
            if (r>0 && s[p-1]!=-1) total[p][r] += total[p-1][r-1];
            if (s[p-1]!=1) total[p][r] += total[p-1][r+1];
            if (total[p][r]>MAX) total[p][r] = MAX+2;
        }

        //cout<<pos<<" "<<total[l][0]<<endl;
        if (total[l][0]<k) {
            s[pos] = -1;
            k -= total[l][0];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i+j]==1) cout<<"(";
            else cout<<")";
        }
        cout<<endl;
    }

    return 0;

}

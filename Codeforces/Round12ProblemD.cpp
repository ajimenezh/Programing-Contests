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

#define MAXN 500010

#define INF 1<<30

int n;
int x[MAXN],y[MAXN],z[MAXN];
pair<int,pair<int,int> > v[500010];
int val[500010][2];
void add(int k, int c, int j, bool d) {
    for(; k<n; k |= k+1) {
        if (val[k][j]<c) {
            val[k][j] = c;
        }
        if (d) {
            val[k][j] = c;
        }
    }
}
int look(int k, int j) {
    int s = -1;
    for (; k >= 0; k = (k & (k + 1)) - 1) {
        if (val[k][j]>s) {
            s = val[k][j];
        }
    }
    return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        x[i] = a;
    }
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        y[i] = a;
    }
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        z[i] = a;
    }
    for (int i=0; i<n; i++) {
        v[i] = make_pair(z[i],make_pair(y[i],x[i]));
    }
    sort(v,v+n);
    int cur = 1;
    int p;
    for (int i=0; i<n; i++) {
        if (i!=0 && v[i].first!=p) cur++;
        p = v[i].first;
        v[i].first = cur;
    }
    cur++;
    for (int i=0; i<n; i++) {
        int tmp = v[i].first;
        v[i].first = v[i].second.second;
        v[i].second.second = tmp;
    }
    sort(v,v+n);
    reverse(v,v+n);

    int r = 0;
    vector<pair<int,int> > next;
    for (int i=0; i<n; i++) for (int j=0; j<2; j++) val[i][j] = -1;
    for (int i=0; i<n; i++) {
        //cout<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
        if (i!=0 && v[i].first!=v[i-1].first) {
            for (int j=0; j<next.size(); j++) {
                add(next[j].first,next[j].second,1,0);
                //add(next[j].first,-1,0,1);
            }
            next.clear();
        }
        if (look(cur-v[i].second.second-1,1)>v[i].second.first);
        //else if (look(cur-v[i].second.second-1,0)>v[i].second.first);
        else r++;
        //add(cur-v[i].second.second,v[i].second.first,0,0);
        next.push_back(make_pair(cur-v[i].second.second,v[i].second.first));
        //cout<<r<<endl;
    }

    cout<<n-r<<endl;

    return 0;

}

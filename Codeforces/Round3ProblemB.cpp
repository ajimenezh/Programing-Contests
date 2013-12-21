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

int n,v;
vector<pair<int,int> > v1,v2;
int sum[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>v;
    for (int i=0; i<n; i++) {
        int t,p;
        scanf("%d%d",&t,&p);
        if (t==1) {
            v1.push_back(make_pair(p,i));
        }
        else {
            v2.push_back(make_pair(p,i));
        }
    }

    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    reverse(v2.begin(),v2.end());
    for (int i=0; i<v1.size(); i++) sum[i+1] = sum[i] + v1[i].first;

    int tmp = 0;
    int p = -1;
    int best = 0;
    for (int i=0; i<=v2.size(); i++) {
        int vv = v-2*i;
        if (vv<0) continue;
        vv = min(vv,(int)v1.size());
        int c = tmp + sum[vv];
        if (c>best) {
            best = c;
            p = i;
        }
        if (i<v2.size()) tmp += v2[i].first;
    }
    cout<<best<<endl;
    for (int i=1; i<=p; i++) cout<<v2[i-1].second+1<<" ";
    int vv = v-2*p;
    vv = min(vv,(int)v1.size());
    for (int i=0; i<vv; i++) cout<<v1[i].second+1<<" ";

    return 0;

}

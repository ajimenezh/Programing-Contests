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
long long k;

pair<int,pair<long long, long long> > v[51];
map<pair<int,pair<long long, long long> >, int> ma;
pair<int,long long> next[51][51][101];

long long dp[51][51][101];

long long solve(int d, int e, int tot) {
    if (d==n-1) return v[e].second.first+tot;
    if (e==m) return -2;
    if (dp[d][e][tot]!=-1) return dp[d][e][tot];

    long long r = v[e].second.first+tot;
    long long tmp = 0;
    bool done = false;

    for (int i=e+1; i<m; i++) {
        if (v[i].first <=v[e].first) continue;
        if (r*k>=v[i].second.first && r*k<=v[i].second.second) {
            long long t = solve(d+1,i,r*k - v[i].second.first);
            if (t!=-2) done = true;
            if (t>tmp) {
                tmp = t;
                next[d][e][tot] = make_pair(i,r*k - v[i].second.first);
            }
        }

        if (r+k>=v[i].second.first && r+k<=v[i].second.second) {
            long long t = solve(d+1,i,r+k - v[i].second.first);
            if (t!=-2) done = true;
            if (t>tmp) {
                tmp = t;
                next[d][e][tot] = make_pair(i,r+k - v[i].second.first);
            }
        }
    }

    if (!done) {
        dp[d][e][tot] = -2;

        return -2LL;
    }

    dp[d][e][tot] = tmp+r;

    return tmp+r;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;

    for (int i=0; i<m; i++) {
        long long a,b;
        int c;
        scanf("%I64d%I64d%d",&a,&b,&c);

        v[i] = make_pair(c,make_pair(a,b));
        ma[make_pair(c,make_pair(a,b))] = i+1;
    }

    sort(v, v+m);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int p=0; p<101; p++)
        dp[i][j][p] = -1;


    long long res = -1;
    int in = -1;
    int ex = 0;
    for (int i=0; i<m; i++) for (int j=0; j<=(v[i].second.second-v[i].second.first); j++) {
        long long tmp = solve(0,i,j);
        //cout<<tmp<<" "<<i<<" "<<j<<endl;
        if (res<tmp) {
            res = tmp;
            in = i;
            ex = j;
        }
    }

    if (res==-1) {
        cout<<"NO";
        return 0;
    }

    cout<<"YES\n";
    for (int i=0; i<n; i++) {
        cout<<ma[v[in]]<<" "<<v[in].second.first+ex<<endl;
        int temp = in;
        in = next[i][in][ex].first;
        ex = next[i][temp][ex].second;
    }

    return 0;

}

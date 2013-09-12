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

pair<int,int> o;

pair<int,int> obj[25];

int n;

int dp[1<<24];

int dist[24];
int distobj[24][24];
pair<int,int> post[1<<24];

int sqr(int a) {return (int)a*(int)a;}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int x,y;
    cin>>x>>y;
    o = make_pair(x,y);
    cin>>n;

    for (int i=0; i<n; i++) {
        cin>>x>>y;
        obj[i] = make_pair(x,y);
    }

    for (int i=0; i<n; i++) {
        dist[i] = sqr(obj[i].first - o.first) + sqr(obj[i].second - o.second);
    }
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        distobj[i][j] = sqr(obj[i].first - obj[j].first) + sqr(obj[i].second - obj[j].second);
    }
    for (int i=0; i<(1<<n); i++) post[i] = make_pair(-1,-1);

    for (int i=0; i<(1<<n); i++) dp[i] = 1<<30;

    dp[0] = 0;

    for (int i=1, j = 0; i<(1<<n); i++) {

        if (i&(1<<(j+1)))
            j++;
        dp[i] = dp[i-(1<<j)] + 2*dist[j];
        post[i] = make_pair(j,-1);

        for (int k=0; k<j; k++) if (i&(1<<k)) {
            int tmp = dp[i-(1<<j)-(1<<k)] + dist[j] + dist[k] + distobj[j][k];
            if (tmp<dp[i]) {
                dp[i] = tmp;
                post[i] = make_pair(k,j);
            }
        }

        //cout<<i<<" "<<dp[i]<<endl;
    }

    cout<<dp[(1<<n)-1]<<endl;

    vector<int> sol;
    sol.push_back(-1);
    int p = (1<<n)-1;
    while (p!=0) {
        //cout<<p<<endl;
        //cout<<post[p].first<<" "<<post[p].second<<endl;
        if (post[p].second==-1) {
            sol.push_back(post[p].first);
            sol.push_back(-1);
            p = p - (1<<(post[p].first));
        }
        else {
            sol.push_back(post[p].first);
            sol.push_back(post[p].second);
            sol.push_back(-1);
            p = p - (1<<(post[p].first)) - (1<<(post[p].second));
        }
        //cout<<p<<endl;
        //cout<<post[p].first<<" "<<post[p].second<<endl;
        //int df; cin>>df;
        //cout<<dp[p]<<endl;
    }

    for (int i=0; i<sol.size(); i++) cout<<sol[i]+1<<" ";

    return 0;

}

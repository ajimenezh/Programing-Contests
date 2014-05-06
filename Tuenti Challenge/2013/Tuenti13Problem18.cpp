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

#define eps 0.0000000000001

int t;
int n,m;
int in[50010];
int out[50010];
double w[50010];
int w1[50010];
double dis[50010];

bool BellmanFord() {

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (dis[out[j]] + w[j] > dis[in[j]] + eps) {
                dis[in[j]] = dis[out[j]] + w[j];
            }
        }
    }

    for (int i=0; i<m; i++) {
        if (dis[out[i]] + w[i] > dis[in[i]] + eps) {
            return true;
        }
    }
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n>>m;
        for (int i=0; i<m; i++) scanf("%d%d%d",out+i,in+i,w1+i);

        bool bug = 0;
        for (int i=0; i<m; i++) w[i] = log(1.0 + 1.0*w1[i]/100.0);
        for (int i=0; i<n; i++) dis[i] = 0;

        bug |= BellmanFord();

        //for (int i=0; i<n; i++) cout<<dis[i]<<" "; cout<<endl;
        bug?printf("True\n"):printf("False\n");
    }

    return 0;

}

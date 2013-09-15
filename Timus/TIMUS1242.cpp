//Not finished

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

int n;
vector<int> e[1100];
int vis[1100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    cin>>n;
    string s;
    getline(cin,s);
    while (getline(cin,s)) {
        if (s=="BLOOD") break;
        stringstream ss(s);
        ss>>s;
        int a = atoi(s.c_str());
        ss>>s;
        int b = atoi(s.c_str());
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int k;
    while (scanf("%d",&k)!=EOF) {
        k--;
        vis[k] = 1;
        for (int i=0; i<ch[k].size(); i++) vis[e[k][i]] = 1;
    }
    for (int i=0; i<n; i++) if (!vis[i]) cout<<i+1<<" ";
    bool good = 0;
    for (int i=0; i<n; i++) if (!vis[i]) good = 1;
    if (!good) cout<<0<<endl;

    return 0;

}

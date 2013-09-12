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

pair<int,int> v[1001];
int k;
map<pair<int,int>, bool> vis;
int des;
pair<int,int> q[2001];
int in,fn;
int a,b;
map<pair<int,int>,pair<int,int> > prev;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>k;
    for (int i=0; i<k; i++) {
        scanf("%d%d",&a,&b);
        a--;
        b--;
        v[i] = make_pair(a,b);
    }

    cin>>des>>a>>b;
    des--; a--; b--;
    q[fn++] = make_pair(a,b);

    pair<int,int> fin = make_pair(-1,-1);

    while (in!=fn) {
        pair<int,int> p = q[in++];
        if (p.first==des || p.second==des) {
            fin = p;
            break;
        }
        for (int i=0; i<k; i++) if (!vis[v[i]] && (v[i].first == p.first || v[i].first==p.second)) {
            prev[v[i]] = p;
            q[fn++] = v[i];
            vis[v[i]] = 1;
        }
    }

    if (fin==make_pair(-1,-1)) cout<<"IMPOSSIBLE";
    else {
        vector<int> w;
        while (fin!=make_pair(a,b)) {
            int p;
            for (int i=0; i<k; i++) if (fin==v[i]) {
                p = i;
                break;
            }
            w.push_back(p);
            fin = prev[fin];
        }
        cout<<w.size()<<endl;
        for (int i=w.size()-1; i>=0; i--) {
            cout<<w[i]+1<<endl;
        }
    }

    return 0;

}

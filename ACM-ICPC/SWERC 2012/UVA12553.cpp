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

int target;
int best;
vector<pair<pair<int,int>,int> > sol;
map<vector<int>,bool> vis;

void dfs(vector<int> &v, vector<pair<pair<int,int>,int> > &w) {
    if (v.size()==1) {
        if (abs(target-v[0])<best) {
            sol = w;
            sol.push_back(make_pair(make_pair(v[0],0),0));
            best = abs(target-v[0]);
        }
        return;
    }
    if (vis[v]) return;
    for (int i=0; i<6; i++) {
        if (abs(target-v[i])<best) {
            sol = w;
            sol.push_back(make_pair(make_pair(v[i],0),0));
            best = abs(target-v[i]);
        }
    }

    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            int t1 = v[i];
            int t2 = v[j];
            vector<int> v2 = v;
            v2.erase(v2.begin()+j);
            v2.erase(v2.begin()+i);

            w.push_back(make_pair(make_pair(t1,t2),1));
            v2.push_back(t1+t2);
            dfs(v2,w);
            w.pop_back();
            v2.pop_back();

            if (t1>t2) {
                w.push_back(make_pair(make_pair(t1,t2),2));
                v2.push_back(t1-t2);
                dfs(v2,w);
                w.pop_back();
                v2.pop_back();
            }
            if (t2>t1) {
                w.push_back(make_pair(make_pair(t2,t1),2));
                v2.push_back(t2-t1);
                dfs(v2,w);
                w.pop_back();
                v2.pop_back();
            }

            w.push_back(make_pair(make_pair(t1,t2),3));
            v2.push_back(t1*t2);
            dfs(v2,w);
            w.pop_back();
            v2.pop_back();

            if (t1%t2==0) {
                w.push_back(make_pair(make_pair(t1,t2),4));
                v2.push_back(t1/t2);
                dfs(v2,w);
                w.pop_back();
                v2.pop_back();
            }
            if (t2%t1==0) {
                w.push_back(make_pair(make_pair(t2,t1),4));
                v2.push_back(t2/t1);
                dfs(v2,w);
                w.pop_back();
                v2.pop_back();
            }
        }
    }

    vis[v] = 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int cas;
    cin>>cas;
    while (cas--) {
        vector<int> v;
        best = 1000000000;
        vis.clear();
        for (int i=0; i<6; i++) {
            int a;
            cin>>a;
            v.push_back(a);
        }
        cin>>target;
        printf("Target: %d\n",target);
        vector<pair<pair<int,int>,int> > w;
        dfs(v, w);
        w = sol;
        int res = 0;
        for (int i=0; i<w.size()-1; i++) {
            int t1 = w[i].first.first;
            int t2 = w[i].first.second;
            if (w[i].second==1) {
                printf("%d + %d = %d\n",t1,t2,t1+t2);
            }
            else if (w[i].second==2) {
                printf("%d - %d = %d\n",t1,t2,t1-t2);
            }
            else if (w[i].second==3) {
                printf("%d * %d = %d\n",t1,t2,t1*t2);
            }
            else if (w[i].second==4) {
                printf("%d / %d = %d\n",t1,t2,t1/t2);
            }
        }
        printf("Best approx: %d\n",w[w.size()-1].first.first);
        printf("\n");
    }

    return 0;

}

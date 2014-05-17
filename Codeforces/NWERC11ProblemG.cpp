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

map<string, int> ma;
pair<int,int> v[110];
string s[110];
vector<int> e[101];
vector<int> r[101];
bool vis[101];
int n,m;
bool gun[101];
long long d[101][101];

long long sqr(int a) {return (long long)a*(long long)a;}

long long dist(int a, int b) {
    return sqr(v[a].first-v[b].first) + sqr(v[a].second-v[b].second);
}

bool cycle(int i) {
    vis[i] = 1;
    bool bad = 0;
    rep(it,e[i]) {
        if (!vis[*it]) bad |= cycle(*it);
        else return 1;
    }
    return bad;
}

int q[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n>>m;

        ma.clear();

        for (int i=0; i<n; i++) {
            string s1;
            int x,y;
            cin>>s1>>x>>y;

            ma[s1] = i;
            s[i] = s1;
            v[i] = make_pair(x,y);
        }

        string str;
        getline(cin,str);
        for (int i=0; i<n; i++) gun[i] = 0;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) r[i].clear();
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[i][j] = 1LL<<61;

        for (int i=0; i<m; i++) {
            getline(cin,str);
            stringstream ss(str);

            string origin;
            ss>>origin;
            string first,last;
            ss>>first; ss>>first;
            ss>>last; ss>>last; ss>>last;

            gun[ma[first]] = 1;
            gun[ma[last]] = 1;

            int ii = ma[origin];
            int jj = ma[first];
            int kk = ma[last];

            d[jj][kk] = min(d[jj][kk],+dist(ii,jj)-dist(ii,kk));


            if (dist(ma[origin],ma[first]) > dist(ma[origin],ma[last]) || origin==first || origin==last) {
                e[ma[first]].push_back(ma[last]);
                r[ma[last]].push_back(ma[first]);

                //cout<<origin<<" "<<first<<" "<<last<<endl;
            }
        } cout<<d[0][1]<<" "<<d[1][0]<<endl;

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }

        bool done = 0;

        for (int i=0; i<n; i++) {
            if (gun[i]) cout<<i<<" "<<s[i]<<" "<<d[i][i]<<endl;
            if (gun[i] && d[i][i]<0) {
                cout<<"IMPOSSIBLE"<<endl;
                done = 1;
                break;
            }
        }

        if (done) continue;

        int cnt = 0;

        for (int i=0; i<n; i++) vis[i] = 0;

        int in = 0, fn = 0;

        for (int i=0; i<n; i++) if (r[i].size()==0 && gun[i]) q[fn++] = i;

        vector<int> order;
        for (int i=0; i<n; i++) {
            if (fn-i>1) {
                done = 1;
                cout<<"UNKNOWN"<<endl;
                break;
            }
            while (in<fn) {
                order.push_back(q[in]);
                vis[q[in++]] = 1;
            }
            for (int j=0; j<n; j++) if (gun[j] && !vis[j]) {
                int c = 0;
                rep(it,r[j]) if (!vis[*it] && gun[*it]) c++;
                if (c==0) {
                    q[fn++] = j;
                }
            }
        }

        if (done) continue;

        for (int i=0; i<order.size(); i++) cout<<s[order[i]]<<" ";
        cout<<endl;

    }

    return 0;

}

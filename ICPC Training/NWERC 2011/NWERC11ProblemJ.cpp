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

int t;
int n;
map<string ,int> ind;
string vs[1001];
vector<pair<int,int> > e[1001];
pair<pair<int,int>,pair<int,int> > v[1001];
int cnt;
priority_queue<pair<double,int> > q;
double dist[1001][60];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while(t--) {
        string _src,_dest;
        cin>>_src>>_dest;

        cnt = 0;

        ind[_src] = cnt++;
        ind[_dest] = cnt++;

        vs[0] = _src;
        vs[1] = _dest;

        int m;
        cin>>m;

        for (int i=0; i<1001; i++) e[i].clear();

        for (int i=0; i<m; i++) {
            int frec,t,d,p;
            cin>>_src>>_dest>>frec>>t>>p>>d;

            if (ind.find(_src)==ind.end()) {
                ind[_src] = cnt++;
                vs[cnt-1] = _src;
            }
            if (ind.find(_dest)==ind.end()) {
                ind[_dest] = cnt++;
                vs[cnt-1] = _dest;
            }

            e[ind[_dest]].push_back(make_pair(ind[_src],i));

            v[i] = make_pair(make_pair(frec,t),make_pair(p,d));
        }

        while (!q.empty()) q.pop();
        for (int i=0; i<cnt; i++) for (int j=0; j<60; j++) dist[i][j] = 1000000;

        q.push(mp(0,60));
        for (int i=0; i<60; i++) dist[1][i] = 0;

        while (!q.empty()) {
            double d = -q.top().first;
            int to = q.top().second/60;
            int r = q.top().second%60;

            q.pop();

            if (d>dist[to][r]+0.00000001) continue;

            rep(it,e[to]) {
                int fr = (*it).first;
                int ind = (*it).second;

                double tmp = 0;

                tmp += (100.0-v[ind].second.first)/100.0*(v[ind].first.second+dist[to][(v[ind].first.second+v[ind].first.first)%60]);

                for (int dd=1; dd<=v[ind].second.second; dd++) {
                    tmp += (v[ind].second.first)/100.0/(1.0*v[ind].second.second)*(v[ind].first.second+dd+dist[to][(v[ind].first.second+v[ind].first.first+dd)%60]);
                }

                //cout<<tmp<<endl<<endl;

                if (dist[fr][v[ind].first.first]>tmp+0.000000001) {
                    q.push(mp(-tmp,60*fr+(v[ind].first.first)%60));
                    for (int t=0; t<60; t++)
						if (dist[fr][(v[ind].first.first-t+60)%60] > tmp + t + 0.0000001)
							dist[fr][(v[ind].first.first-t+60)%60] = tmp + t;
                }
            }
        }

        double res = 1000000;
        for (int t=0; t<60; t++)
            res = min(res,dist[0][t]);

        if (res == 1000000)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << res << endl;

    }


    return 0;

}

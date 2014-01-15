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

int cnt;

struct wing{
    map<int,int> halls;
    vector<int> ind;
    pair<int,int> link;
    int upwing;
    vector<pair<int,int> > iedges;
    vector<pair<int,int> > fedges;
    vector<int> wedges;

    void add_edge(int a, int b) {
        if (halls.find(a)!=halls.end()) {
            if (halls.find(b)!=halls.end()) {
                iedges.push_back(make_pair(a,b));
            }
            else {
                halls[b] = ind.size();
                ind.push_back(b);
                iedges.push_back(make_pair(a,b));
            }
        }
        else {
            halls[a] = ind.size();
            ind.push_back(a);
            if (halls.find(b)!=halls.end()) {
                iedges.push_back(make_pair(a,b));
            }
            else {
                halls[b] = ind.size();
                ind.push_back(b);
                iedges.push_back(make_pair(a,b));
            }
        }
    }
    wing(int a, int b) {
        link = make_pair(a,b);
        upwing = cnt-1;
    }
    void add_wing(int a, int b) {
        fedges.push_back(make_pair(a,b));
        wedges.push_back(++cnt);
    }
};
vector<wing> v;

void read(istream &is, int uplink, int downlink) {

    wing w = wing(uplink, downlink);

    v.push_back(w);

    int now = v.size()-1;

    int n,m,k;

    is >> n >> m >> k;

    for (int i=0; i<m; i++) {

        int a,b;

        is >> a >> b;
        a--; b--;

        v[now].add_edge(a,b);
    }

    for (int i=0; i<k; i++) {

        int a,b;

        is >> a >> b;
        a--; b--;

        v[now].add_wing(a,b);

        read(is,a,b);
    }
}

void print(int node) {
    cout << "Estamos en el ala " << node << endl;
    cout<<"los halls son:"<<endl;
    rep(it,v[node].halls) {
        cout<<(*it).first+1<<endl;
    }
    cout<<"Conecta con:"<<endl;
    for (int i=0; i<v[node].wedges.size(); i++) {
        cout<<"Hall "<<v[node].fedges[i].second+1<<" con index "<<v[node].wedges[i]<<endl;
    }

    cout<<endl;

    for (int i=0; i<v[node].wedges.size(); i++) {
        print(v[node].wedges[i]);
    }
}

pair<int,int> solve(int node) {

    vector<pair<int,int> > sol;

    for (int i=0; i<v[node].fedges.size(); i++) {
        sol.push_back(solve(v[node].wedges[i]));
    }

    int n = v[node].ind.size();

    int bestoff = 1000000;
    int beston = 1000000;

    for (int i=0; i<(1<<n); i++) {
        //check_internals
        bool good = 1;
        for (int j = 0; j<v[node].iedges.size(); j++) {
            if ( ( ( 1<<(v[node].halls[v[node].iedges[j].first]) ) & i ) ||
                    ( ( 1<<(v[node].halls[v[node].iedges[j].second]) ) & i ) ) {
                    }
            else {
                good = 0;
                break;
            }
        }

        if (!good) continue;

        int tmp = 0;
        for (int j=0; j<n; j++) if ((1<<j)&i) tmp++;

        for (int j = 0; j<v[node].wedges.size(); j++) {
            if ( ( 1<<(v[node].halls[v[node].fedges[j].first]) ) & i ) {
                tmp += min(sol[j].first,sol[j].second);
            }
            else {
                tmp += sol[j].first;
            }
        }

        if (v[node].link.first==-1) {
            bestoff = min(bestoff,tmp);
            beston = min(beston,tmp);
        }
        else {
            if ( ( 1<<(v[node].halls[v[node].link.second]) ) & i ) {
                beston = min(beston,tmp);
            }
            else {
                bestoff = min(bestoff,tmp);
            }
        }
    }

    //cout<<node<<" "<<beston<<" "<<bestoff<<endl;

    return make_pair(beston,bestoff);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    read(cin, -1, 0);

    //print(0);

    pair<int,int> res = solve(0);

    cout<<min(res.first,res.second);

    return 0;

}

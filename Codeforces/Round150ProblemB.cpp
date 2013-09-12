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

int n,m,h,t;
vector<int> e[100010];
pair<int,int> ed[100010];
set<pair<int,int> > es;
int ti;
int ho,to;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>h>>t;
    ho = h;
    to = t;

    if (h>t) {
        int tmp = h;
        h = t;
        t = tmp;
    }
    int k = 0;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
        ed[k++] = make_pair(max(a,b),min(a,b));
        es.insert(make_pair(max(a,b),min(a,b)));
    }


    for (int i=0; i<m; i++) {
        int p = ed[i].first;
        int q = ed[i].second;
        int ti = 0, hi = 0, c = 0;
        for (int j=0; j<min((int)e[p].size(),200); j++) {
            if (e[p][j]!=q && es.find(make_pair(max(e[p][j],q), min(e[p][j],q)))==es.end()) {
                ti++;
            }
            else if (e[p][j]!=q) {
                c++;
            }
        }
        for (int j=0; j<min((int)e[q].size(),200); j++) {
            if (e[q][j]!=p && es.find(make_pair(max(e[q][j],p), min(e[q][j],p)))==es.end()) {
                hi++;
            }
        }
        if (hi>ti) {
            int tmp = hi;
            hi = ti;
            ti = tmp;
        }

        //cout<<ti<<" "<<hi<<" "<<c<<endl;
        //cout<<p<<" "<<q<<endl;
        //cout<<(es.find(make_pair(2,0))==es.end())<<endl;
        if ((h-hi)+(t-ti)<=c) {
            cout<<"YES"<<endl;
            vector<int> tv,hv,cv;

            for (int j=0; j<min((int)e[p].size(),200); j++) {
                if (e[p][j]!=q && es.find(make_pair(max(e[p][j],q), min(e[p][j],q)))==es.end()) {
                    tv.push_back(e[p][j]);
                }
                else if (e[p][j]!=q) {
                    cv.push_back(e[p][j]);
                }
            }
            for (int j=0; j<min((int)e[q].size(),200); j++) {
                if (e[q][j]!=p && es.find(make_pair(max(e[q][j],p), min(e[q][j],p)))==es.end()) {
                    hv.push_back(e[q][j]);
                }
                else if (e[q][j]!=p) {
                    cv.push_back(e[q][j]);
                }
            }

            if (hv.size()>tv.size()) {
                vector<int> tmp = hv;
                hv = tv;
                tv = tmp;
            }
            vector<int> tf,hf;
            for (int j=0; j<min((int)tv.size(),t); j++) tf.push_back(tv[j]);
            int k = 0;
            for (int j=0; j<t-tv.size(); j++) tf.push_back(cv[k++]);
            for (int j=0; j<min((int)hv.size(),h); j++) hf.push_back(hv[j]);
            for (int j=0; j<h-hv.size(); j++) hf.push_back(cv[k++]);

            if (ho==hf.size()) {
                bool flag = true;
                for (int j=0; j<hf.size(); j++) if (es.find(make_pair(max(hf[j],p),min(hf[j],p)))==es.end()) flag = false;
                if (flag) cout<<p+1<<" "<<q+1<<endl;
                else cout<<q+1<<" "<<p+1<<endl;
                for (int j=0; j<hf.size(); j++) cout<<hf[j]+1<<" "; cout<<endl;
            }
            else {
                bool flag = true;
                for (int j=0; j<tf.size(); j++) if (es.find(make_pair(max(tf[j],p),min(tf[j],p)))==es.end()) flag = false;
                if (flag) cout<<p+1<<" "<<q+1<<endl;
                else cout<<q+1<<" "<<p+1<<endl;
                for (int j=0; j<tf.size(); j++) cout<<tf[j]+1<<" "; cout<<endl;
            }

            if (to==tf.size()) {
                for (int j=0; j<tf.size(); j++) cout<<tf[j]+1<<" "; cout<<endl;
            }
            else {
                for (int j=0; j<hf.size(); j++) cout<<hf[j]+1<<" "; cout<<endl;
            }

            return 0;
        }
    }

    cout<<"NO";

    return 0;

}

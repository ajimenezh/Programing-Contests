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

int n;
int m[51][51];
pair<int,int> w[51];

void update(int a, int b, int c) {
    for (int j=0; j<n; j++) {
        m[a][j]+=c;
        m[j][b]+=c;
        if (a+j<n && b+j<n) m[a+j][b+j]+=c;
        if (a-j>-1 && b-j>-1)m[a-j][b-j]+=c;
        if (a+j<n && b-j>-1)m[a+j][b-j]+=c;
        if (a-j>-1 && b+j<n)m[a-j][b+j]+=c;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b; a--; b--;
        w[i] = make_pair(a,b);
        update(a,b,1);
    }

    long long res = 0;

    for (int i=0; i<n; i++) {
        update(w[i].first,w[i].second,-1);
        for (int j=i+1; j<n; j++) {
            update(w[j].first,w[j].second,-1);
            for (int k=j+1; k<n; k++) {
                update(w[k].first,w[k].second,-1);

                vector<pair<int,int> > tmp;
                tmp.push_back(w[i]);
                tmp.push_back(w[j]);
                tmp.push_back(w[k]);
                vector<pair<int,int> > u;

                for (int ii=0; ii<3; ii++) for (int jj=0; jj<3; jj++) if (ii!=jj) {
                    u.push_back(make_pair(tmp[ii].first,tmp[jj].second));
                }
                for (int ii=0; ii<6; ii++) for (int jj=ii+1; jj<6; jj++) for (int kk=jj+1; kk<6; kk++) {
                    if (u[ii].first==u[jj].first || u[ii].first==u[kk].first || u[kk].first==u[jj].first) continue;
                    if (u[ii].second==u[jj].second || u[ii].second==u[kk].second || u[kk].second==u[jj].second) continue;
                    if (m[u[ii].first][u[ii].second]>0) continue;
                    if (m[u[jj].first][u[jj].second]>0) continue;
                    if (m[u[kk].first][u[kk].second]>0) continue;
                    if (u[ii].first-u[ii].second==u[jj].first-u[jj].second || u[ii].first+u[ii].second==u[jj].first+u[jj].second) continue;
                    if (u[kk].first-u[kk].second==u[jj].first-u[jj].second || u[kk].first+u[kk].second==u[jj].first+u[jj].second) continue;
                    if (u[ii].first-u[ii].second==u[kk].first-u[kk].second || u[ii].first+u[ii].second==u[kk].first+u[kk].second) continue;
                    res++;
                }

                update(w[k].first,w[k].second,1);
            }
            update(w[j].first,w[j].second,1);
        }
        update(w[i].first,w[i].second,1);
    }

    cout<<res<<endl;

    return 0;

}

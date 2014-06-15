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

int n, m, reg;
int p[1010], d[1010];
bool used[1010];
vector<pair<int,int> > v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>reg;
    for (int i=0; i<n; i++) cin>>p[i]>>d[i];

    int h = m;
    int tim = 0;
    for (int i=0; i<n; i++) {
        int best = -1;
        int t = 1000000;
        int ind = -1;
        for (int j=0; j<n; j++) if (!used[j]) {
            if (reg>0 && p[j]*m<=h*100) {
                if (p[j]*m<=h*100) {
                    if (best<d[j]) {
                        t = 0;
                        best = d[j];
                        ind = j;
                    }
                }
            }
            else if (reg<0) {
                int tot = (int)(-1.0*p[j]*m/100/reg) + 1.0;
                //cout<<h<<" "<<tot<<endl;
                tot = h - tot;
                if (tot<t || (tot==t&&best<d[j])) {
                    t = tot ;
                    best = d[j];
                    ind = j;
                }
            }
        }
        //cout<<t<<" "<<reg<<endl;
        //cout<<tim<<endl;
        if (ind==-1) {
            tim--;
            break;
        }
        h += reg;
        h = min(h, m);
        reg -= d[ind];
        used[ind] = 1;
        tim += t;
        v.push_back(make_pair(tim, ind));
        if (h<=0) break;
        if (i!=n-1) tim++;
    }

    //cout<<tim<<" "<<h<<" "<<reg<<endl;
    if (reg>=0 && h>0) cout<<"NO";
    else {
        cout<<"YES"<<endl;
        cout<<tim + (h-1)/(-reg)<<" "<<v.size()<<endl;
        for (int i=0; i<v.size(); i++) {
            cout<<v[i].first<<" "<<v[i].second+1<<"\n";
        }
    }

    return 0;

}

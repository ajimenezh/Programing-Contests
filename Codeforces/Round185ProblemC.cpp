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

long long h;
int n,m,k;
long long methods[25];
long long a[100010];
int c[100010];
set<pair<int,pair<int,long long> > > s;
bool vis[100010];
bool done[100010];
long long d[10010];
int nm;
priority_queue<pair<long long,int> > q;

void solve() {
    while(!q.empty()) q.pop();
    for (int i=0; i<k; i++) if (d[i]!=-1) {
        q.push(make_pair(-d[i],i));
    }

    while (!q.empty()) {
        pair<long long,int> p = q.top();
        q.pop();

        //cout<<p.first<<" "<<p.second<<endl;

        for (int i=0; i<nm; i++) {
            long long u =  - p.first + methods[i];

            if (d[(u-1)%k]==-1 || d[(u-1)%k] > u) {
                d[(u-1)%k] = u;
                q.push(make_pair(-d[(u-1)%k],(u-1)%k));
            }
        }
    }
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>h>>n>>m>>k;
    for (int i=0; i<n; i++) scanf("%I64d%d",a+i,c+i);

    for (int i=0; i<n; i++) if ((a[i]-1LL)%k==0) {
        vis[i] = 1;
        s.insert(make_pair(-c[i],make_pair(i,a[i])));
    }

    for (int i=0; i<k; i++) d[i] = -1;
    d[0] = 1;

    nm = 0;

    methods[nm++] = k;

    for (int j=0; j<m; j++) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            long long tmp;
            scanf("%I64d",&tmp);
            bool good = 1;
            for (int i=0; i<nm; i++) if (methods[i]==tmp) good = 0;
            if (good) methods[nm++] = tmp;

            solve();

            //for (int i=0; i<k; i++) cout<<d[i]<<" "; cout<<endl;
            //for (int i=0; i<n; i++) cout<<done[i]<<" "; cout<<endl;

            for (int i=0; i<n; i++) if (d[(a[i]-1)%k]!=-1 && d[(a[i]-1)%k]<=(a[i]) && !done[i]) {
                if (!vis[i]) s.insert(make_pair(-c[i],make_pair(i,a[i])));
                vis[i] = 1;
            }
        }
        else if (t==2) {
            int ind;
            int x;
            scanf("%d%d",&ind,&x);
            ind--;
            pair<int,pair<int,long long> > p;
            //rep(it,s) cout<<(*it).first<<" "; cout<<endl;
            p = make_pair(-c[ind],make_pair(ind,a[ind]));
            if (s.find(p)!=s.end()) {
                s.erase(p);
                c[ind] -= x;
                p.first = -c[ind];
                s.insert(p);
            }
            else {
                c[ind] -= x;
            }
        }
        else {
            if (!s.empty()) {
                printf("%d\n",-(*s.begin()).first);
                done[(*s.begin()).second.first] = 1;
                s.erase(s.begin());
            }
            else {
                printf("0\n");
            }
        }
    }

    return 0;

}

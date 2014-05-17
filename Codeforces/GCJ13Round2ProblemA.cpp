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
int n,m;
vector<pair<pair<int,int>, int> > v;
vector<pair<pair<int,int>, int> > w;
vector<pair<int,int> > l;
vector<pair<int,int> > r;
vector<pair<int,int> > all;
long long res;

long long cost(pair<pair<int,int>, int> p) {
    long long k = p.first.second - p.first.first;

    return (long long)n*((long long)n+1LL)/2LL - ((long long)n-k)*((long long)n-k+1)/2LL;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n>>m;

        v.clear();
        res = 0;

        for (int i=0; i<m; i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);

            v.push_back(make_pair(make_pair(a,b),c));
        }

        for (int i=0; i<m; i++) {
            res += cost(v[i])*(long long)v[i].second;
        }

        all.clear();
        for (int i=0; i<m; i++) {
            all.push_back(make_pair(v[i].first.first,-v[i].second));
            all.push_back(make_pair(v[i].first.second,+v[i].second));
        }
        sort(all.begin(),all.end());

        int k = 0;

        while (k!=-1) {

            int in=-1,f;
            long long cnt = 0;
            for (int i=k; i<m; i++) {
                if (cnt-all[i].second>0);
                else {
                    in = k;
                    k = i;
                    f = i;
                    break;
                }
            }
            if (in==-1) {
                k = -1;
                in = 0;
                f = m;
            }

            l.clear();
            r.clear();
            for (int i=in; i<f; i++) {
                if (all[i].second<0) l.push_back(make_pair(all[i].first,-all[i].second));
                else r.push_back(make_pair(all[i].first,+all[i].second));
            }
            sort(l.begin(),l.end());
            sort(r.begin(),r.end());
            reverse(r.begin(),r.end());

            int i=0, j = r.size()-1;

            while (i<l.size() && j>=0) {
                if (l[i].second<r[j].first) {
                    res -= cost(make_pair(make_pair(l[i].first,r[j].first),0))*(long long)l[i].second;
                    i++;
                }
                else {
                    res -= cost(make_pair(make_pair(l[i].first,r[j].first),0))*(long long)r[j].second;
                    j--;
                }
            }

        }

        printf("Case #%d: %I64d\n",tt+1,-res);
    }

    return 0;

}

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

int n, m;
set<pair<int,int> > all[2];
pair<int,int> c[100010];

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while (cin>>n && n!=-1) {
        all[0].clear();
        all[1].clear();
        for (int i=0; i<n; i++) {
            int c1,c2;
            scanf("%d%d",&c1,&c2);
            all[0].insert(make_pair(c1+c2,i));
            all[1].insert(make_pair(abs(c1-c2),i));
            c[i] = make_pair(c1,c2);
        }
        cin>>m;
        for (int i=0; i<m; i++) {
            int c1,c2;
            scanf("%d%d",&c1,&c2);
            int C = c1+c2;
            int M = abs(c1-c2);

            set<pair<int,int> >::iterator it1, it1r, it2, it2r, tmp;

            it1 = lower_bound(all[0].begin(),all[0].end(),make_pair(C,-1));
            it1r = it1;
            if (it1!=all[0].begin()) it1r--;
            if (it1==all[0].end()) it1--;
            it2 = lower_bound(all[1].begin(),all[1].end(),make_pair(M,-1));
            it2r = it2;
            if (it2!=all[1].begin()) it2r--;
            if (it2==all[1].end()) it2--;

            int best = 1000000000;

            int a1, a2, a3, a4;
            a1 = abs((*it1).first-C);
            a2 = abs((*it1r).first-C);
            a3 = abs((*it2).first-M);
            a4 = abs((*it2r).first-M);

            int k = (*it1).second;
            if (c[k].first>=c1 && c[k].second>=c2) {
                if (best>a1) {
                    best = a1;
                }
            }
            if (c[k].first<=c1 && c[k].second<=c2) {
                if (best>a1) {
                    best = a1;
                }
            }

            k = (*it1r).second;
            if (c[k].first>=c1 && c[k].second>=c2) {
                if (best>a2) {
                    best = a2;
                }
            }
            if (c[k].first<=c1 && c[k].second<=c2) {
                if (best>a2) {
                    best = a2;
                }
            }

            k = (*it2).second;
            if (c[k].first>=c1 && c[k].second<=c2) {
                if (best>a3) {
                    best = a3;
                }
            }
            if (c[k].first<=c1 && c[k].second>=c2) {
                if (best>a3) {
                    best = a3;
                }
            }

            k = (*it2r).second;
            if (c[k].first>=c1 && c[k].second<=c2) {
                if (best>a4) {
                    best = a4;
                }
            }
            if (c[k].first<=c1 && c[k].second>=c2) {
                if (best>a4) {
                    best = a4;
                }
            }

            cout<<best<<"\n";
        }
        cout<<"\n";
    }

    return 0;

}

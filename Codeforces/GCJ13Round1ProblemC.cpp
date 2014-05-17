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

#define mid 676060+500

int t;
vector<pair<pair<int,int>,pair<int,int> > > v;
int wall[1400000];
vector<int> v2;

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        v.clear();
        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            int di,ni,wi,ei,si,deltadi,deltapi,deltasi;
            cin>>di>>ni>>wi>>ei>>si>>deltadi>>deltapi>>deltasi;

            for (int j=0; j<ni; j++) {
                v.push_back(make_pair(make_pair(di+j*deltadi,si+j*deltasi),make_pair(wi+j*deltapi,ei+j*deltapi)));
            }
        }
        sort(v.begin(),v.end());
        int day = v[0].first.first;
        int cnt = 0;
        for (int i=0; i<2*mid; i++) wall[i] = 0;
        int tot = 0;
        for (int i=0; i<v.size(); i++) {
            if (v[i].first.first==day) {
                tot = max(tot,v[i].first.second);
                v2.push_back(i);
                for (int j=v[i].second.first; j<v[i].second.second; j++) {
                    if (wall[mid+j]<v[i].first.second) {
                        cnt++;
                        break;
                    }
                }
            }
            else {
                day = v[i].first.first;
                i--;
                for (int j=0; j<v2.size(); j++) {
                    for (int k=v[v2[j]].second.first; k<v[v2[j]].second.second; k++) {
                        wall[mid+k] = max(wall[mid+k],v[v2[j]].first.second);
                    }
                }
                //for (int k=0; k<15; k++) cout<<wall[k+mid]<<" "; cout<<endl;
                tot = 0;
                v2.clear();
            }
        }
        v2.clear();
        printf("Case #%d: %d\n",tt+1,cnt);
    }
    return 0;

}

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

#define MAXN 100010
#define MAXM 10010

int n,m;
int a[MAXN],h[MAXN],l[MAXN],r[MAXN];
int b[MAXM],z[MAXM];
vector<pair<pair<int,int>,int> > v;
map<int,double> mp;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d%d%d%d",a+i,h+i,l+i,r+i);
    for (int i=0; i<m; i++) scanf("%d%d",b+i,z+i);
    for (int i=0; i<n; i++) if (r[i]!=100) {
        v.push_back(make_pair(make_pair(a[i]+1,1),100-r[i]));
        v.push_back(make_pair(make_pair(a[i]+h[i]+1,-1),100-r[i]));
    }
    for (int i=0; i<m; i++) {
        v.push_back(make_pair(make_pair(b[i],2),200));
        mp[b[i]] = 0.0;
    }
    sort(v.begin(),v.end());
    double p = 0.0;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first.second==2) {
            double q = mp[v[i].first.first];
            q = q + p;
            mp[v[i].first.first] = q;
            //cout<<p<<endl;
        }
        if (v[i].first.second==1) {
            double q = v[i].second*1.0/100.0;
            q = log(q);
            p = q + p;
        }
        if (v[i].first.second==-1) {
            double q = v[i].second*1.0/100.0;
            q = log(q);
            p = p - q;
        }
    }

    v.clear();
    for (int i=0; i<n; i++) if (l[i]!=100) {
        v.push_back(make_pair(make_pair(a[i],-1),100-l[i]));
        v.push_back(make_pair(make_pair(a[i]-h[i],1),100-l[i]));
    }
    for (int i=0; i<m; i++) {
        v.push_back(make_pair(make_pair(b[i],2),200));
    }

    sort(v.begin(),v.end());
    p = 0.0;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first.second==2) {
            double q = mp[v[i].first.first];
            q = q + p;
            mp[v[i].first.first] = q;
        }
        if (v[i].first.second==1) {
            double q = v[i].second*1.0/100.0;
            //cout<<p<<endl;
            q = log(q);
            p = q + p;
            //cout<<p<<" "<<q<<endl;
        }
        if (v[i].first.second==-1) {
            double q = v[i].second*1.0/100.0;
            q = log(q);
            p = p-q;
            //cout<<p<<endl;
        }
    }


    v.clear();
    for (int i=0; i<n; i++) if (r[i]==100) {
        v.push_back(make_pair(make_pair(a[i]+1,1),r[i]));
        v.push_back(make_pair(make_pair(a[i]+h[i]+1,-1),r[i]));
    }
    for (int i=0; i<m; i++) {
        v.push_back(make_pair(make_pair(b[i],2),0));
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first.second==2 && cnt>0) {
            double q = mp[v[i].first.first];
            q = -10000000000;
            mp[v[i].first.first] = q;
        }
        if (v[i].first.second==1) {
            cnt++;
        }
        if (v[i].first.second==-1) {
            cnt--;
        }
    }

    v.clear();
    for (int i=0; i<n; i++) if (l[i]==100) {
        v.push_back(make_pair(make_pair(a[i],-1),l[i]));
        v.push_back(make_pair(make_pair(a[i]-h[i],1),l[i]));
    }
    for (int i=0; i<m; i++) {
        v.push_back(make_pair(make_pair(b[i],2),0));

    }

    sort(v.begin(),v.end());
    cnt = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i].first.second==2 && cnt>0) {
            double q = mp[v[i].first.first];
            q = -10000000000;
            mp[v[i].first.first] = q;
        }
        if (v[i].first.second==1) {
            cnt++;
        }
        if (v[i].first.second==-1) {
            cnt--;
        }
    }

    double res = 0.0;
    for (int i=0; i<m; i++) {
        res += z[i]*exp(mp[b[i]]);
    }

    printf("%.12f",res);

    return 0;

}

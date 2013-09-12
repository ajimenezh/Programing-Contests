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

int n,m,k;
vector<int> h;
vector<int> v;
int c1,c2;
map<int,set<pair<int,int> > > v1,v2;
set<int> vs1,vs2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<k; i++) {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2) {
            v1[x1].insert(make_pair(min(y1,y2),max(y1,y2)));
            vs1.insert(x1);
        }
        else {
            v2[y1].insert(make_pair(min(x1,x2),max(x1,x2)));
            vs2.insert(y1);
        }
    }

    rep(it,v1) {
        set<pair<int,int> >::iterator i = (*it).second.begin();
        if ((*i).first>0) h.push_back((*i).first);
        while (true) {
            int yf = (*i).second;
            i++;
            if (i==(*it).second.end()) {
                if (yf<m) h.push_back(m-yf);
                break;
            }
            else {
                int yi = (*i).first;
                if (yi>yf) {
                    h.push_back(-yf+yi);
                }
            }
        }
    }
    rep(it,v2) {
        set<pair<int,int> >::iterator i = (*it).second.begin();
        if ((*i).first>0) v.push_back((*i).first);
        while (true) {
            int xf = (*i).second;
            i++;
            if (i==(*it).second.end()) {
                if (xf<n) v.push_back(n-xf);
                break;
            }
            else {
                int xi = (*i).first;
                if (xi>xf) {
                    v.push_back(-xf+xi);
                }
            }
        }
    }

    c1 = vs1.size();
    c2 = vs2.size();
    //cout<<c1<<" "<<c2<<endl;
    //for (int i=0; i<h.size(); i++) cout<<h[i]<<" "; cout<<endl;
    //for (int i=0; i<v.size(); i++) cout<<v[i]<<" "; cout<<endl;
    int a,b;
    if ((m-c2-1)%2==0) a = 0;
    else a = n;
    if ((n-c1-1)%2==0) b = 0;
    else b = m;

    for (int i=0; i<h.size(); i++) {
        a = a^h[i];
    }
    for (int i=0; i<v.size(); i++) {
        b = b^v[i];
    }
    int sol = a^b;
    if (sol!=0) cout<<"FIRST"<<endl;
    else {cout<<"SECOND"<<endl; return 0;}


    for (int j=1; j<n; j++) {
        if (v1.find(j)!=v1.end());
        else {
            cout<<j<<" "<<0<<" "<<j<<" "<<m<<endl;
            return 0;
        }
    }
    for (int j=1; j<m; j++) {
        if (v2.find(j)!=v1.end()) ;
        else {
            cout<<0<<" "<<j<<" "<<n<<" "<<j<<endl;
            return 0;
        }
    }


    for (int j=1; j<n; j++) {
        if (v1.find(j)!=v1.end()) {
            set<pair<int,int> >::iterator i = v1[j].begin();
            if ((*i).first!=0) {
                cout<<j<<" "<<0<<" "<<j<<" "<<(*i).first<<endl;
                return 0;
            }
            while (true) {
                int yf = (*i).second;
                i++;
                if (i==v1[j].end()) {
                    if (yf!=m) {
                        if (sol<=m-yf) cout<<j<<" "<<m-sol<<" "<<j<<" "<<m<<endl;
                        return 0;
                    }
                    break;
                }
                else {
                    int yi = (*i).first;
                    if (yi>yf) {
                        if (sol<=yi-yf) cout<<j<<" "<<yi-sol<<" "<<j<<" "<<yi<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    for (int j=1; j<m; j++) {
        if (v2.find(j)!=v1.end()) {
            set<pair<int,int> >::iterator i = v2[j].begin();
            if ((*i).first!=0) {
                cout<<0<<" "<<j<<" "<<(*i).first<<" "<<j<<endl;
                return 0;
            }
            while (true) {
                int yf = (*i).second;
                i++;
                if (i==v2[j].end()) {
                    if (yf!=n && sol!=0) {
                        if (sol<=n-yf) cout<<n-sol<<" "<<j<<" "<<n<<" "<<j<<endl;
                        return 0;
                    }
                    break;
                }
                else {
                    int yi = (*i).first;
                    if (yi>yf) {
                        if (sol<=yi-yf) cout<<yi-sol<<" "<<j<<" "<<yi<<" "<<j<<endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;

}

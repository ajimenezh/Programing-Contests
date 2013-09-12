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
int M,N;
map<int,int> mp[2];
int cnt;
vector<pair<int,int> > v[100010];
int t[100010];
int s[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    M = m; N = n;
    for (int i=0; i<k; i++) {
        int xi,yi,xf,yf;
        scanf("%d%d%d%d",&xi,&yi,&xf,&yf);
        if (xi==xf) {
            int c;
            if (mp[0].find(xi)==mp[0].end()) {
                c = cnt;
                mp[0][xi] = cnt++;
                n--;
            }
            else c = mp[0][xi];
            if (yi>yf) {int tmp = yi; yi = yf; yf = tmp;}
            v[c].push_back(make_pair(yi,yf));
            t[c] = xi+1;
        }
        if (yi==yf) {
            int c;
            if (mp[1].find(yi)==mp[1].end()) {
                c = cnt;
                mp[1][yi] = cnt++;
                m--;
            }
            else c = mp[1][yi];
            if (xi>xf) {int tmp = xi; xi = xf; xf = tmp;}
            v[c].push_back(make_pair(xi,xf));
            t[c] = -yf-1;
        }
    }
    for (int i=0; i<cnt; i++) sort(v[i].begin(),v[i].end());

    int res = 0;
    for (int c=0; c<cnt; c++) {
        int f = 0;
        int in = v[c][0].first;
        int fn = v[c][0].second;
        f += in;
        for (int j=1; j<v[c].size(); j++) {
            if (v[c][j].first>=in && v[c][j].second<=fn) continue;
            if (v[c][j].first<=fn && v[c][j].second>=fn) {
                fn = v[c][j].second;
            }
            else {
                in = v[c][j].first;
                f += (in-fn);
                fn = v[c][j].second;
            }
        }
        if (t[c]>0) f += (M-fn);
        else f += (N-fn);
        res ^= f;
        s[c] = f;
    }
    if ((n-1)%2!=0) res ^= M;
    if ((m-1)%2!=0) res ^= N;
    if (res==0) {
        cout<<"SECOND";
        return 0;
    }
    cout<<"FIRST\n";
    for (int c=0; c<cnt; c++) {
        int in = v[c][0].first;
        int fn = v[c][0].second;
        int f = 0;
        f += in;
        if ((s[c]-f)<=(res^s[c])) {
            if (t[c]<0) {
                cout<<0<<" "<<-t[c]-1<<" "<<f-(res^s[c])<<-t[c]-1<<endl;
            }
            else {
                cout<<t[c]-1<<" "<<0<<" "<<t[c]-1<<" "<<f-(res^s[c])<<endl;
            }
            return 0;
        }
        for (int j=1; j<v[c].size(); j++) {
            if (v[c][j].first>=in && v[c][j].second<=fn) continue;
            if (v[c][j].first<=fn && v[c][j].second>=fn) {
                fn = v[c][j].second;
            }
            else {
                in = v[c][j].first;
                int f2 = f;
                f += in - fn;
                if ((s[c]-f)<=(res^s[c])) {
                    if (t[c]<0) {
                        cout<<0<<" "<<-t[c]-1<<" "<<in-(f-(res^s[c])-f2)<<-t[c]-1<<endl;
                    }
                    else {
                        cout<<t[c]-1<<" "<<0<<" "<<t[c]-1<<" "<<in-(f-(res^s[c])-f2)<<endl;
                    }
                    return 0;
                }
                fn = v[c][j].second;
            }
        }
        if (f<=(res^s[c])) {
            if (t[c]<0) {
                cout<<0<<" "<<-t[c]-1<<" "<<fn+(s[c]-(res^s[c])-f)<<-t[c]-1<<endl;
            }
            else {
                cout<<t[c]-1<<" "<<0<<" "<<t[c]-1<<" "<<fn+(s[c]-(res^s[c])-f)<<endl;
            }
            return 0;
        }
    }
    if ((res^M)<=M) {
        for (int i=1; i<min(2*cnt+10,N); i++) {
            if (mp[0].find(i)==mp[0].end()) {
                cout<<i<<" "<<0<<" "<<i<<" "<<M-(res^M)<<endl;
                return 0;
            }
        }
    }

    if ((res^N)<=N) {
        for (int i=1; i<min(2*cnt+10,M); i++) {
            if (mp[1].find(i)==mp[1].end()) {
                cout<<0<<" "<<i<<" "<<N-(res^N)<<" "<<i<<endl;
                return 0;
            }
        }
    }

    return 0;

}

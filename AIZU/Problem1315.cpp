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

int n;
vector<int> t[1010];
vector<int> vis;
int sum[1010];
int v[1445];
void update(int x) {
    for(;x<=1441; x+=x&-x) v[x]++;
}
int get(int x) {
    int s = 0;
    for (;x>=1; x-=x&-x) s+=v[x];
    return s;
}

int parse(string s) {
    string h = s.substr(0,2);
    string m = s.substr(3,2);
    return atoi(h.c_str())*60 + atoi(m.c_str());
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        string s, last;
        cin>>last;
        s = last;
        for (int i=0; i<1000; i++) sum[i] = 0;
        for (int i=0; i<=n; i++) {
            if (i!=0 && i!=n) cin>>s;
            if (last!=s || i==0 || i==n) {

                if (i!=0) {
                    for (int j=0; j<t[0].size(); j+=2) {
                        for (int k=t[0][j]; k<t[0][j+1]; k++) update(k);
                    }
                    for (int j=1; j<1000; j++) {
                        for (int k=0; k<t[j].size(); k+=2) sum[j] += get(t[j][k+1]-1) - get(t[j][k]-1);
                    }
                }

                for (int j=0; j<1445; j++) v[j] = 0;
                for (int j=0; j<vis.size(); j++) t[vis[j]].clear();
                vis.clear();

                if (i==n) break;

                last = s;

            }
            string hour;
            cin>>hour;
            int tmp = parse(hour);
            cin>>hour;
            string id;
            cin>>id;
            vis.push_back(atoi(id.c_str()));
            t[atoi(id.c_str())].push_back(tmp);
        }

        int m = 0;
        for (int i=1; i<1000; i++) m = max(m, sum[i]);
        printf("%d\n",m);
    }

    return 0;

}

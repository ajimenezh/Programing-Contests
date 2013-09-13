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

int dist[1<<17];
int q[100000];
int in,fn;
string pattern[3];

void change(int &mask, int i, int j, int k) {
    if (i<0 || i>=16) return;
    if (pattern[j][k]=='1') {
        if (mask&(1<<i)) {
            mask -= 1<<i;
        }
        else mask += 1<<i;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int p = 0;
    for (int i=0; i<4; i++) {
        string s;
        cin>>s;
        for (int j=0; j<4; j++) {
            if (s[j]=='W') p += 1<<(i*4+j);
        }
    }

    for (int i=0; i<(1<<16); i++) dist[i] = -1;
    q[fn++] = p;
    dist[p] = 0;

    for (int i=0; i<3; i++) cin>>pattern[i];

    while (in<fn) {
        int cur = q[in++];
        if (cur==0 || cur==(1<<16)-1) break;

        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                int to = cur;
                for (int ii=-1; ii<=1; ii++) {
                    for (int jj=-1; jj<=1; jj++) {
                        int id = (i+ii)*4;
                        if (id<0 || id>15) id += 100;
                        if (jj+j>=0 && j+jj<=3) id += j+jj;
                        else if (j+jj<0) id = 100;
                        else if (j+jj>3) id = 100;
                        change(to,id, ii+1, jj+1);
                    }
                }
                if (dist[to]==-1) {
                    dist[to] = dist[cur] + 1;
                    q[fn++] = to;
                }
            }
        }
    }

    if (dist[0]==-1&&dist[(1<<16)-1]==-1) cout<<"Impossible";
    else {
        if (dist[0]==-1) dist[0] = 100000;
        if (dist[(1<<16)-1]==-1) dist[(1<<16)-1] = 100000;
        cout<<min(dist[0], dist[(1<<16)-1])<<endl;
    }

    return 0;

}

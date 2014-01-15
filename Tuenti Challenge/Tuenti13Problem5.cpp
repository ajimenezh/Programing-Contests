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
int x,y;
int z;
int c[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int rec(int a, int b, int r, int pre) {
    if (r==0) return c[a][b];

    int d = c[a][b];
    int tmp = 0;
    c[a][b] = 0;

    for (int i=0; i<4; i++) if (i!=pre) {
        if (a+dx[i]>=n || a+dx[i]<0) continue;
        if (b+dy[i]>=m || b+dy[i]<0) continue;

        tmp = max(tmp,rec(a+dx[i],b+dy[i],r-1,(i+2)%4)+d);
    }

    c[a][b] = d;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%d,%d",&n,&m);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) c[i][j] = 0;
        scanf("%d,%d",&x,&y);
        scanf("%d",&z);
        int g;
        scanf("%d",&g);
        string s;
        cin>>s;
        for (int i=0; i<s.length(); i++) if (s[i]=='#') s[i] = ' ';
        stringstream ss(s);
        while (ss>>s) {
            for (int i=0; i<s.length(); i++) if (s[i]==',') s[i]=' ';
            stringstream ss2(s);
            int x1,y1,c1;
            ss2>>x1>>y1>>c1;
            c[x1][y1] = c1;
        }
        //for (int i=0; i<n; i++) {for (int j=0; j<m; j++) cout<<c[i][j]<<" "; cout<<endl;}
        int res = rec(x,y,z,-1);
        printf("%d\n",res);
    }

    return 0;

}

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

bool c[201][201];
bool vis[201][201];
int w,h;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>w>>h>>n;
    for (int i=0; i<2*w; i++) c[i][0] = 1;
    for (int i=0; i<2*h; i++) c[0][i] = 1;
    for (int i=0; i<n; i++) {
        int x,xc,y,yc;
        cin>>x>>y>>xc>>yc;
        if (y==yc && y!=0 && yc!=h) {
            y = 2*y;
            x = 2*x;
            xc = 2*xc;
            for (int j=x; j<xc; j++) c[j][y] = 1;
        }
        if (x==xc && x!=0 && xc!=w) {
            x = 2*x;
            y = 2*y;
            yc = 2*yc;
            for (int j=y; j<yc; j++) c[x][j] = 1;
        }
    }
    //for (int i=0; i<2*h; i++) {for (int j=0; j<2*w; j++) cout<<c[j][i]; cout<<endl;}
    vector<int> ar;
    for (int i=1; i<2*w; i+=2) for (int j=1; j<2*h; j+=2) {
        if (!vis[i][j] && c[i][j]==0) {
            int a = 0;
            for (int r=i; r<2*w ; r+=2) {
                for (int p=j; p<2*h && c[r][p]==0; p+=2) {
                    a++;
                    vis[r][p] = 1;
                    c[r][p] = 1;
                    if (c[r][p+1]==1) break;
                }
                if (c[r+1][j]==1) break;
            }
            //cout<<a<<endl;
            ar.push_back(a);

            //cout<<endl;
            //for (int i=0; i<2*h; i++) {for (int j=0; j<2*w; j++) cout<<c[j][i]; cout<<endl;}
        }
    }
    sort(ar.begin(),ar.end());
    for (int i=0; i<ar.size(); i++) cout<<ar[i]<<" "; cout<<endl;

    return 0;

}

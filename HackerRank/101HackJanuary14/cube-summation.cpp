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

int n,m;

long long a[102][102][102];
long long last[102][102][102];
char buf[20];

long long get(int xx, int yy, int zz) {
    long long tot = 0;
    for (int x=xx;x>=1;x-=x&-x) {
        for(int y=yy;y>=1;y-=y&-y) {
            for (int z=zz;z>=1;z-=z&-z) {
                tot += a[x][y][z];
            }
        }
    }
    return tot;
}

void update(int xx, int yy, int zz, int k) {
    for (int x=xx;x<=n;x+=x&-x) {
        for(int y=yy;y<=n;y+=y&-y) {
            for (int z=zz;z<=n;z+=z&-z) {
                a[x][y][z] += k;
            }
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; k<n; k++) {
                    a[i+1][j+1][k+1] = 0;
                    last[i+1][j+1][k+1] = 0;
                }
            }
        }
        for (int i=0; i<m; i++) {
            scanf("%s",buf);
            if (buf[0]=='U') {
                int x,y,z,k;
                scanf("%d%d%d%d",&x,&y,&z,&k);
                update(x,y,z,-last[x][y][z]);
                last[x][y][z] = k;
                update(x,y,z,k);
            }
            else {
                int x1,x2,y1,y2,z1,z2;
                scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                long long sum = 0;
                sum = get(x2,y2,z2);
                sum -= get(x2,y2,z1-1);
                sum -= get(x2,y1-1,z2);
                sum -= get(x1-1,y2,z2);
                sum += get(x2,y1-1,z1-1);
                sum += get(x1-1,y1-1,z2);
                sum += get(x1-1,y2,z1-1);
                sum -= get(x1-1,y1-1,z1-1);

                cout<<sum<<"\n";
            }
        }
    }

    return 0;

}

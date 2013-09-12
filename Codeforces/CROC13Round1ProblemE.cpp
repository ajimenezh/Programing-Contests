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

int n,m;
int a[100010];
int b[100010];
int t[318];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) scanf("%d",b+i);
    for (int i=0; i<317; i++) t[i] = -1;

    int s = sqrt(n);
    //cout<<s<<endl;

    for (int i=0; i<m; i++) {
        int c;
        scanf("%d",&c);
        if (c==2) {
            int ind;
            scanf("%d",&ind);
            ind--;
            if (t[ind/s]==-1) {
                printf("%d\n",b[ind]);
            }
            else {
                printf("%d\n",a[t[ind/s]+ind-(ind/s)*s]);
            }
        }
        else {
            int x,y,k;
            scanf("%d%d%d",&x,&y,&k);
            x--; y--;
            int f = 0;
            for (int j=0; j<=k/s; j++) {
                if (j==0) {
                    for (int p=(y/s)*s; p<y; p++) {
                        b[p] = a[t[p/s]+p-(p/s)*s];
                    }
                    for (int p=y; p<min((y/s+1)*s,y+k); p++) {
                        b[p] = a[x+p-y];
                        f++;
                    }
                    t[y/s] = -1;
                }
                else if (j==k/s) {
                    //cout<<((y+k)/s)*s<<" "<<y+k<<endl;
                    for (int p=((y+k)/s)*s; p<y+k; p++) {
                        b[p] = a[x+p-y];
                    }
                    for (int p=(y+k); p<min(((y+k-1)/s+1)*s,n); p++) {
                        b[p] = a[t[p/s]+p-(p/s)*s];
                    }
                    t[(y+k-1)/s] = -1;
                }
                else {
                    t[(y+f)/s] = x+f;
                    f += s;
                }
            }
        }
        //for (int j=0; j<n; j++) cout<<b[j]<<" "; cout<<endl;
        //for (int j=0; j<s; j++) cout<<t[j]<<" "; cout<<endl;
    }

    return 0;

}

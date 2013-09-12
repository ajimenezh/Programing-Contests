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

int n;
int x[101], y[101];
int x1[101],yI[101],x2[101],y2[101];
int f(int x) {return x*x*x;}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        x[i] = (a+c);
        y[i] = (b+d);
        x1[i] = min(a,c); x2[i] = max(a,c);
        yI[i] = min(b,d); y2[i] = max(d,b);
    }

    int r = 1;
    for (int i=0; i<n; i++) {
        if (i==0) continue;
        int cx = 0, cy = 0;
        bool done = false;
        int k = 0;
        for (int j=i; j>0; j--) {
            if (j==i) {
                cx = x[i]*f(x2[j]-x1[j]);
                cy = y[i]*f(x2[j]-x1[j]);
                k += f(x2[j]-x1[j]);
                //cout<<cx<<" "<<cy<<endl;

                if (cx>2*k*x2[i-1] || cx<2*k*x1[i-1]) {
                    done = true;
                    break;
                }
                if (cy>2*k*y2[i-1] || cy<2*k*yI[i-1]) {
                    done = true;
                    //cout<<"hola";
                    break;
                }
            }
            else {
                cx = (cx + x[j]*f(x2[j]-x1[j]));
                cy = (cy + y[j]*f(x2[j]-x1[j]));
                k += f(x2[j]-x1[j]);

                if (cx>k*2*x2[j-1] || cx<k*2*x1[j-1]) {
                    done = true;
                    //cout<<cx<<" "<<cy<<" "<<k<<endl;
                    //cout<<x2[j-1]<<" "<<x1[j-1]<<endl;
                    break;
                }
                if (cy>k*2*y2[j-1] || cy<k*2*yI[j-1]) {
                    done = true;
                    //cout<<cx<<" "<<cy<<" "<<k<<endl;
                    //cout<<y2[j-1]<<" "<<yI[j-1]<<endl;
                    break;
                }
            }
        }
        if (done) break;
        r++;
    }

    cout<<r<<endl;

    return 0;

}

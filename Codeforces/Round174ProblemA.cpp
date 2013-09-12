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
long long a[200010];
long long b[200010];
long long t;
int j;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    j = 0;
    t = 0LL;
    for (int i=0; i<n; i++) {
        int s;
        scanf("%d",&s);
        if (s==1) {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            a[x] = a[x] + (long long)y*(long long)(x + 1);
            t += (long long)y*(long long)(x + 1);
        }
        else if (s==2) {
            int x;
            scanf("%d",&x);
            b[++j] = x;
            t += x;
        }
        else {
            t -= b[j];
            t -= a[j] / (j + 1);
            b[j] = 0;
            a[j-1] += a[j] - a[j] / (j + 1);
            j--;
        }
        //cout<<t<<" "<<j<<endl;
        double d = 1.0*t / (1.0*j + 1.0);
        printf("%.12llf\n",d);
    }

    return 0;

}

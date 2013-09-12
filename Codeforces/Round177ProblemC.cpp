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
int p[1000010];
int vis[1000010];
long long res;
long long neg[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int k = 0;
    int c = n;
    while (c>0) {k++; c>>=1LL;}

    for (int i=0; i<=n; i++) {
        int a = 0;
        for (int j=k;j>=0; j--) {
            if (i&(1<<j)) ;
            else {
                a |= 1<<j;
            }
        }
        neg[i] = a;
    }
    for (int i=n; i>=0; i--) {
        if (neg[i]<=n && !vis[~i]) {
            p[i] = neg[i];
            res += neg[i]^i;
            vis[neg[i]] = 1;
        }
        else {
            long long a = neg[i];
            for (int j=k; j>=0; j--) {
                if ((a & (1LL<<j))) {
                    //cout<<a<<" "<<(a ^ (1<<j))<<" "<<j<<endl;
                    a = a ^ (1LL<<j);
                }
                else {
                    a = a | (1LL<<j);
                }
                if ((a)<=n && !vis[a]) {
                    //cout<<a<<endl;
                    p[i] = (a);
                    res += (a)^i;
                    vis[a] = 1;
                    break;
                }
            }
//            if (!vis[neg[i]]) {
//                a = i;
//                for (int j=0; j<=k; j++) {
//                    if ((a & (1<<j))) {
//                        //cout<<a<<" "<<(a ^ (1<<j))<<" "<<j<<endl;
//                        a = a | (1<<j);
//                    }
//                    if ((a)<=n && !vis[a]) {
//                        p[i] = (a);
//                        res += (a)^i;
//                        vis[a] = 1;
//                        break;
//                    }
//                }
//            }
        }
    }

    cout<<res<<endl;
    for (int i=0; i<=n; i++) printf("%d ",p[i]);

    return 0;

}

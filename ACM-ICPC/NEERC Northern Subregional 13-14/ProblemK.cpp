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


int main() {

    freopen("kids.in","r",stdin);
    freopen("kids.out","w",stdout);

    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int boys = 1000000;
    int girls = 1000000;

    for (int i=a+1; i<=4*55*55; i++) {
        for (int j=d+1; j<=4*55*55; j++) {
            if (i*b==j*c) {
                if ((i*a)%2==0 && (j*d)%2==0) {
                    if (i>=c && j>=b) {
                        if (boys+girls>j+i) {
                            boys = j;
                            girls = i;
                        }
                    }
                }
            }
        }
    }

    printf("%d %d\n",girls,boys);
    for (int i=1; i<=girls; i++) {
        for (int j=i+1; j<=i+a/2; j++) {
            int t = (j-1)%girls+1;
            printf("%d %d\n",i,t);
        }
    }
    if (a%2==1) {
        for (int i=1; i<=girls/2; i++) {
            printf("%d %d\n",i,i+girls/2);
        }
    }
    for (int i=1; i<=boys; i++) {
        for (int j=i+1; j<=i+d/2; j++) {
            int t = (j-1)%boys+1;
            printf("%d %d\n",i+girls,t+girls);
        }
    }
    if (a%2==1) {
        for (int i=1; i<=boys/2; i++) {
            printf("%d %d\n",i+girls,i+boys/2+girls);
        }
    }
    int k = 0;
    for (int i=1; i<=girls; i++) {
        for (int j=1; j<=b; j++) {
            k++;
            if (k>boys) k = 1;
            printf("%d %d\n",i,girls+k);
        }
    }

    return 0;

}

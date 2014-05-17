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



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n, p;
        cin>>n>>p;

        for (int i=0; i<n-1; i++) printf("%d %d\n", i+1, (i+1)%n+1);
        for (int i=0; i<n-1; i++) printf("%d %d\n", i+1, (i+2)%n+1);
        printf("%d %d\n", n, 1);
        printf("%d %d\n", n, 2);

        int k = 3;
        while (p>0) {
            for (int i=0; i<n; i++) {
                if (p==0) break;
                printf("%d %d\n", i+1, (i+k)%n+1);
                p--;
            }
            k++;
        }
    }

    return 0;

}

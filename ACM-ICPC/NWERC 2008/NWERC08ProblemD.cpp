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
int a,b;
int x[10010];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=2; i<10002; i++) {
        for (int j=2; j<10001; j++) {
            if ((i*822 + j)%10001 == 1918 && (i*17 + j)%10001 == 9727) {
                a = i;
                b = j;
            }
        }
    }

    cin>>t;

    while (t--) {
        cin>>n;

        cout<<(a*n+b)%10001<<endl;
    }


    return 0;

}

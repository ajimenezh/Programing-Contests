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
vector<int> v;
int c[100010][19];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    v = vector<int> (n,0);
    for (int i=0; i<n; i++) scanf("%d",&v[i]);


    int last = n;
    int k = 0;
    for (int i=0; i<n; i++) c[i][k] = v[i];
    while (true) {
        int cnt = 0;
        bool done = 0;
        c[cnt++][k+1] = c[0][k];
        for (int i=1; i<last; i++) {
            if (c[i][k]>=c[i-1][k]) {
                c[cnt++][k+1] = c[i][k];
            }
        }
        for (int j=0; j<cnt; j++) cout<<c[j][k+1]<<" "; cout<<endl;
        if (cnt==last) break;
        last = cnt;
        k++;
    }

    cout<<k<<endl;

    return 0;

}

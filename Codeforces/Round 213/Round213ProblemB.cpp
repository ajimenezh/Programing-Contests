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

int n,d;
int c[55];
bool vis[600000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>d;
    for (int i=0; i<n; i++) cin>>c[i];
    sort(c,c+n);

    int last = 0;

    int sum = 0;
    for (int i=0; i<n; i++) {
        if (sum+d>=c[i]) {
            sum += c[i];
            last = i;
        }
    }
    vis[0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=sum; j>=c[i]; j--) {
            vis[j] |= vis[j-c[i]];
        }
    }

    cout<<sum<<" ";

    int result = 0;

    int cnt = 0;
    for (cnt=0;;cnt++) {
        int j;
        for (j=d; j>=0; j--) {
            if (vis[result+j]) {
                result += j;
                break;
            }
        }
        if (!j) break;
    }

    cout<<cnt<<endl;

    return 0;

}

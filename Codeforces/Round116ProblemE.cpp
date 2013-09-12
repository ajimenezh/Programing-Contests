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

int n,m,k;
int c[100010];
int a[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<=m; i++) c[i] = 0;

    int last = 0;
    int now = a[0];
    int tot = 0;
    int best = 0;
    for (int i=0; i<n; i++) {
        tot++;
        c[a[i]]++;
        if (tot-c[now]>k) {
            for (int j=last; j<=i; j++) {
                if (tot-c[a[j]]<=k) {
                    now = a[j];
                    last = j;
                    break;
                }
                tot--;
                c[a[j]]--;
            }
        }
        best = max(best,c[now]);
        //cout<<i<<" "<<last<<" "<<best<<" "<<now<<" "<<c[now]<<endl;
    }

    cout<<best<<endl;

    return 0;

}
